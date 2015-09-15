#include "singleapp.h"
#include <QDebug>
#include <QFileInfo>
//SingleApp::SingleApp(QObject *parent) :
//    QApplication(parent)
//{
//}
#define TimeOut 5000;
SingleApp::SingleApp(int argc, char **argv ):
    QApplication( argc, argv),
    m_isruning(false),
    m_localServer(NULL),
    w(NULL)
{
    m_serverName=QApplication::applicationName();
    m_serverName=QFileInfo(QApplication::applicationFilePath()).fileName() ;
    // m_serverName="1";
    qDebug()<<m_serverName;
    initLocalConnect();
}

bool SingleApp::isRuning()
{
    return m_isruning;
}

void  SingleApp::initLocalConnect()
{
    //每次执行都会创建新的，可能会造成内存泄露，2.只是取的返回值
    //    QLocalSocket *localSocket=new QLocalSocket;
    //    localSocket->connectToServer(m_serverName);

    //    if(localSocket->waitForConnected() )
    QLocalSocket localSocket;
    localSocket.connectToServer(m_serverName);
    if(localSocket.waitForConnected())
    {
        /* 已经建立连接 程序已经在运行*/
        qDebug()<<m_serverName<<"is already runing!!!";
        m_isruning=true;
        //其他处理，启动参数的处理
        return;
    }
    else
    {
        //没有建立连接  ，创建服务则建立连接
        newLocalServer();
    }
}



/*创建服务端
 *
QAbstractSocket::AddressInUseError
The address specified to QUdpSocket::bind()
is already in use and was set to be exclusive.

bool QLocalServer::removeServer ( const QString & name ) [static]
Removes any server instance that might cause a call to listen() to fail and returns true if successful;
otherwise returns false. This function is meant to recover from a crash,
when the previous server instance has not been cleaned up.
On Windows, this function does nothing; on Unix, it removes the socket file given by name.
Warning: Be careful to avoid removing sockets of running instances.


bool QLocalServer::listen ( const QString & name )
Tells the server to listen for incoming connections on name.
If the server is currently listening then it will return false.
Return true on success otherwise false.
name can be a single name and QLocalServer will determine the correct platform specific path.
serverName() will return the name that is passed into listen.
Usually you would just pass in a name like "foo",
but on Unix this could also be a path
such as "/tmp/foo" and on Windows this could be a pipe path such as "\\.\pipe\foo"
Note: On Unix if the server crasheswithout closing listen will fail with AddressInUseError.
To create a new server the file should be removed.
On Windows two local servers can listen to the same pipe at the same time,
but any connections will go to one of the server.

 **/
void SingleApp::newLocalServer()
{
    m_localServer=new QLocalServer;
    connect(m_localServer,SIGNAL(newConnection()),this,SLOT(newLocalConnection()));
    if(!m_localServer->listen(m_serverName))
    {
        //此时监听失败，可能是程序崩溃时，残留进程服务导致的，移除
        if(m_localServer->serverError()==QAbstractSocket::AddressInUseError)
        {
            QLocalServer::removeServer(m_serverName);
            // QLocalServer::removeServer(m_localServer->serverName());//不能实现单一实例化
            m_localServer->listen(m_serverName);
        }
    }
}



/*激活窗口
 **/
void SingleApp::activeWindow()
{
    if(w)
    {
        w->show();
        w->raise();
        w->activateWindow();
    }
}

/*有新连接时的槽函数
 **/
void SingleApp::newLocalConnection()
{
    QLocalSocket *socket=m_localServer->nextPendingConnection();
    if(socket)
    {
        socket->waitForReadyRead();
        delete socket;
        //其他处理，读取启动参数

        activeWindow();
    }
}
