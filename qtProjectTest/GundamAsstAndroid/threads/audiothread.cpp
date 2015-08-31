#include "audiothread.h"
#include <QSettings>
#include <QProcess>
#include <QDir>

AudioThread::AudioThread(QObject *parent) :
    QThread(parent)
{
}

void AudioThread::run()
{
    QString currentPath = QDir::currentPath()+"/tmp/Audio/";
    QSettings settings;
    QString sdk;
    sdk = settings.value("sdkPath").toString();
    QProcess proces;
    QString tmp;
    proces.setProcessChannelMode(QProcess::MergedChannels);
    bool b = true;
    while(b)
    {
        proces.start( sdk + "adb pull /sdcard/Gundam/AudioSuccess "+currentPath);
        proces.waitForFinished(-1);
        tmp = proces.readAll();
        if(!tmp.contains("does not exist"))
        {
            proces.start( sdk + "adb pull /sdcard/Gundam/Audio " + currentPath);
            proces.waitForFinished(-1);
            tmp = proces.readAll();
            b = false;
            emit AudioFinished();
        }else
        {
            sleep(2);
        }
    }
}
