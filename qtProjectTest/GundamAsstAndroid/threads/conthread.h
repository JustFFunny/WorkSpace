#ifndef CONTHREAD_H
#define CONTHREAD_H

#include <QThread>
#include <QTcpSocket>

class ConThread : public QThread
{
    Q_OBJECT
public:
    ConThread();
    void run();
    QTcpSocket *socket;

signals:
    void connectionChanged(int,QString);
};

#endif // CONTHREAD_H
