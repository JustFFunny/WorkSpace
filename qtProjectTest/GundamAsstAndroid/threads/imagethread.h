#ifndef IMAGETHREAD_H
#define IMAGETHREAD_H

#include <QThread>

class ImageThread : public QThread
{
    Q_OBJECT
public:
    explicit ImageThread(QObject *parent = 0);

private:
    void run();

signals:
    void ImageFinished();
        
};

#endif // IMAGETHREAD_H
