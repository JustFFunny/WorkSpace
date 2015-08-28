#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QVariant>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setOrganizationDomain("mysoft.com");
    QCoreApplication::setApplicationName("Star Runner");
    QSettings setting;
    QString str = setting.value("Test").toString();
    qDebug()<<str<<"\n";
    setting.setValue("Test","wuqiankun");
    QString str2 = setting.value("TestNoExist",80).toString();
    qDebug()<<str2<<"\n";
    setting.beginGroup("group");
    setting.setValue("part1",10);
    setting.endGroup();
    setting.beginGroup("group");
    qDebug() << setting.value("part1").toString();
    setting.endGroup();
}

MainWindow::~MainWindow()
{
    QSettings setting ;
    setting.setValue("Test","Testwuqiankun");
    delete ui;
}
