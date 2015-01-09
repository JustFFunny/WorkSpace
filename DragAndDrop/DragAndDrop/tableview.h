#ifndef TABLEVIEW_H
#define TABLEVIEW_H
//MIME类通常由剪贴板和拖放系统使用，以识别不同类型的数据
//重新实现   QWidget的DRAGANDDROP四个函数
#include <QTableView>

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);
    
signals:
    
public slots:
protected:

    //当把一个对象拖动到这个 窗体上时，就会调用 dragEnterEvent
    //如果对这个事件调用acceptProposedAction()，就表明可以在这个窗体上拖放对象。默认情况下窗口部件是不接受拖动的。Qt会自动改变光标向用户说明这个窗口部件不是有效的放下点。
    //Event which is sent to a widget when a drag and drop action enters it
    void dragEnterEvent(QDragEnterEvent *event);

    //Event which is sent when a drag and drop action is completed
    void dropEvent(QDropEvent *event);


//一般情况下，不修改
    //Event which is sent while a drag and drop action is in progress
    void dragMoveEvent(QDragMoveEvent *event);

    //Event that is sent to a widget when a drag and drop action leaves it
     void dragLeaveEvent(QDragLeaveEvent *event);

    
    int i;
};

#endif // TABLEVIEW_H
