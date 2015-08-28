#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include "citymodel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();


    //    QTableView view;
    //  QStandardItemModel model(4, 2);
    //  view.setModel(&model);
    //    view.show();


    QStringList cities;
    cities << "Arvika" << "Boden" << "Eskilstuna" << "Falun";

    CityModel cityModel;
    cityModel.setCities(cities);

    QTableView tableView;
    tableView.setModel(&cityModel);
    tableView.setAlternatingRowColors(true);
    tableView.setWindowTitle(QObject::tr("Cities"));
    tableView.show();
    
    return a.exec();
}
/*
 *int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        QStringList cities;
        cities << "Arvika" << "Boden" << "Eskilstuna" << "Falun";

        CityModel cityModel;
        cityModel.setCities(cities);

        QTableView tableView;
        tableView.setModel(&cityModel);
        tableView.setAlternatingRowColors(true);
        tableView.setWindowTitle(QObject::tr("Cities"));
        tableView.show();
        return a.exec();
}
 **/
