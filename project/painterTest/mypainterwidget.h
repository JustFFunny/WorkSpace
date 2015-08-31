#ifndef MYPAINTERWIDGET_H
#define MYPAINTERWIDGET_H

#include <QWidget>
#include <vector>
using namespace std;
//线段
typedef struct myLine{
    QPoint startPnt;
    QPoint endPnt;
}myLine;
class MyPainterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyPainterWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent* p);
signals:
    
public slots:
public:
    QPoint startPnt;   //起点
    QPoint endPnt;     //终点

   vector<myLine> lines; //存放所有的线段
    
};

#endif // MYPAINTERWIDGET_H
