#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QWidget * playform;
    QProcess * process;
public slots:
    void result();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
