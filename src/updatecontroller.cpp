#include "updatecontroller.h"
#include "httpmanager.h"

#include <QJsonDocument>
#include <QMessageBox>
#include <fstream>
#include <QFile>

UpdateController::UpdateController() : httpManager(std::make_unique<HttpManager>())	{}
UpdateController::~UpdateController() = default;

void UpdateController::setParameters(const QString &apiUrl, const QString &appName, const QString &downloadFileName, const QString& versionFileFullPath)
{
    this->apiUrl = apiUrl;
    this->appName = appName;
    this->downloadFileName = downloadFileName;
    this->versionFileFullPath = versionFileFullPath;
    isParametersSet = true;
}

void UpdateController::downloadFile(const QString& fileName, const QString& urlSpec)
{
    httpManager->downloadSynchronous(fileName, urlSpec);
}

QString UpdateController::readFile(const QString& fileName, QIODevice::OpenModeFlag flag)
{
	QFile file(fileName);
    if (!file.open(flag | QIODevice::Text))
    {
        QMessageBox::warning(nullptr, tr(appName.toStdString().c_str()), fileName + " açılamadı. Dosyayı kontrol edin. Güncelleme aracından çıkılıyor...");
        return "";
    }
    return file.readAll();
}
bool UpdateController::compareTagVersion(const QString& tagAtGithub, const QString& currentTag) // TODO: .'lar arasında birden fazla basamak olursa da çalışmalı
{
    osName = currentTag.contains("-") ? currentTag.split("-").last().trimmed() : "";
    auto parse = [](const QString& str){return str.mid(1).split("-").at(0).split(".");};
    auto makeIntVector = [parse](const QString& str)
    {
        std::vector<int> ivec;
        for (const auto& s : parse(str))
            ivec.emplace_back(s.toInt());
        return ivec;
    };

    return makeIntVector(tagAtGithub) > makeIntVector(currentTag);
}

void UpdateController::isNewVersionAvailable(bool tellIsUptodate)
{
    const QString apiPath = std::tmpnam(nullptr);
    const QString versionFileName = versionFileFullPath.isEmpty() ? "version.txt" : versionFileFullPath;
    if (!isParametersSet)
    {
		QMessageBox::warning(nullptr, tr(appName.toStdString().c_str()), "Güncelleme Kontrolcüsüne parametreler geçilmemiş\nGüncelleme olup olmadığını kontrol edebilmek için gerekli parametreleri geçip tekrar deneyin");
        return;
    }
    httpManager->downloadSynchronous(apiPath, apiUrl);
	if (httpManager->hasError)
		return;
    const QString saveData = readFile(apiPath);
    if (saveData.isEmpty()) return;
//	QJsonDocument loadDoc = QJsonDocument::fromVariant(saveData);
    const QJsonDocument loadDoc = QJsonDocument::fromJson(QByteArray::fromStdString(saveData.toStdString()));

	const QString currentTag = readFile(versionFileName);
    if (currentTag.isEmpty()) return;
    if(compareTagVersion(loadDoc["tag_name"].toString(), currentTag))               // TODO: version.txt'deki ile api.json'daki aynı olmasina ragmen yeni surum bulundu diyo
    {
        if (QMessageBox(QMessageBox::Question, appName, "Yeni sürüm bulundu\nİndirilelim mi?", QMessageBox::No | QMessageBox::Yes).exec() == QMessageBox::No)
		{
			return;
		}
//            https://github.com/atakli/EtkinlikKayit/releases/latest/download/EtkinlikKayit.zip
        QString url = loadDoc["assets"][0]["browser_download_url"].toString();
        qDebug() << "download url:" << url;
        if (!osName.isEmpty())
        {
            if (!url.endsWith(osName + ".zip", Qt::CaseInsensitive))
                url = loadDoc["assets"][1]["browser_download_url"].toString();
        }
        httpManager->downloadSynchronous(downloadFileName, url, true); // ismi PrayerReminder.zip'dan başka bişey olursa diye // TODO: 0'da sıkıntı olabilir
//        QString url = "https://github.com/atakli/PrayerReminder-Desktop/releases/latest/download/PrayerReminder-" + osName + ".zip";
    }
    else if (tellIsUptodate)
    {
        QMessageBox::information(nullptr, tr(appName.toStdString().c_str()), "Program güncel");
    }
}
