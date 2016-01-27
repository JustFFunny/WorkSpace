#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
   void  rotate();

private:
    Ui::MainWindow *ui;
    QGraphicsWidget * gwidget;
};

#endif // MAINWINDOW_H
