/*验证的是：QTextEdit右键菜单 英文转变为中文
 *
 *fir:QTranslator安装了中文翻译以后，
 *就可QlineEdit右键的英文就会翻译成中文;
 *然而QTextEdit 右键的英文还是英文需要进一步的修改。
 *
 **/
#include "mainwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <QTranslator>
#include <QLineEdit>
#include <QObject>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
//    QTranslator trl;
//    trl.load(QString(":/language/qt_zh_CN.qm"));
//    a.installTranslator(&trl);


//    QTextEdit te;
//    te.setWindowTitle(("QTextEdit"));
//    te.show();

//    //
//    QLineEdit le;
//    le.setWindowTitle(("QLineEdit"));
//    le.show();

    QLabel l;
    l.setWindowTitle(QObject::tr("QLabel"));
    l.show();
    return a.exec();
}
