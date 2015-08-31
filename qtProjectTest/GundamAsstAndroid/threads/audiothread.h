#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QThread>

class AudioThread : public QThread
{
    Q_OBJECT
public:
    explicit AudioThread(QObject *parent = 0);
    
private:
    void run();

signals:
    void AudioFinished();
    
};

#endif // AUDIOTHREAD_H
