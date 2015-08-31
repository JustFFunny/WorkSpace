#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setText(const QString &newText);

    QString text() const { return myText; }

    QSize sizeHint() const;


protected:

    void paintEvent(QPaintEvent *event);

    void timerEvent(QTimerEvent *event);

    void showEvent(QShowEvent *event);

    void hideEvent(QHideEvent *event);


private:

    QString myText;

    int offset;

    int myTimerId;

    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
