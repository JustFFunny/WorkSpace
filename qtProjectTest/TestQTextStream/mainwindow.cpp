#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDataStream>
#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString dir = QFileDialog::getSaveFileName(this, tr("Save FileName"),"./testSave.txt",
                                               "txt");
    if(dir.isEmpty())
        return;
    QFile f(dir);
    if(!f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "Open failed." << endl;
        QMessageBox::information(0,"权限提示信息","该路径没有写权限\n,请选择合适的路径.",QString::fromLocal8Bit("关闭"));
        return ;
    }

    QDataStream txtOutput(&f);
    QStringList _list;
    _list<<"1"<<"2"<<"3"<<"4";
    QProgressDialog * pd=new QProgressDialog("正在导出...","取消",0,_list.count(),this);


    // QProgressDialog ( const QString & labelText, const QString & cancelButtonText, int minimum, int maximum, QWidget * parent = 0, Qt::WindowFlags f = 0 )
    pd->setModal(true);
    pd->setWindowTitle("导出");
    pd->setMinimumDuration(1);
   // pd->show();
    pd->exec();
    //能保存
    for(int i=0;i<_list.count();++i)
    {
        txtOutput<<_list[i]<<"\n";
    }


    //    //迭代器
    //    QStringList::iterator _it=_list.begin();
    //    for(;_it != _list.end();_it++)
    //    {
    //        txtOutput<<*_it<<"\n";

    //    }
    f.close();
}
