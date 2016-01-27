#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QLabel>
#include <QMovie>
#include <QPushButton>
#include <QDebug>
#include <QTime>
void sleep(unsigned int msec);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,900);
    QGraphicsScene* scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
   ui->graphicsView->resize(1200,900);
    //加载图片 静态的
    // QPixmap *pixmap = new QPixmap("/home/qiankun64/cat.gif");
    // scene->addPixmap(*pixmap );
    // ui->graphicsView->show();

    QLabel * _label=new QLabel();
    _label->setFixedSize(600,600);
    gwidget=(QGraphicsWidget *)(scene->addWidget(_label)) ;
    QMovie * _move=new QMovie("/home/qiankun64/cat.gif");
    _move->start();
    _label->setMovie(_move);
    ui->graphicsView->show();

    QPushButton * button=new QPushButton ;
    connect(button,SIGNAL(clicked()),this,SLOT(rotate()));
   button->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotate()
{
    qDebug()<<"enter";
    gwidget->setRotation(90);
    sleep(20);
    ui->graphicsView->update();
}

void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
