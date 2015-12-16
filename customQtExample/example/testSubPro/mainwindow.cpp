#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(progress()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::progress()
{
    ui->progressBar->setMaximum(1000);
    for(int i=0;i<=1001;++i)
    {
        ui->progressBar->setValue(i);
    }
}
