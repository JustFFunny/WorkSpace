#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtWebKit>
#include <QTime>
#include <QDebug>
#include <QScrollBar>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    QFile source(":/style.html");
    source.open(QIODevice::ReadOnly);
   ui->webView->setHtml(QString::fromUtf8(source.readAll().constData()));


    source.close();
/*
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(disTime()));
   m_timer->start(6000);
   disFlag = false;
   faceFormFlag = false;
    connect(this, SIGNAL(toBottom()), this, SLOT(toViewBottom()));
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sendMsgShow(ui->lineEdit->text());
/*    if (ui->lineEdit->text() == QString("你好"))
        revMsgShow(QString("您好,有什么可以帮助您！"));
    else if (ui->lineEdit->text() == QString("现在几点")) {

        revMsgShow(QString("现在为北京时间：%1").arg(QTime::currentTime().toString("hh:mm:ss")));
    }
*/
}


void MainWindow::sendMsgShow(QString msg)
{
    QString html = QString("");

//    if (disFlag) {
 //    QString time = QString("<center>%1</center>").arg(QTime::currentTime().toString("-- hh:mm --"));
 //    html.append(QString("document.getElementById(\"content\").insertAdjacentHTML(\"beforeEnd\",\"%1<div style='overflow:hidden;'><p class='triangle-right right'>%2</p></div>\")").arg(time).arg(msg));
 //   }
 //   else {
    //   msg.replace( "[smail.png]", "<img src=qrc:/smail.png alt=表情 align=center border=0>" );
    //    msg.replace( "[ali.gif]", "<img src=qrc:/ali.gif alt=表情 align=center border=0>" );
      //    msg.append("<img src=file:///E:/qt/test/smail.png alt=表情 with=24 height=24 align=center border=0>");
    html.append(QString("document.getElementById(\"content\").insertAdjacentHTML(\"beforeEnd\",\"<div style='overflow:hidden;'><p class='triangle-right right'>%1</p></div>\")").arg(msg));
 //   }

    ui->webView->page()->mainFrame()->evaluateJavaScript(html);
   // disFlag = false;
   // m_timer->start(30000);
}
/*
void MainWindow::revMsgShow(QString msg)
{
    QString html = QString("document.getElementById(\"content\").insertAdjacentHTML(\"beforeEnd\",\"<div style='overflow:hidden;'><p class='triangle-left left'>%1</p></div>\")").arg(msg);
    ui->webView->page()->mainFrame()->evaluateJavaScript(html);
}

void MainWindow::disTime()
{
    disFlag = true;
    m_timer->stop();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(faceFormFlag){
        disconnect(m_faceForm, SIGNAL(faceClicked(QString)), this, SLOT(addFace(QString)));
        m_faceForm->deleteLater();
        faceFormFlag = false;
        ui->verticalLayout->setStretch(0,10);
        return;
    }
    m_faceForm = new faceForm();
    faceFormFlag = true;
    ui->verticalLayout->insertWidget(1, m_faceForm, 4);
    ui->verticalLayout->setStretch(0, 6);
     connect(m_faceForm, SIGNAL(faceClicked(QString)), this, SLOT(addFace(QString)));

}


void MainWindow::addFace(QString text)
{
    ui->lineEdit->setText(ui->lineEdit->text()+text);
    ui->lineEdit->setFocus();
    disconnect(m_faceForm, SIGNAL(faceClicked(QString)), this, SLOT(addFace(QString)));
    m_faceForm->deleteLater();
    faceFormFlag = false;
    ui->verticalLayout->setStretch(0,10);}*/
