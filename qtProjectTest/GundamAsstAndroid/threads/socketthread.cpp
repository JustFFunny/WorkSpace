#include "socketthread.h"

SocketThread::SocketThread(QObject *parent) :
    QThread(parent)
{
}

void SocketThread::run() {   
    while(true)
    {
        sleep(10);
        QString mesg = "SMS:GETNEW\n";
        m_pClient = new QTcpSocket();
        m_pClient->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
        if (m_pClient->waitForConnected(2000))
        {
            m_pClient->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
            m_pClient->waitForBytesWritten();
            m_pClient->waitForReadyRead(2000);
            while(m_pClient->canReadLine())
            {
                QString read = QString::fromUtf8(m_pClient->readLine());
                QString info  = read.split("\n")[0];
                if(info != NULL)
                {
                    emit readData(info);
                }
            }
        }
        m_pClient->disconnectFromHost();
        m_pClient->close();
        sleep(15);
    }
}


