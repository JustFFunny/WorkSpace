#include "tableview.h"
#include <QDebug>
#include <QEvent>
#include <QDropEvent>
#include <QList>
#include <QUrl>
TableView::TableView(QWidget *parent) :
    QTableView(parent)
{
    i=0;
    setAcceptDrops(true);//接受放下事件
    setDropIndicatorShown(true);//清晰看到放下过程的图标指示


    setWindowTitle("DragAndDropTest");
}

//
void TableView::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/uri-list"))
    {
      event->acceptProposedAction();//允许把该事件拖放到 该控件上
    }
   qDebug()<<"drag enter";
}

void TableView::dragMoveEvent(QDragMoveEvent *event)//正在移动
{
    ++i;
    qDebug()<<"drag Move"<<i;
}

void TableView::dropEvent(QDropEvent *event)
{
   QList<QUrl> urls=event->mimeData()->urls();//MIME  颜色 url text  image
    if(urls.isEmpty())
        return;
    foreach (QUrl url, urls)
    {
        QString file_name=url.toLocalFile();
         qDebug()<<file_name;
    }

    qDebug()<<"drag Complete";
}
 void TableView::dragLeaveEvent(QDragLeaveEvent *event)
 {
     qDebug()<<"drag Leave";
 }
