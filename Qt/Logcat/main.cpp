#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <QStringList>
#include <QDebug>

#include "widgettest.h"
//异常信息的捕获
void myMessageOutput(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", msg);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg);
        fprintf(stderr, "wuqiankun: find error output");
        //abort();
    }
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qInstallMsgHandler(myMessageOutput);

    //    //异常以后从, qinstallMsgHandler(),捕获异常信息直接退出.
    //    QStringList _list;
    //    _list<<"aa";
    //    _list.at(2);//1.异常以后从, qinstallMsgHandler(),捕获异常信息直接退出.

    //new在堆中创建内存,结束的时候没有delete,内存不会被释放(即重新被 OS重新分配).
    //    WidgetTest * _widgetTest=new WidgetTest();
    //    _widgetTest->show();
    //    delete _widgetTest;



    //在栈中的分配内存,会随着{}后,自动释放内存.
    WidgetTest _test;
    _test.show();


    qDebug()<<"\n hello";
    return app.exec();

};
