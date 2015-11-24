#include "testobject.h"
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QKeySequence>
TestObject::TestObject(QObject *parent) :
    QObject(parent)
{
}

void TestObject::output(const QPoint & pos)
{

    //_action=_menu->addAction(QIcon(),tr("&OS"),this,SLOT(TestshortCut()),QKeySequence(tr("Ctrl+O")));
    //    _action=_menu->addAction(QIcon(),tr("&OS"),this,SLOT(TestshortCut()));
    //    _action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));


    qDebug()<<"test";
    QMenu *_menu=new QMenu();
    _menu->show();
    QAction * _action =new QAction(tr("&Test"),this);

    _menu->addAction(_action);
    //_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    connect(_action,SIGNAL(triggered()),this,SLOT(TestshortCut()));
    qDebug()<<_action->shortcut().toString();
}

void TestObject::TestshortCut()
{
    qDebug()<<"Enter";
}


