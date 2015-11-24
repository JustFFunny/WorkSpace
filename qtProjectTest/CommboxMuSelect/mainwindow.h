#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListView>
#include <QTableView>

#include "contactmodel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void initListWidget();
    void stateChangedslot(int);

    void initMV();
private:
    QListWidget * m_listWidget;
    QLineEdit  * m_lineEdit;
    QPushButton * m_pushButton;
    Contactmodel * m_contactModel;
    QListView * m_listView;

    QTableView* m_tableView;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
