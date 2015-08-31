#ifndef QPROJECTLIST_H
#define QPROJECTLIST_H
//怎样进行drag，怎样接受drop。
//该类可以接受drag and drop
#include <QListWidget>
#include <QPoint>

class QProjectList : public QListWidget
{
    Q_OBJECT
public:
    explicit QProjectList(QWidget *parent = 0);
    
signals:
    
public slots:
public:
 //重新实现  5个QWidget中声明的事件处理函数（有很多的）
   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *e);

   void dragEnterEvent(QDragEnterEvent *event);
   void dragMoveEvent(QDragMoveEvent *e);
   void dropEvent(QDropEvent *event);
private:
   void startDrag();
   QPoint startPos;
    
};

#endif // QPROJECTLIST_H
