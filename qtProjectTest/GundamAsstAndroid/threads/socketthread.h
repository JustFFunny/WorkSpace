#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QtNetwork>

class SocketThread : public QThread
{
    Q_OBJECT
public:
    explicit SocketThread(QObject *parent = 0);
    QTcpSocket *m_pClient;
signals:
    void readData(QString mesg);
    
public slots:
    void run();
};

#endif // SOCKETTHREAD_H
