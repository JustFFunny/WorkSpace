#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
//样式表的修改
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qApp->setStyleSheet("QPushButton { color: white }");
   this->ui->pushButton->setStyleSheet( "QToolButton{min-height:20;\
                         border-style:solid;\
                         border-top-left-radius:2px;\
                         border-top-right-radius:2px;\
                       background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1 }" );


   //this->ui->pushButton->setStyleSheet("* { color: yellow}");

}

MainWindow::~MainWindow()
{
    delete ui;
}
