#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QSignalMapper;
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
    void remove();
    void showinteget(int _intger);
private:
    Ui::MainWindow *ui;
    QSignalMapper * m_signalMapper;
};

#endif // MAINWINDOW_H
