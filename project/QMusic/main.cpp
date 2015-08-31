#include <QtGui/QApplication>
#include "qplayer.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QPlayer w;
    w.show();
    return a.exec();
}
