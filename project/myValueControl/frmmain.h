#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>

#include "mygauge1.h"
#include "mygauge2.h"
#include "mygauge3.h"
#include "mygauge4.h"
#include "mygauge5.h"
#include "mygauge6.h"
#include "mygauge7.h"
#include "myprogressbar.h"
#include "mybattery.h"
#include "mycoolbar.h"
#include "myindicator.h"

namespace Ui {
    class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

private:
    Ui::frmMain *ui;
    QVBoxLayout *mainLayout;
    QHBoxLayout *layout1;

    myGauge1 *gauge1;
    myGauge2 *gauge2;
    myGauge3 *gauge31;
    myGauge3 *gauge32;
    myGauge3 *gauge33;
    myGauge4 *gauge41;
    myGauge4 *gauge42;
    myGauge4 *gauge43;
    myGauge5 *gauge5;
    myGauge6 *gauge61;
    myGauge6 *gauge62;
    myGauge6 *gauge63;
    myGauge7 *gauge71;
    myGauge7 *gauge72;
    myGauge7 *gauge73;

    myProgressBar *myprogressbar1;
    myProgressBar *myprogressbar2;
    myProgressBar *myprogressbar3;

    myBattery *mybattery1;
    myBattery *mybattery2;
    myBattery *mybattery3;
    myBattery *mybattery4;

    myCoolBar *mycoolbar;

    myIndicator *myindicator1;
    myIndicator *myindicator2;
    myIndicator *myindicator3;
    myIndicator *myindicator4;
    myIndicator *myindicator5;

    QTimer *updateTimer1;
    QTimer *updateTimer2;
    QTimer *updateTimer4;
    QTimer *updateTimer5;
    QTimer *updateTimer6;
    QTimer *updateTimer7;
    QTimer *updateTimer8;

    QTimer *updateTimer10;

private slots:
    void on_btnIndicator_clicked();
    void on_btnCoolBar_clicked();
    void on_btnBattery_clicked();
    void on_btnGauge7_clicked();
    void on_btnProgressBar_clicked();
    void on_btnGauge6_clicked();
    void on_btnGauge5_clicked();
    void on_btnGauge4_clicked();
    void on_btnGauge3_clicked();
    void on_btnGauge2_clicked();
    void on_btnGauge1_clicked();

    void ChangeVisible(bool b);
    void UpdateData1();
    void UpdateData2();
    void UpdateData3(qreal value);
    void UpdateData4();
    void UpdateData5();
    void UpdateData6();
    void UpdateData7();
    void UpdateData8();
    void UpdateData9(int value);
    void UpdateData10();
};

#endif // FRMMAIN_H
