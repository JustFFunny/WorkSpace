#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

enum ScreenMode{Portrait,Landscape};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
     virtual void resizeEvent ( QResizeEvent * event );

private:
    Ui::MainWindow *ui;
    enum ScreenMode scmode;
};

#endif // MAINWINDOW_H
