#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QToolButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton-> setAutoDefault(false);
    ui->pushButton->setText(tr("hello"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
