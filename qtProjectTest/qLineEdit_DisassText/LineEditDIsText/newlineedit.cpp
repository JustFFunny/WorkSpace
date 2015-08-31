#include "newlineedit.h"
#include <QDebug>
#include <QMouseEvent>
//鼠标点击的时候  文字消失,彻底的消失
//鼠标点击的时候  文字消失,彻底的消失,当鼠标失去焦点的时候,有显示
NewlINeEdit::NewlINeEdit(QWidget *parent) :
    QLineEdit(parent)
{
    this->setText("aaa");
    this->setStyleSheet("QLineEdit(color:green)");

}

//void NewlINeEdit::mousePressEvent(QMouseEvent * event)////鼠标点击的时候  文字消失,彻底的消失
//{

//     if (event->button() == Qt::LeftButton)
//     {
//            qDebug()<<"this way";
//         if(this->text()=="aaa")
//         {
//             this->setText("");
//         }

//     }
//}

void NewlINeEdit::focusInEvent(QFocusEvent * event)
{
    qDebug()<<"focusInEvent";
    this->setText("");
}

void NewlINeEdit::focusOutEvent(QFocusEvent *event)
{
  qDebug()<<"focusOutEvent";
  this->setText("2");
}
