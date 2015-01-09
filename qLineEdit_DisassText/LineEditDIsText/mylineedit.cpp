#include "mylineedit.h"
#include <QDebug>

mylineEdit::mylineEdit(QWidget *parent) :
    QWidget(parent)
{
    _l=new QLineEdit;
   _l->setText("aa");
    _l->show();
   // _l->setStyleSheet("  QLineEdit{   text:a };   ");
    QObject::connect(_l,SIGNAL(textChanged(QString)),this,SLOT(test(QString )));
}


