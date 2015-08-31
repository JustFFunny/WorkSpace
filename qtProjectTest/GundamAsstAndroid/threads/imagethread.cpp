#include "imagethread.h"
#include <QSettings>
#include <QProcess>
#include <QDir>
#include <QtGui>
#include <QtNetwork>

ImageThread::ImageThread(QObject *parent) :
    QThread(parent)
{
}

void ImageThread::run()
{
    QString currentPath = QDir::currentPath()+"/tmp/Image/";
    QSettings settings;
    QString sdk;
    sdk = settings.value("sdkPath").toString();

    QProcess proces;
    QString tmp;
    proces.setProcessChannelMode(QProcess::MergedChannels);
    bool b = true;
    while(b)
    {
        proces.start( sdk + "adb pull /sdcard/Gundam/ImageSuccess "+currentPath);
        proces.waitForFinished(-1);
        tmp = proces.readAll();
        if(!tmp.contains("does not exist"))
        {
            proces.start( sdk + "adb pull /sdcard/Gundam/Image " + currentPath);
            proces.waitForFinished(-1);
            tmp = proces.readAll();
            b = false;
            emit ImageFinished();
        }else
        {
            sleep(2);
        }
    }
}

