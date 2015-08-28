#ifndef NEWLINEEDIT_H
#define NEWLINEEDIT_H
//鼠标点击的时候  文字消失,彻底的消失
#include <QLineEdit>
#include <QEvent>

class NewlINeEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit NewlINeEdit(QWidget *parent = 0);
   // void mousePressEvent(QMouseEvent *);

/////
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
signals:
    
public slots:
    
};

#endif // NEWLINEEDIT_H
