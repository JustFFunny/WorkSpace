/*验证:
 *当在构造函数中异常退出以后, 是否还要走 析构函数.
 *验证前认为: 异常以后,不再进行析构函数.
 *结论:????
 **/

#include "widgettest.h"
#include "ui_widgettest.h"
#include <QDebug>

WidgetTest::WidgetTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTest)
{
    ui->setupUi(this);
    //Test  异常退出
//    QStringList _list;
//    _list<<"aa";
//    _list.at(2);
    connect( ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}

WidgetTest::~WidgetTest()
{
    qDebug()<<"deconstruct!";
    delete ui;
}
