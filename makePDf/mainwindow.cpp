#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPushButton>
#include <QTextEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->push,SIGNAL(clicked()),this,SLOT(exportqq()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::exportqq()
{
 QTextEdit * _e=   ui->textEdit;
 qDebug()<<   _e->document()->toPlainText();

//文本形式PDF文件输出
 QPrinter  printer(QPrinter::HighResolution);
 printer.setOutputFormat(QPrinter::PdfFormat);
 printer.setOutputFileName("C:/Users/nfs/Downloads/wuqiankun.pdf");
 _e->document()->print(&printer);

}
