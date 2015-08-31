#include "videothread.h"
#include <QSettings>
#include <QProcess>
#include <QDir>

VideoThread::VideoThread(QObject *parent) :
    QThread(parent)
{
}

void VideoThread::run()
{
    QString currentPath = QDir::currentPath()+"/tmp/Video/";
    QSettings settings;
    QString sdk;
    sdk = settings.value("sdkPath").toString();
    QProcess proces;
    QString tmp;
    proces.setProcessChannelMode(QProcess::MergedChannels);
    bool b = true;
    while(b)
    {
        proces.start( sdk + "adb pull /sdcard/Gundam/VideoSuccess "+currentPath);
        proces.waitForFinished(-1);
        tmp = proces.readAll();
        if(!tmp.contains("does not exist"))
        {
            proces.start( sdk + "adb pull /sdcard/Gundam/Video " + currentPath);
            proces.waitForFinished(-1);
            tmp = proces.readAll();
            b = false;
            emit VideoFinished();
        }else
        {
            sleep(2);
        }
    }
}
