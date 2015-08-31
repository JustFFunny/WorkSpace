/*1. IOS时间的验证.
 *2.Linux用户统计:
 *    统计的信息有 系统的版本,IP地址      运行的次数.运行的时间.每个模块运行时间.\
 *    可能需要的  异常退出的次数或者待机退出
 *
 *运行次数:可以在配置文件中,进行记录;如果重新生成配置文件为0;
 **/
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

#include <QSysInfo>
#include <QHostAddress>
#include <QHostInfo>
#include <QProcess>
#include <QTime>

#include <unistd.h>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //    QString localHostName=QHostInfo::localHostName();
    //    //"wuqiankun-OptiPlex-360"    (QHostAddress("127.0.1.1") )
    //    //qDebug()<<localHostName<< "  "<<QHostInfo::fromName(localHostName).addresses();
    //    QHostInfo info=QHostInfo::fromName(localHostName);

    //    foreach(QHostAddress address,info.addresses())
    //    {
    //        //  if(address.protocol() == QAbstractSocket::IPv4Protocol)
    //        qDebug() << address.toString();
    //    }

    //获得内核版本
    QProcess * _process=new QProcess;
    QString _cmd("uname -r");
    _process->setProcessChannelMode(QProcess::MergedChannels);
    _process->start(_cmd);
    _process->waitForFinished(-1);
    QString result=_process->readAll();
    qDebug()<<"Linux kernel:"<<result;
    delete _process;

    //获取时间
    qDebug()<<"currentTime:"<<QTime::currentTime().toString("hh:mm:ss");

    QTime _time;
    _time.start();//开始计时
    sleep(5);
    qDebug()<< _time.restart();
    sleep(5);
    qDebug()<< _time.elapsed();//毫秒  1s=1000ms

    QString _numStr("1");
    qDebug()<<_numStr.toInt()+1;

    //条件编译,不同的环境(Windows/Linux/Mac)编译不同的部分.   在编译时候起作用.
#ifdef Q_OS_WIN
    // Windows上的代码
#endif

#ifdef Q_OS_LINUX
    // Linux上的代码
#endif

#ifdef Q_OS_MAC
    // Mac上的代码
#endif


    QString  timestamp("1434544621");
    qDebug()<<timestamp.toLongLong();
    qint64 time(1434544621);
    qDebug()<< QDateTime::fromMSecsSinceEpoch(time*100).toString("hh:mm dd.MM.yyyy");




    return a.exec();
}
