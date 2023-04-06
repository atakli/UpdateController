#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDialog>

QT_BEGIN_NAMESPACE
class QUrl;
class QFile;
class QSslError;
QT_END_NAMESPACE

class HttpManager : public QDialog
{
    Q_OBJECT
public:
    explicit HttpManager(QWidget *parent = nullptr);
	~HttpManager();
	void downloadFile(const QString fileName, const QString urlSpec);
    void downloadSynchronous(QString fileName, const QString& urlSpec, const QString& downloadFileName);
    bool hasError = false;
private slots:
	void httpFinished();
	void httpReadyRead();
	void connectionError(QNetworkReply::NetworkError error);
#if QT_CONFIG(ssl)
	void sslErrors(const QList<QSslError> &errors);
#endif

private:
	std::unique_ptr<QFile> openFileForWrite(const QString &fileName, QIODevice::OpenModeFlag flag = QIODevice::WriteOnly);
	void startRequest(const QUrl &requestedUrl);

	QNetworkAccessManager qnam;
	std::unique_ptr<QNetworkReply> reply;
	std::unique_ptr<QFile> file;
};

#endif
