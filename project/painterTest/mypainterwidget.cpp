#include "mypainterwidget.h"
#include <QPainter>
#include <QPen>

MyPainterWidget::MyPainterWidget(QWidget *parent) :
    QWidget(parent)
{
//    setMinimumSize(240,120);
//    setMaximumSize(480,240);
    setFixedSize(100,100);
    myLine  _myline;
    _myline.startPnt=QPoint(0,0);_myline.endPnt=QPoint(100,100);
    lines.push_back(_myline);
    this->setStyleSheet("QWidget{background-color:white;}");
//    _myline.startPnt=100;_myline.endPnt=100;
//    lines.push_back(_myline);


}
void MyPainterWidget::paintEvent(QPaintEvent*p)
{
    QPainter painter(this);
    QPen pen;                                 //创建一个画笔
    pen.setColor(Qt::darkCyan);
    pen.setWidth(5);
    painter.setPen(pen);

    for(int i = 0;i<lines.size();i++)
    {
        myLine pLine = lines[i];
        painter.drawLine(pLine.startPnt,pLine.endPnt);
    }
}
