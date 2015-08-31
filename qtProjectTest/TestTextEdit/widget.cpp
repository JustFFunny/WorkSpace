#include "widget.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <QHBoxLayout>
/*
 *根据文件的内容 自动改变文件的大小
 **/
Widget::Widget(QWidget *parent) :
    QWidget(parent)
{

//QVBoxLayout  *grid =  new QVBoxLayout;
    QHBoxLayout * grid =new QHBoxLayout;
QTextEdit *text_edit = new QTextEdit("Some content* I make this a little bit longer as I want to see the effect on a widget with more than one line*");
text_edit->setReadOnly(1);
text_edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
text_edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//text_edit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

 text_edit->setFixedWidth(200);

//Qt*WA_DontShowOnScreen = 103;//, PyQt does not have this mapping?!
//text_edit->setAttribute(103);
text_edit->show();

text_edit->setFixedHeight(text_edit->document()->size().height() + text_edit->contentsMargins().top()*2);
std::cout<<text_edit->document()->size().height()<<"\n";
grid->addWidget(text_edit);
setLayout(grid);
}
void Widget::setText()
{
//    text_edit->setFixedHeight(text_edit->document()->size().height() + text_edit->contentsMargins().top()*2);
//    std::cout<<text_edit->document()->size().height()<<"\n";
}
