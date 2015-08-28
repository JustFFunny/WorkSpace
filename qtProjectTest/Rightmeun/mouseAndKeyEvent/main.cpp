#include <QApplication>
#include <QWidget>
#include <subwidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWidget * _widget=new QWidget;
//    _widget->show();
    subWidget * _subwidget=new subWidget;
    _subwidget->show();
    return a.exec();
}
