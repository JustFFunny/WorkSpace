#include "subwidget.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPoint>
#include <QDebug>
#include <QIcon>
subWidget::subWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(const QPoint &)),this,SLOT(showMenu(const QPoint &)));
}
void subWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_F8:
        qDebug()<<"响应F8键盘消息，可以开始做相应OP";
        break;
    case Qt::Key_F9:
        qDebug()<<"响应F9键盘消息，可以开始做相应OP";
        break;
    }
}

void subWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton)
    {
        emit customContextMenuRequested(event->pos());//QWidget 的信号
    }
}

void subWidget::showMenu(const QPoint &pos)
{
    m_menu=new QMenu;
    //   m_menu->addAction("rename");
    //   m_menu->addAction("refush");
    //   m_menu->addAction("newDir");
    m_menu->addAction(QIcon(),tr("refush"),this,SLOT(showName()));
    m_menu->addAction(QIcon(),tr("rename"),this,SLOT(showName()));
    m_menu->addAction(QIcon(),tr("newDir"),this,SLOT(showName()));
    m_menu->addAction(QIcon(),tr("install"),this,SLOT(showName()));
            QPoint pos2;
    pos2.setX(pos.x());
    pos2.setY(pos.y()+20);
    m_menu->exec(pos2);
}
void subWidget::showName()
{
    qDebug()<<"hello qt ,this is a test";
}
