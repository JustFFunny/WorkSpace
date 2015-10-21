#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget;
    QLabel * label=new QLabel("HELLO");
    QLineEdit * lineDit=new QLineEdit;
    QHBoxLayout * hboxlyaot=new QHBoxLayout;
    hboxlyaot->addWidget(label,3,Qt::AlignRight);
    hboxlyaot->addWidget(lineDit,0,Qt::AlignRight);
    ui->widget->setLayout(hboxlyaot);

}

MainWindow::~MainWindow()
{
    delete ui;
}
