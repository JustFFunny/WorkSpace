#include "icondelegate.h"
#include <QIcon>
#include <QPixmap>
#include <QPainter>
#include <QStyleOption>
#include <QApplication>

IconDelegate::IconDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}
void IconDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QApplication::style()->drawItemPixmap(painter,option.rect,Qt::AlignCenter,QPixmap(":/icon/icon/video_select.png"));
}



bool IconDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{

    //    if (event->type() == QEvent::MouseButtonPress) {

    //        QMouseEvent* e =(QMouseEvent*)event;

    //        if (m_btns.contains(index)) {
    //            QPair<QStyleOptionButton*, QStyleOptionButton*>* btns = m_btns.value(index);
    //            if (btns->first->rect.contains(e->x(), e->y())) {
    //                btns->first->state |= QStyle::State_Sunken;
    //            }
    //            else if(btns->second->rect.contains(e->x(), e->y())) {
    //                btns->second->state |= QStyle::State_Sunken;
    //            }
    //        }
    //    }
    if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent* e =(QMouseEvent*)event;

        //        if (m_btns.contains(index)) {
        //            QPair<QStyleOptionButton*, QStyleOptionButton*>* btns = m_btns.value(index);
        //            if (btns->first->rect.contains(e->x(), e->y())) {
        //                btns->first->state &= (~QStyle::State_Sunken);
        //                //showMsg(tr("btn1 column %1").arg(index.column()));
        //                 emit  rowSignal(index.row());
        //            } else if(btns->second->rect.contains(e->x(), e->y())) {
        //                btns->second->state &= (~QStyle::State_Sunken);
        //               // showMsg(tr("btn2 row %1").arg(index.row()));
        emit  row(index);
    }
//}
//}

}
