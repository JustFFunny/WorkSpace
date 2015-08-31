#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>

class VideoThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = 0);
    
private:
    void run();

signals:
    void VideoFinished();
    
};

#endif // VIDEOTHREAD_H
