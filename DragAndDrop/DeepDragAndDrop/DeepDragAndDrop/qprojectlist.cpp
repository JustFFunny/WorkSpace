#include "qprojectlist.h"
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QMimeData>
QProjectList::QProjectList(QWidget *parent) :
    QListWidget(parent)
{
    setAcceptDrops(true);//允许控件接受drop
    setDropIndicatorShown(true);//drop的时候，指示器显示
    setWindowTitle("DeepDragAndDrop");
}

//当用户点击了鼠标左键时，我们把鼠标位置保存在startPos变量中。
//然后调用基类QListWidget的mousePressEvent()，使QListWidget能处理鼠标点击事件，
//即列表控件的鼠标点击事件进入程序的消息循环。
void QProjectList::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
       startPos=event->pos();
       QListWidget::mousePressEvent(event);
    }
}

void QProjectList::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        int distance=(e->pos()-startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance())//QApplication::startDragDistance() 默认是4个像素
        {
            startDrag();// 开始拖动 调用函数
        }
        QListWidget::mouseMoveEvent(e);
    }
}
void QProjectList::startDrag()
{
    QListWidgetItem * item=currentItem();
    if(item)
    {
        QMimeData * mineDate=new QMimeData;
         mineDate->setText(item->text());
         QDrag* drag=new Qdrag(this);
         drag->setMimeData(mineDate);
         //drag->setPixmap(QPixmap("picture.png"));//设置啦跟随鼠标的图标
         if(drag->start(Qt::MoveAction)==Qt::MoveAction)//开始拖动，直到用户drop(完成)，或者取消拖动
         {    //Starts the drag and drop operation and returns a value indicating the requested drop action when it is completed.
            delete item;
         }
    }
}








//ProjectListWidget不但可以产生drag，还可以接受来自程序中
//其他ProjectListWidget控件的drag。如果drag发生在同一个应用程序中，
//QDragEnterEvent::source()得到产生drag控件的指针。如果不是一个程序，则返回空指针。
//qobject_cast<T>()可以确保拖动来自与一个ProjectListWidget控件。
//如果一切正常，则调用accept()通知Qt接受这个action作为一个移动操作

//允许把 该事件拖放到该控件上   event->acceptProposedAction();
 //inline void acceptProposedAction() { drop_action = default_action; accept()};
void QProjectList::dragEnterEvent(QDragEnterEvent *event)
{
    QProjectList *source=qobject_cast<QProjectList *>(event->source());
    if(source && source!=this)
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }

}

void QProjectList::dragMoveEvent(QDragMoveEvent *e)
{
    QProjectList *source=qobject_cast<QProjectList *>(event->source());
    if(source && source!=this)
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }

}

void QProjectList::dropEvent(QDropEvent *event)
{
    QProjectList *source=qobject_cast<QProjectList *>(event->source());
    if(source && source!=this)
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }

}

