#include "mainwindow.h"
#include <QApplication>

#include <QtGui>
#include <QtGui/QApplication>
#include <QtGui/QAbstractItemView>
#include <QAbstractListModel>
#include <QStringList>
#include <QListView>
#include <QStringListModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setText(QObject::tr("How long it lasted was impossible to say ++ "));
     w.show();
    
    return a.exec();
}
