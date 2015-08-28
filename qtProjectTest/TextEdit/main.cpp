#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit * _t=new QTextEdit;

    _t->show();
    
    return a.exec();
}
