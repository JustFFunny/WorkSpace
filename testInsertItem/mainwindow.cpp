/*
 *Qlistwidget插入的话,如果新建的item有父节点的话,insertItem无效==additem
 **/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidget * _test=new QListWidget();
    setCentralWidget(_test);
    for(int i=0;i<10;++i)
    {

        _test->insertItem(0,QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
