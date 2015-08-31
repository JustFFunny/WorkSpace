#include "pcoverwidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QBitmap>
#include <QGridLayout>
#include <QTimer>
#include <QTime>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    QPalette p=palette();
    p.setColor(QPalette::WindowText,Qt::green);
    setPalette(p);

    l=new QLabel;
    QTime time=QTime::currentTime();
    QTextEdit * t=new QTextEdit;
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(l,0,0,Qt::AlignHCenter);
    mainLayout->addWidget(t);

    pix.load("1.png",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));

//    QTimer *timer=new QTimer;
//    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
//    timer->start(10);
}

Widget::~Widget()
{

}

void Widget::showtime()
{
    QTime time=QTime::currentTime();
    l->setText(time.toString("A hh:mm:ss"));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button()==Qt::RightButton)
    {
        close();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalPos()-dragPosition);
    event->accept();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("1.png"));
}
