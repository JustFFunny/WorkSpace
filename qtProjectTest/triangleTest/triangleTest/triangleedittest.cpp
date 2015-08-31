#include "triangleedittest.h"
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

TriangleEditTest::TriangleEditTest(QWidget *parent) :
    QWidget(parent)
{

}
void TriangleEditTest::paintEvent(QPaintEvent * event)
{

    QPainter * paint;
    paint=new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::blue,4,Qt::DashLine)); //设置画笔形式
    paint->setBrush(QBrush(Qt::red,Qt::SolidPattern)); //设置画刷形式
    paint->drawRect(20,20,160,160);
    paint->drawText(0,0,100,50,Qt::AlignHCenter,"hello");
    paint->end();
    QPixmap * pix=new QPixmap;
    pix->load("/home/wuqiankun/桌面/learn/webKIt/webkit/1.png",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
       resize(pix->size());
       setMask(QBitmap(pix->mask()));
    //setMask( QRegion(QRect(20,20,160,160)));

//    QBrush brush(QColor("#007430"));

//    painter->setBrush(brush);
//    painter->setPen(Qt::NoPen);
//    painter->setRenderHint(QPainter::Antialiasing);

//    painter->drawRoundedRect(0, 0, boundingRect().width(), boundingRect().height() - 10, 10, 10);

//    if (rightAligned)
//    {
//    const QPointF points[3] = {
//    QPointF(boundingRect().width() - 10.0, boundingRect().height() - 10.0),
//    QPointF(boundingRect().width() - 20.0, boundingRect().height()),
//    QPointF(boundingRect().width() - 30.0, boundingRect().height() - 10.0),
//    };
//    painter->drawConvexPolygon(points, 3);
//    }
//    else
//    {
//    const QPointF points[3] = {
//    QPointF(10.0, boundingRect().height() - 10.0),
//    QPointF(20.0, boundingRect().height()),
//    QPointF(30.0, boundingRect().height() - 10.0),
//    };
//    painter->drawConvexPolygon(points, 3);
//    }
}


