#include <QApplication>
#include <QPainter>
#include "triangleedittest.h"
#include "qibao.h"
#include "pcoverwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    TriangleEditTest * _tri=new TriangleEditTest;
//    _tri->show();
    Qibao * _qipao=new Qibao;
_qipao->show();
// Widget * _p=new Widget;
// _p->show();

    return a.exec();
}
