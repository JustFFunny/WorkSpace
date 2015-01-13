#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->->setIcon( QPixmap(":/audio/test/Audio/右侧_导入.png") );
//    ui->pushButton_in->setIconSize( QPixmap(":/audio/test/Audio/右侧_导入.png").size());
      ui->pushButton ->setFixedSize( QPixmap(":/audio/test/Audio/右侧_导入.png").size());
      ui->pushButton ->setFouceProterty(Qt::NoFouce);
}

MainWindow::~MainWindow()
{
    delete ui;
}
