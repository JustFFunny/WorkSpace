#ifndef ANDROIDAPK_H
#define ANDROIDAPK_H

#include <QSettings>
#include <QProcess>
#include <QDir>

class AndroidAPK
{
public:
    AndroidAPK();

    QSettings settings;
    QString sdk ;
    QProcess proces;
    QString tmp;

    void init();
    int installApk();
    int startMainActivity();

    int scarnSdcard();
    int imageUpdate();
    int audioUpdate();
    int videoUpdate();
    int fielUpdate(QString filePath);

    void mkdir(QString path);
    QString push(QString src, QString dest);
    int pull(QString src, QString dest);
    int dele(QString path);

    void forward(QString port1 = "", QString port2 = "");
    void pullImage();
    void pullAudio();
    void pullVideo();

    int sendSMS(QString num, QString body);

};

#endif // ANDROIDAPK_H
