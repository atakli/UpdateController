#ifndef UPDATECONTROLLER_H
#define UPDATECONTROLLER_H

class HttpManager;

#include <QIODevice>
#include <QObject>

class UpdateController : public QObject
{
    Q_OBJECT
public:
    UpdateController();
    ~UpdateController();
    void isNewVersionAvailable(bool tellIsUptodate = false);
    void downloadFile(const QString& fileName, const QString& urlSpec);
    void setParameters(const QString& apiUrl, const QString& appName, const QString& downloadFileName, const QString& versionFileFullPath = "");
private:
    bool isParametersSet = false;
	std::unique_ptr<HttpManager> httpManager;
    QString osName, apiUrl, appName, downloadFileName, versionFileFullPath;

    bool compareTagVersion(const QString& tag, const QString& currentTag);
	QString readFile(const QString& fileName, QIODevice::OpenModeFlag flag=QIODevice::ReadOnly);
};

#endif // UPDATECONTROLLER_H
