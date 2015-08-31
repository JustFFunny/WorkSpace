#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "faceform.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
  //  void disTime();

  //  void on_pushButton_2_clicked();
   // void addFace(QString text);

private:
    Ui::MainWindow *ui;

    void sendMsgShow(QString msg);
  //  void revMsgShow(QString msg);

    QTimer *m_timer;
    bool disFlag;
    faceForm *m_faceForm;
    bool faceFormFlag;

};

#endif // MAINWINDOW_H
