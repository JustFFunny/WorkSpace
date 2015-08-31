#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_edit=new QTextEdit;
    m_edit->installEventFilter(this);
    setCentralWidget(m_edit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::eventFilter(QObject * obj, QEvent * event)
{
    if(obj==m_edit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << "Ate key press" << keyEvent->key();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);

    }

}
