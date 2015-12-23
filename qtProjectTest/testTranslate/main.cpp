
#include <QApplication>
#include <QFileDialog>
#include <QObject>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
  QTranslator _t;
  _t.load(":/language/qiankun.qm");
  qApp->installTranslator(&_t);

  QString  fileName = QFileDialog::getSaveFileName(NULL, \
        QObject::tr("Open Image"), "/home/",  QObject::tr("Image Files (*.png *.jpg *.bmp)"));
    return a.exec();
}
