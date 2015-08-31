#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置字体Format


        QTextCursor cursor =  ui->textEdit->textCursor();
        QTextCharFormat textCharFormat;
        textCharFormat.setFontPointSize(30.0);
        QFont font;
        font.setBold(true);
        textCharFormat.setFont(font);
        cursor.setCharFormat(textCharFormat);

}

MainWindow::~MainWindow()
{
    delete ui;
}
