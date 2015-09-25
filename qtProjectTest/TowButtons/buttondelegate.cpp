#include "buttondelegate.h"

#include <QApplication>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QStyleOption>
#include <QDesktopWidget>
#include <QIcon>
#include <QPixmap>

ButtonDelegate::ButtonDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}


void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QPair<QStyleOptionButton*, QStyleOptionButton*>* buttons = m_btns.value(index);
    if (!buttons) {
        QStyleOptionButton* button1 = new QStyleOptionButton();
        //button1->rect = option.rect.adjusted(4, 4, -(option.rect.width() / 2 + 4) , -4); //
        //button1->text = "X";
       // button1->icon=QIcon(":/icon/icon/video_select.png");//.scaled(50,50);
        button1->state |= QStyle::State_Enabled;

        QStyleOptionButton* button2 = new QStyleOptionButton();
        //button2->rect = option.rect.adjusted(button1->rect.width() + 4, 4, -4, -4);
        button2->text = "Y";
        button2->state |= QStyle::State_Enabled;
        buttons =new  QPair<QStyleOptionButton*, QStyleOptionButton*>(button1, button2);
        (const_cast<ButtonDelegate *>(this))->m_btns.insert(index, buttons);
    }
    buttons->first->rect = option.rect.adjusted(4, 4, -(option.rect.width() / 2 + 4) , -4); //
    buttons->second->rect = option.rect.adjusted(buttons->first->rect.width() + 4, 4, -4, -4);
    painter->save();

    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, option.palette.highlight());
    }
    painter->restore();
    QApplication::style()->drawControl(QStyle::CE_PushButton, buttons->first, painter);
    /*virtual void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p,
                             const QWidget *w = 0) const = 0;
     *
     *   virtual void drawItemPixmap(QPainter *painter, const QRect &rect,
                                int alignment, const QPixmap &pixmap) const;
     */
    //test
    QApplication::style()->drawItemPixmap(painter,option.rect,Qt::AlignCenter,QPixmap(":/icon/icon/delete_icon.png"));

    QApplication::style()->drawControl(QStyle::CE_PushButton, buttons->second, painter);
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress) {

        QMouseEvent* e =(QMouseEvent*)event;

        if (m_btns.contains(index)) {
            QPair<QStyleOptionButton*, QStyleOptionButton*>* btns = m_btns.value(index);
            if (btns->first->rect.contains(e->x(), e->y())) {
                btns->first->state |= QStyle::State_Sunken;
            }
            else if(btns->second->rect.contains(e->x(), e->y())) {
                btns->second->state |= QStyle::State_Sunken;
            }
        }
    }
    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent* e =(QMouseEvent*)event;

        if (m_btns.contains(index)) {
            QPair<QStyleOptionButton*, QStyleOptionButton*>* btns = m_btns.value(index);
            if (btns->first->rect.contains(e->x(), e->y())) {
                btns->first->state &= (~QStyle::State_Sunken);
                //showMsg(tr("btn1 column %1").arg(index.column()));
                 emit  rowSignal(index.row());
            } else if(btns->second->rect.contains(e->x(), e->y())) {
                btns->second->state &= (~QStyle::State_Sunken);
               // showMsg(tr("btn2 row %1").arg(index.row()));
               emit  rowSignal(index.row());
            }
        }
    }
}

void ButtonDelegate::showMsg(QString str)
{
    QMessageBox msg;
    msg.setText(str);
    msg.exec();
}
