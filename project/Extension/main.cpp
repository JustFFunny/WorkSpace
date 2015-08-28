#include <QApplication>
#include <extension.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Extension exten;
      exten.show();
    return a.exec();
}
