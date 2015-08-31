#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setMaximum(1000000);
    ui->progressBar->setValue(0);

    connect(ui->Button,SIGNAL(clicked()),this,SLOT(hello()));
    connect(ui->Button,SIGNAL(clicked()),this,SLOT(hello()));


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hello()
{
    qDebug()<<"hello";
    int i=0;
    while(i<1000000)
    {
        ui->progressBar->setValue(i);
        ++i;
    }
}
