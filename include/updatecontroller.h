#ifndef UPDATECONTROLLER_H
#define UPDATECONTROLLER_H

class HttpManager;

#include <QIODevice>
#include <QWidget>
#include <QObject>
#include <QDialog>

class UpdateController : public QObject
{
    Q_OBJECT
public:
	UpdateController();
	~UpdateController();
    void isNewVersionAvailable();
    void downloadFile(QString fileName, QString urlSpec, const QString& downloadFileName);
	void setParameters(const QString& apiUrl, const QString& appName, const QString& downloadFileName);
private:
    bool isParametersSet = false;
	std::unique_ptr<HttpManager> httpManager;
	QString osName, apiUrl, appName, downloadFileName;

    bool compareTagVersion(const QString& tag, const QString& currentTag);
	QString readFile(const QString& fileName, QIODevice::OpenModeFlag flag=QIODevice::ReadOnly);
};

#endif // UPDATECONTROLLER_H
