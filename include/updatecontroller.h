#ifndef UPDATECONTROLLER_H
#define UPDATECONTROLLER_H

class HttpManager;

#include <QIODevice>
#include <QObject>

//#ifndef LIB_SHARED
//#define LIB_EXPORT
//#else
//#ifdef _WIN32
//#ifdef LIB_BUILD_SHARED
//#define LIB_EXPORT __declspec(dllexport)
//#else
//#define LIB_EXPORT __declspec(dllimport)
//#endif
//#else
//#define LIB_EXPORT __attribute__((visibility("default")))
//#endif
//#endif

class /*LIB_EXPORT*/ UpdateController : public QObject
{
    Q_OBJECT
public:
    UpdateController();
    ~UpdateController();
    void isNewVersionAvailable();
    void downloadFile(QString fileName, const QString& urlSpec, const QString& downloadFileName);
    void setParameters(const QString& apiUrl, const QString& appName, const QString& downloadFileName);
private:
    bool isParametersSet = false;
	std::unique_ptr<HttpManager> httpManager;
	QString osName, apiUrl, appName, downloadFileName;

    bool compareTagVersion(const QString& tag, const QString& currentTag);
	QString readFile(const QString& fileName, QIODevice::OpenModeFlag flag=QIODevice::ReadOnly);
};

#endif // UPDATECONTROLLER_H
