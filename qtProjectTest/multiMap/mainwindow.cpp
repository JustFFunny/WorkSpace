#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QFont>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget;
    QLabel * label=new QLabel("HELLO");
    QLineEdit * lineDit=new QLineEdit;
    QHBoxLayout * hboxlyaot=new QHBoxLayout;
    hboxlyaot->addWidget(label,3,Qt::AlignRight);
    hboxlyaot->addWidget(lineDit,0,Qt::AlignRight);
    ui->widget->setLayout(hboxlyaot);

    //    QFont _font;
    //    _font.setFamily("/home/wuqiankun/文档/gitHub/WorkSpace/qtProjectTest/multiMap/字体/Arial.ttf");
    //    ui->label->setFont(_font);
    qDebug()<< ui->label->font().family();


    QFont _font2;
    _font2.setFamily("方正魏碑_GBK");
    _font2.setPointSize(40);
    ui->label_2->setFont(_font2);
    ui->label_2->setText("大江东去浪淘尽");
    ui->label_2->setStyleSheet("QLabel#label_2 {border:1px solid red; }");
    ui->widget->setStyleSheet("QWidget#widget {border:1px solid red; }");
    //字体路径
    // /usr/share/fonts/truetype
}

MainWindow::~MainWindow()
{
    delete ui;
}
