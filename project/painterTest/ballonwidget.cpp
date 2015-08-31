#include "ballonwidget.h"
#include <QPainter>
#include <QBitmap>
//全绘制
BallonWidget::BallonWidget(QWidget *parent,QString mess):
    QWidget(parent),m_message(mess)
{
}

BallonWidget::~BallonWidget()
{
}

void BallonWidget::paintEvent(QPaintEvent *)
{
    QBrush brush(QColor("#007430"));
    QPainter * painter=new QPainter();
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->setRenderHint(QPainter::Antialiasing);
    boundingRect();
    painter->drawRoundedRect(0, 0, boundingRect().width(), boundingRect().height() - 10, 10, 10);
    painter->setFont(QFont(QString::fromLocal8Bit("宋体"),50,-1,false));
    painter->drawText(   QRect (0,0,boundingRect().width(),boundingRect().height()),Qt::AlignHCenter|Qt::AlignVCenter,QString::fromLocal8Bit("中国"));

    if (m_message=="inbox")
    {
    const QPointF points[3] = {
    QPointF(boundingRect().width() - 10.0, boundingRect().height() - 10.0),
    QPointF(boundingRect().width() - 20.0, boundingRect().height()),
    QPointF(boundingRect().width() - 30.0, boundingRect().height() - 10.0),
    };
    painter->drawConvexPolygon(points, 3);
    }
    else
    {
    const QPointF points[3] = {
    QPointF(10.0, boundingRect().height() - 10.0),
    QPointF(20.0, boundingRect().height()),
    QPointF(30.0, boundingRect().height() - 10.0),
    };
    painter->drawConvexPolygon(points, 3);
    }
}
QRect BallonWidget::boundingRect()
{
  //计算窗口的大小
//   int height;
//   int _height=m_message.getBody().count()/16;

    return QRect(0,0,200,200);
}
