#include "conthread.h"
#include <QStringList>
#include <QProcess>
#include <QSettings>

ConThread::ConThread()
{

}

void ConThread::run()
{
    QSettings settings;
    QString type = settings.value("connectType").toString();
    QString sdk = settings.value("sdkPath").toString();
    QString ip = settings.value("wlanIP").toString();
    qint16 port = settings.value("cPort").toInt();

    if(type == "usb")
    {
        QProcess proces;
        proces.setProcessChannelMode(QProcess::MergedChannels);
        proces.start( sdk + "adb forward tcp:6101 tcp:7101");
        proces.waitForFinished(-1);
        QString tmp = proces.readAll();
        if (tmp.contains("error: device not found"))
        {
            emit this->connectionChanged(0,"");
            return;
        }
    }

    this->socket = new QTcpSocket();
    this->socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (this->socket->waitForConnected(2000))
    {
        this->socket->write("DEVICES\n");
        this->socket->waitForReadyRead(2000);
        QString data = QString::fromUtf8(this->socket->readLine());
        if (data.contains("OKAY"))
        {
            QString  serialNumber = data.split(":")[1];
            emit this->connectionChanged(1,serialNumber);
        }
        else
        {
            emit this->connectionChanged(0,"");
            return;
        }
    }
    else
    {
        emit this->connectionChanged(0,"");
        return;
    }
}
