//验证结论，信号是已经定义好的在QSignalMapper中保存，没有进行改变。

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_signalMapper=new QSignalMapper;
    connect(m_signalMapper, SIGNAL(mapped(int)),this, SLOT(showinteget(int)));


    connect(ui->pushButton,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    m_signalMapper->setMapping(ui->pushButton,int(1));

    connect(ui->pushButton_2,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    m_signalMapper->setMapping(ui->pushButton_2,int(2));

    connect(ui->pushButton_3,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    m_signalMapper->setMapping(ui->pushButton_3,int(3));

    connect(ui->pushButton_4,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    m_signalMapper->setMapping(ui->pushButton_4,int(4));

    connect(ui->pushButton_5,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    m_signalMapper->setMapping(ui->pushButton_5,int(5));


    //remove
    connect(ui->pushButton_remove,SIGNAL(clicked()),this,SLOT(remove()));
}

void MainWindow::remove()
{
    m_signalMapper->removeMappings(ui->pushButton_3);
    delete ui->pushButton_3;
}

void MainWindow::showinteget(int _intger)
{
    qDebug()<<_intger;
}

MainWindow::~MainWindow()
{
    delete ui;
}
