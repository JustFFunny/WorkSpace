#ifndef PCOVERWIDGET_H
#define PCOVERWIDGET_H

#include <QWidget>
#include <QLabel>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
protected:
//这里的三个函数都是重载函数，可以响应响应的事件
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);//这个在窗口需要重绘的时候自动调用
private slots:
    void showtime();
private:
    QPoint dragPosition;
    QLabel *l;
    QPixmap pix;
};

#endif // PCOVERWIDGET_H
