/***********************************************************************
*Copyright 2010-20XX by 7ymekk
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
*   @author 7ymekk (7ymekk@gmail.com)
*
************************************************************************/


#include <QtGui/QApplication>
#include "./classes/application.h"
#include "./dialogs/mainwindow.h"
////////////////////////////////////////
#include <QtDebug>
#include <QFile>
#include <QTextStream>

void myMessageHandler(QtMsgType type, const char *msg)
{
    QStringList args = qApp->arguments();

    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);       
        abort();
    }
    if (args.contains("--debug"))
    {
        QFile outFile("debug.log");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ts(&outFile);

        txt.remove(QChar( 0xa ),Qt::CaseInsensitive);
        txt.remove(QChar( 0xd ),Qt::CaseInsensitive);

        ts << txt << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Bracia");
    QCoreApplication::setApplicationName("Gundam");
    QCoreApplication::setApplicationVersion("0.8.1");
    QCoreApplication::setOrganizationDomain("http://gundam.com");
    Application a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    qInstallMsgHandler(myMessageHandler);
    a.loadTranslations(":/lang");
    a.loadTranslations(qApp->applicationDirPath());
    a.setQuitOnLastWindowClosed(true);
    qDebug()<<"app version: "<<QCoreApplication::applicationVersion();
    QSettings settings;
    QString sdk;
    sdk = "/home/jyf/gundam-adb/";
    //sdk = "/usr/share/gundam-asst/application/lib/";

    QString locale = QLocale::system().name().left(2);
    QString lang = settings.value("Language", locale).toString();
    bool langSet = false;

    if (!Application::availableLanguagesRes().contains(lang))
        lang = "en";
    foreach (QString avail, Application::availableLanguagesRes())
    {
        if (avail == lang)
        {
            langSet = true;
            Application::setLanguage(lang, "res");
        }
    }

    foreach (QString avail, Application::availableLanguagesDir())
    {
        if ((avail == lang) && (langSet == false))
        {
            Application::setLanguage(lang, "dir");
        }
    }

    bool sdkOk = false;
    do{
        QString tmp;
        if (sdk.isEmpty())
        {
            sdk=QFileDialog::getExistingDirectory(NULL,QObject::tr("Choose path to dir with adb and aapt binaries"),"/");
            if (!sdk.isEmpty())
                sdk.append("/");
        }
        if (!sdk.isEmpty())
        {
            QDir checkSDK(sdk);
            QFileInfoList list=checkSDK.entryInfoList();
            while(list.length()>0)
            {
                tmp = list.takeFirst().fileName();
                if (tmp.contains("adb"))
                {
                    sdkOk=true;
                    break;
                }
            }
        }
        if (!sdkOk)
        {
            sdk.clear();
            QMessageBox *msgBox = new QMessageBox(QMessageBox::Critical, QObject::tr("error"), QObject::tr("there is no adb binary in here!"));
            QPushButton *choosePathMsg = msgBox->addButton(QObject::tr("Choose path"), QMessageBox::AcceptRole);
            QPushButton *closeMsg = msgBox->addButton(QObject::tr("Close"), QMessageBox::RejectRole);

            msgBox->exec();

            if (msgBox->clickedButton() == choosePathMsg)
            {
                continue;
            }
            else
            {
                break;
            }
            delete closeMsg;
            delete choosePathMsg;
            delete msgBox;
        }
        else break;
    }while(true);

    if (sdkOk){

        settings.setValue("sdkPath", sdk);
        settings.setValue("connectType", "usb");
        settings.setValue("wlanIP","127.0.0.1");
        settings.setValue("cPort","6101");
        settings.setValue("sPort","6100");

        QProcess proces;
//      adbd cannot run as root in production builds
        proces.setProcessChannelMode(QProcess::MergedChannels);
        proces.start("\"" + sdk + "\"adb version");
        proces.waitForFinished(-1);
        QString tmp = proces.readAll();
        qDebug()<<"adb version - "<<tmp;
        if (proces.exitCode() != 0)
        {
            qDebug()<<"adb error - "<<proces.errorString();
            QMessageBox *msgBox = new QMessageBox(QMessageBox::Critical, QObject::tr("error"), QObject::tr("It seems that adb is not working properly"), QMessageBox::Ok);
            msgBox->exec();
            delete msgBox;
            return 1;
        }

        MainWindow w;
        //w.setWindowFlags(w.windowFlags() &~ Qt::WindowMinMaxButtonsHint);
        w.show();
        return a.exec();
    }
    else{
        return 0;
    }
}
