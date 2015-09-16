#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("QMainWindow{ background-image: url(:/pics/bgPortrait.jpg)}");
#if defined(Q_WS_S60)
    w.showFullScreen();
#else
    w.show();
#endif

    return a.exec();
}
