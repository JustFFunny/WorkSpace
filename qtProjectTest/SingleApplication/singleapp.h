#ifndef SINGLEAPP_H
#define SINGLEAPP_H
//单实例运行
#include <QApplication>

#include <QLocalServer>
#include <QLocalSocket>
#include <QWidget>
#include <QString>

class SingleApp : public QApplication
{
    Q_OBJECT
public:
//    explicit SingleApp(QObject *parent = 0);
    SingleApp(int argc, char *argv[] );
    QWidget * w;//mainWindows指针
    bool isRuning();
    void initLocalConnect();//初始化本地连接
    void newLocalServer();//创建服务端
    void activeWindow();// 激活窗口
signals:
    
public slots:
    void newLocalConnection();//有新连接时的槽函数
private:
    QString m_serverName;//服务名称
    QLocalServer * m_localServer;//本地socketServer
    bool m_isruning;//实例是否正在执行
    
};

#endif // SINGLEAPP_H
