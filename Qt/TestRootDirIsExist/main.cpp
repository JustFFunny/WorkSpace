#include <QCoreApplication>
#include <QDir>
#include  <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
      QDir _dir;
      bool _b=_dir.exists("/media/iPhone");
      qDebug()<<_b;
    return a.exec();
}
