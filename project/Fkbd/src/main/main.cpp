#include <QApplication>
#include <QIcon> 
#include <QSystemTrayIcon>
#include <QMenu>
#include <QDeclarativeContext>
#include <QUuid>

#include <stdio.h>


#include "vkbd.h"
#include "keyboardapplication.h"

FILE * out = stderr;


void myMessageOutput(QtMsgType type, const char *msg)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dt = dateTime.toString("yyyyMMdd hh:mm:ss:zzz");
    switch (type) {
    case QtDebugMsg:
        fprintf(out, "%s Debug: %s\n",qPrintable(dt), msg);
        break;
    case QtWarningMsg:
        fprintf(out, "%s Warning: %s\n",qPrintable(dt), msg);
        break;
    case QtCriticalMsg:
        fprintf(out, "%s Critical: %s\n",qPrintable(dt), msg);

        break;
    case QtFatalMsg:
        fprintf(out, "%s Fatal: %s\n",qPrintable(dt), msg);

        FILE * crash = fopen("fatal.txt","a");
        if (crash)
        {
            fprintf(crash, "%s Fatal: %s\n",qPrintable(dt), msg);
            fclose(crash);
        }
        abort();
    }
}

void logToFile(bool log)
{
    if (log)
    {
        out = fopen("log.txt","a");
        if (!out)
            out = stderr;
    }
}

int main(int argc, char *argv[])
{
    KeyboardApplication app(argc, argv);

    //QCoreApplication::setOrganizationName("3electrons");
    //QCoreApplication::setApplicationName("Fkbd");

    qInstallMsgHandler(myMessageOutput);
    logToFile(app.arguments().contains("-log"));

    // Icon
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/resources/resources/vkbd_64.png"), QSize(), QIcon::Normal, QIcon::Off);


    // VKBD
    Vkbd vkbd;
    vkbd.setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint |  Qt::Tool );
    vkbd.setWindowIcon(icon);

    // TRAY
    QSystemTrayIcon tray(icon);
    QMenu * menu = new QMenu;
    QAction * close = menu->addAction(QObject::trUtf8("&Zamknij"));
    //tray.setContextMenu(menu);

    QObject::connect(close,SIGNAL(triggered()),&app,SLOT(quit()));
    QObject::connect(&vkbd, SIGNAL(closed()), &app,SLOT(quit()));

    vkbd.show();
    app.setKeyboardWidget(&vkbd);

    tray.show();
    //tray.showMessage("Fkbd",QObject::trUtf8("Klawiatura ekranowa jest\ngotowa do u\305\274ycia."));

    return app.exec();

}// main 

