#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_bfalse=true;
    playform = new QWidget(this);
    playform->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    playform->setAttribute(Qt::WA_OpaquePaintEvent);
    playform->move(110,100);
    playform->setMinimumSize(320,240);
    //playform->hide();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(play()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(stop()));

    connect(ui->quiet,SIGNAL(clicked()),this,SLOT(quiet()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(next()));
    connect(ui->pre,SIGNAL(clicked()),this,SLOT(pre()));
    connect(ui->v_,SIGNAL(clicked()),this,SLOT(v_()));
    connect(ui->v2,SIGNAL(clicked()),this,SLOT(v2()));
    connect(ui->fast,SIGNAL(clicked()),this,SLOT(move()));

   // connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(back_messgae()));
   // timer=new QTimer(this);
   // connect(timer,SIGNAL(timeout()),this,SLOT(getTime()));
   // timer->start(1000);
    //退出 quit\n
    i=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::play()
{
    process=new QProcess(this);
    QStringList args;
    args << "-slave";
    args << "-quiet";//参数的格式 不正确造成
    //让窗口依附于
    args << "-wid" << QString::number(this->playform->winId());
    args <<"/home/wuqiankun/fire.mp3";
    process->setProcessChannelMode(QProcess::MergedChannels);
    process->start("/home/wuqiankun/mplayer",args);

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
void MainWindow::stop()
{
    process->write("pause\n");
}
void MainWindow::quiet()
{
    if(m_bfalse)
    {
        process->write("mute 1\n"); //关闭静音
        m_bfalse=false;
    }
    else
    {
        process->write("mute 0\n"); //开启静音
        m_bfalse=true;
    }

}

void MainWindow::next()
{
    ui->horizontalSlider->setValue(i);
    ui->horizontalSlider->setMaximum(100);
    ++i;
}

void MainWindow::pre()
{
}

void MainWindow::v_()
{
    process->write("volume -5\n");
}

void MainWindow::v2()
{
    process->write("volume +5\n");
}

void MainWindow::move()
{
    process->write("seek +10\n");
}

// void back_messgae()
//{
//     while(process->canReadLine())
//     {
//         QString message(process->readLine);
//         messaage.split("=");
//         //关键字 ANS_TIME_POSITION ANS_LENGTH

//     }
//}
//void getTime()
//{
//    process->write("get_time_pos\n");
//    process->write("get_time_length");
//}
