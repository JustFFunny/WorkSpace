#include "androidapk.h"

AndroidAPK::AndroidAPK()
{
    sdk = settings.value("sdkPath").toString();
    proces.setProcessChannelMode(QProcess::MergedChannels);
}

void AndroidAPK::init()
{
    proces.start( sdk + "adb push " + sdk+ "busybox/ /data/local/tmp/busybox");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Image");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Audio");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Video");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Gundam");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Gundam/tmp");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Gundam/Image");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Gundam/Video");
    proces.waitForFinished(-1);
    proces.start("\""+sdk+"\""+"adb shell mkdir /sdcard/Gundam/Audio");
    proces.waitForFinished(-1);
}

int AndroidAPK::installApk()
{
    proces.start(sdk + "adb install "+sdk+ "Gundam-common.apk");
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("Success"))
    {
        return 0;
    }
    return -1;
}

int AndroidAPK::startMainActivity()
{
    proces.start("\"" + sdk + "\"adb shell am force-stop com.gundam.asst");
    proces.waitForFinished(-1);
    proces.start("\"" + sdk + "\"adb shell am start -n com.gundam.asst/.MainActivity");
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("does not exist."))
    {
        return -1;
    }
    return 0;
}

int AndroidAPK::scarnSdcard()
{
    proces.start( sdk + "./adb shell am startservice -n com.gundam.asst/.ScanSdService");
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("Error"))
    {
        return -1;
    }
    return 0;
}

int AndroidAPK::imageUpdate()
{
    proces.start( sdk + "./adb shell am startservice -n com.gundam.asst/.ImageService");
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("Error"))
    {
        return -1;
    }
    return 0;
}

int AndroidAPK::audioUpdate()
{
    proces.start( sdk + "./adb shell am startservice -n com.gundam.asst/.AudioService");
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("Error"))
    {
        return -1;
    }
    return 0;
}

int AndroidAPK::videoUpdate()
{
    proces.start( sdk + "./adb shell am startservice -n com.gundam.asst/.VideoService");
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("Error"))
    {
        return -1;
    }
    return 0;
}


//./adb shell am start -n com.gundam.asst/.ScanFileActivity -e FilePath /Image/a.png
int AndroidAPK::fielUpdate(QString filePath)
{
    proces.start( sdk + "./adb shell am start -n com.gundam.asst/.ScanFileActivity -e FilePath "+filePath);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("Error"))
    {
        return -1;
    }
    return 0;
}



QString AndroidAPK::push(QString src, QString dest)
{

    QString filename = src.split("/").last();
    filename.replace(QRegExp("[:-]"),"");
    QString path = "";
    proces.start( sdk + "adb push \"" + src + "\" " + "/sdcard/"+ dest+filename);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("bytes in"))
    {
        path = dest+filename;
    }
    return path;
}

int AndroidAPK::pull(QString src, QString dest)
{
    proces.start( sdk + "adb pull \"" + src + "\" " + dest);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("bytes in"))
    {
        return 0;
    }
    return -1;
}

void AndroidAPK::mkdir(QString path)
{
    proces.start("\""+sdk+"\""+"adb shell mkdir \"" + path + "\"");
    proces.waitForFinished(-1);
    tmp = proces.readAll();
}

void AndroidAPK::forward(QString port1, QString port2)
{
    if(port1.isEmpty() || port2.isEmpty())
        proces.start( sdk + "adb forward tcp:6100 tcp:7100");
    else
        proces.start( sdk + "adb forward tcp:"+port1+" tcp:"+port2);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
}


void AndroidAPK::pullImage()
{
    QString currentPath = QDir::currentPath()+"/tmp/Image/";
    proces.start( sdk + "adb pull /sdcard/Gundam/Image " + currentPath);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
}

void AndroidAPK::pullAudio()
{
    QString currentPath = QDir::currentPath()+"/tmp/Audio/";
    proces.start( sdk + "adb pull /sdcard/Gundam/Audio " + currentPath);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
}

void AndroidAPK::pullVideo()
{
    QString currentPath = QDir::currentPath()+"/tmp/Video/";
    proces.start( sdk + "adb pull /sdcard/Gundam/Video " + currentPath);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
}

int AndroidAPK::sendSMS(QString num, QString body)
{
    proces.start( sdk + "./adb shell am start -n com.gundam.asst/.SmsActivity -e sms " + num + " -e sms_body "+body);
    proces.waitForFinished(-1);
    tmp = proces.readAll();
    if(tmp.contains("Error"))
    {
        return -1;
    }
    return 0;

}




