#include "mainwindow.h"
#include <QApplication>
#include "./singleapp.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SingleApp _singleapp(argc,argv);
    if(!_singleapp.isRuning())
    {
        MainWindow w;
        _singleapp.w=&w;
        w.show();

        return a.exec();
    }
    else
    {
        return 0;
    }

}
