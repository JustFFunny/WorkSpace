#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class mylineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit mylineEdit(QWidget *parent = 0);
      QLineEdit * _l;
//      void focusInEvent(QFocusEvent *);
//      void focusOutEvent(QFocusEvent *);
signals:
    
public slots:

    
};

#endif // MYLINEEDIT_H
