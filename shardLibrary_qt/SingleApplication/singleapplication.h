#ifndef SINGLEAPPLICATION_H
#define SINGLEAPPLICATION_H


#include "singleapplication_global.h"
#include <QObject>
#include <QApplication>
#include <QtNetwork/QLocalServer>
#include <QWidget>
#include <QTranslator>
#include <QHash>
#include <QStringList>

class QDir;
class QTranslator;

typedef QHash<QString, QTranslator*> Translators;

class SINGLEAPPLICATIONSHARED_EXPORT SingleApplication :public QApplication
{
  Q_OBJECT
public:
    SingleApplication(int &argc, char **argv);
    bool isRunning();                // 是否已經有实例在运行
    QWidget *w;                        // MainWindow指针
    static void loadTranslations(const QString& dir);
    static const QStringList availableLanguagesRes();
    static const QStringList availableLanguagesDir();
public slots:
    static void setLanguage(const QString& locale, QString source);
private slots:
    // 有新连接时触发
    void _newLocalConnection();
private:
    // 初始化本地连接
    void _initLocalConnection();         // 创建服务端
    void _newLocalServer();         // 激活窗口
    void _activateWindow();
    bool _isRunning;                // 是否已經有实例在运行
    QLocalServer *_localServer;     // 本地socket Server
    QString _serverName;            // 服务名称
    static QTranslator* current;
    static Translators translatorsRes, translatorsDir;

};

#endif // SINGLEAPPLICATION_H
