#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QProcess>
#include <QString>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    playform = new QWidget(this);
    playform->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    playform->setAttribute(Qt::WA_OpaquePaintEvent);
    playform->move(110,100);
    playform->setMinimumSize(320,240);
    //playform->hide();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(result()));
}

MainWindow::~MainWindow()
{
    //delete ui;
}
void MainWindow::result()
{
  process=new QProcess(this);
    QStringList args;
    args << "-slave";
    args << "-quiet";//参数的格式 不正确造成
    //让窗口依附于
    args << "-wid" << QString::number(this->playform->winId());
    args <<"/home/wuqiankun/fire.mp3";
    process->setProcessChannelMode(QProcess::MergedChannels);
    process->execute("/home/wuqiankun/mplayer",args);

//    QProcess *process = new QProcess(this);
//  //  process->start("mplayer –ac mad Unbelivable-23.avi");
//     QStringList args;
//     args << "-slave";
//     args << "-quiet";
//     args << "-wid" << QString::number(this->playform->winId());
//     args << "/home/wuqiankun/fire.mp3";
//     process->setProcessChannelMode(QProcess::MergedChannels);
//     process->start("/home/wuqiankun/mplayer",args);
}

