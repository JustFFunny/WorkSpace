#include <QCoreApplication>
#include "test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

  Test _t;
  _t.getJ();
  _t.getJ().get();



    return a.exec();
}
