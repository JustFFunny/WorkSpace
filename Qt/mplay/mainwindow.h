#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTimer>

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
    bool m_bfalse;
    QTimer * m_timer;
public slots:
    void play();
    void stop();


   void quiet();
   void next();
   void pre();
   void v_();
   void v2();
   void move();
private:
    Ui::MainWindow *ui;
    int i;
};

#endif // MAINWINDOW_H
