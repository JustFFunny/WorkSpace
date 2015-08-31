#include "frmmain.h"
#include "ui_frmmain.h"

frmMain::frmMain(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::frmMain)
{
    ui->setupUi(this);

    mainLayout=new QVBoxLayout();
    layout1=new QHBoxLayout();

    gauge1=new myGauge1(ui->fm);
    gauge2=new myGauge2(ui->fm);
    gauge2->setAnimating(true);

    gauge31=new myGauge3(ui->fm);
    gauge31->setRange(0,50);
    connect(gauge31,SIGNAL(valueChanged(qreal)),this,SLOT(UpdateData3(qreal)));

    gauge32=new myGauge3(ui->fm);
    gauge32->setRange(0,100);
    connect(gauge32,SIGNAL(valueChanged(qreal)),this,SLOT(UpdateData3(qreal)));

    gauge33=new myGauge3(ui->fm);
    gauge33->setRange(30,120);
    connect(gauge33,SIGNAL(valueChanged(qreal)),this,SLOT(UpdateData3(qreal)));

    gauge41=new myGauge4(ui->fm);
    gauge41->setValue(50);
    gauge42=new myGauge4(ui->fm);
    gauge42->setValue(30);
    gauge43=new myGauge4(ui->fm);
    gauge43->setValue(100);

    gauge5=new myGauge5(ui->fm);

    gauge61=new myGauge6(ui->fm);
    gauge61->setAnimating(true);
    gauge61->SetGraphColor(Qt::green);
    gauge62=new myGauge6(ui->fm);
    gauge62->setAnimating(true);
    gauge62->SetGraphColor(Qt::blue);
    gauge63=new myGauge6(ui->fm);
    gauge63->setAnimating(true);
    gauge63->SetGraphColor(Qt::red);

    gauge71=new myGauge7(ui->fm);
    gauge71->SetGraphColor(Qt::red);
    gauge72=new myGauge7(ui->fm);
    gauge72->SetGraphColor(Qt::green);
    gauge73=new myGauge7(ui->fm);
    gauge73->SetGraphColor(Qt::blue);

    myprogressbar1=new myProgressBar(ui->fm);
    myprogressbar1->setInterval(20);
    myprogressbar2=new myProgressBar(ui->fm);
    myprogressbar2->setInterval(60);
    myprogressbar3=new myProgressBar(ui->fm);
    myprogressbar3->setInterval(150);

    mybattery1=new myBattery(ui->fm);
    mybattery2=new myBattery(ui->fm);
    mybattery3=new myBattery(ui->fm);
    mybattery4=new myBattery(ui->fm);

    mycoolbar=new myCoolBar(ui->fm);
    mycoolbar->setRange(0,100);
    mycoolbar->setValue(60);
    connect(mycoolbar,SIGNAL(valueChanged(int)),this,SLOT(UpdateData9(int)));

    myindicator1=new myIndicator(ui->fm);
    myindicator1->SetForeColor(Qt::green);
    myindicator2=new myIndicator(ui->fm);
    myindicator2->SetForeColor(Qt::red);
    myindicator3=new myIndicator(ui->fm);
    myindicator3->SetForeColor(Qt::black);
    myindicator4=new myIndicator(ui->fm);
    myindicator4->SetForeColor(Qt::blue);
    myindicator5=new myIndicator(ui->fm);
    myindicator5->SetForeColor(Qt::cyan);

    mainLayout->addWidget(gauge1);
    mainLayout->addWidget(gauge2);
    mainLayout->addWidget(gauge31);
    mainLayout->addWidget(gauge32);
    mainLayout->addWidget(gauge33);
    mainLayout->addWidget(gauge41);
    mainLayout->addWidget(gauge42);
    mainLayout->addWidget(gauge43);
    mainLayout->addWidget(gauge5);    

    mainLayout->addWidget(myprogressbar1);
    mainLayout->addWidget(myprogressbar2);
    mainLayout->addWidget(myprogressbar3);
    mainLayout->addWidget(mybattery1);
    mainLayout->addWidget(mybattery2);
    mainLayout->addWidget(mybattery3);
    mainLayout->addWidget(mybattery4);
    mainLayout->addWidget(mycoolbar);

    mainLayout->addLayout(layout1);

    layout1->addWidget(gauge61);
    layout1->addWidget(gauge62);
    layout1->addWidget(gauge63);

    layout1->addWidget(gauge71);
    layout1->addWidget(gauge72);
    layout1->addWidget(gauge73);

    layout1->addWidget(myindicator1);
    layout1->addWidget(myindicator2);
    layout1->addWidget(myindicator3);
    layout1->addWidget(myindicator4);
    layout1->addWidget(myindicator5);

    ui->fm->setLayout(mainLayout);

    updateTimer1=new QTimer(this);
    updateTimer1->setInterval(3000);
    connect(updateTimer1,SIGNAL(timeout()),this,SLOT(UpdateData1()));

    updateTimer2=new QTimer(this);
    updateTimer2->setInterval(3000);
    connect(updateTimer2,SIGNAL(timeout()),this,SLOT(UpdateData2()));

    updateTimer4=new QTimer(this);
    updateTimer4->setInterval(3000);
    connect(updateTimer4,SIGNAL(timeout()),this,SLOT(UpdateData4()));

    updateTimer5=new QTimer(this);
    updateTimer5->setInterval(3000);
    connect(updateTimer5,SIGNAL(timeout()),this,SLOT(UpdateData5()));

    updateTimer6=new QTimer(this);
    updateTimer6->setInterval(3000);
    connect(updateTimer6,SIGNAL(timeout()),this,SLOT(UpdateData6()));

    updateTimer7=new QTimer(this);
    updateTimer7->setInterval(3000);
    connect(updateTimer7,SIGNAL(timeout()),this,SLOT(UpdateData7()));

    updateTimer8=new QTimer(this);
    updateTimer8->setInterval(3000);
    connect(updateTimer8,SIGNAL(timeout()),this,SLOT(UpdateData8()));

    updateTimer10=new QTimer(this);
    updateTimer10->setInterval(3000);
    connect(updateTimer10,SIGNAL(timeout()),this,SLOT(UpdateData10()));

    this->ChangeVisible(false);
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::ChangeVisible(bool b)
{
    gauge1->setVisible(b);

    gauge2->setVisible(b);

    gauge31->setVisible(b);
    gauge32->setVisible(b);
    gauge33->setVisible(b);

    gauge41->setVisible(b);
    gauge42->setVisible(b);
    gauge43->setVisible(b);

    gauge5->setVisible(b);

    gauge61->setVisible(b);
    gauge62->setVisible(b);
    gauge63->setVisible(b);

    gauge71->setVisible(b);
    gauge72->setVisible(b);
    gauge73->setVisible(b);

    myprogressbar1->setVisible(b);
    myprogressbar2->setVisible(b);
    myprogressbar3->setVisible(b);

    mybattery1->setVisible(b);
    mybattery2->setVisible(b);
    mybattery3->setVisible(b);
    mybattery4->setVisible(b);
    mycoolbar->setVisible(b);

    myindicator1->setVisible(b);
    myindicator2->setVisible(b);
    myindicator3->setVisible(b);
    myindicator4->setVisible(b);
    myindicator5->setVisible(b);

    updateTimer10->stop();
    updateTimer8->stop();
    updateTimer7->stop();
    updateTimer6->stop();
    updateTimer5->stop();
    updateTimer4->stop();
    updateTimer2->stop();
    updateTimer1->stop();
}

void frmMain::on_btnGauge1_clicked()
{
    this->ChangeVisible(false);
    gauge1->setVisible(true);
    updateTimer1->start();
}

void frmMain::UpdateData1()
{
    int value=qrand()%100;
    gauge1->setValue(value);
    ui->labValue->setText(tr("当前值:%1").arg(value));
}

void frmMain::on_btnGauge2_clicked()
{
    this->ChangeVisible(false);
    gauge2->setVisible(true);    
    updateTimer2->start();
}

void frmMain::UpdateData2()
{
    int value=qrand()%100;
    gauge2->setValue(value);
    ui->labValue->setText(tr("当前值:%1").arg(value));
}

void frmMain::on_btnGauge3_clicked()
{
    this->ChangeVisible(false);
    gauge31->setVisible(true);
    gauge32->setVisible(true);
    gauge33->setVisible(true);
}

void frmMain::UpdateData3(qreal value)
{
    ui->labValue->setText(tr("当前值:%1").arg(value));
}

void frmMain::on_btnGauge4_clicked()
{
    this->ChangeVisible(false);
    gauge41->setVisible(true);
    gauge42->setVisible(true);
    gauge43->setVisible(true);
    updateTimer4->start();
}

void frmMain::UpdateData4()
{
    int value1=qrand()%100;
    int value2=qrand()%100;
    int value3=qrand()%100;
    gauge41->setValue(value1);
    gauge42->setValue(value2);
    gauge43->setValue(value3);
    ui->labValue->setText(tr("当前值:%1 %2 %3").arg(value1).arg(value2).arg(value3));
}

void frmMain::on_btnGauge5_clicked()
{
    this->ChangeVisible(false);
    gauge5->setVisible(true);
    updateTimer5->start();
}

void frmMain::UpdateData5()
{
    int value=qrand()%100;
    gauge5->setValue(value);
    ui->labValue->setText(tr("当前值:%1").arg(value));
}

void frmMain::on_btnGauge6_clicked()
{
    this->ChangeVisible(false);
    gauge61->setVisible(true);
    gauge62->setVisible(true);
    gauge63->setVisible(true);
    updateTimer6->start();
}

void frmMain::UpdateData6()
{
    int value1=qrand()%100;
    int value2=qrand()%100;
    int value3=qrand()%100;
    gauge61->setValue(value1);
    gauge62->setValue(value2);
    gauge63->setValue(value3);
    ui->labValue->setText(tr("当前值:%1 %2 %3").arg(value1).arg(value2).arg(value3));
}

void frmMain::on_btnGauge7_clicked()
{
    this->ChangeVisible(false);
    gauge71->setVisible(true);
    gauge72->setVisible(true);
    gauge73->setVisible(true);
    updateTimer7->start();
}

void frmMain::UpdateData7()
{
    int value1=qrand()%100;
    int value2=qrand()%100;
    int value3=qrand()%100;
    gauge71->setValue(value1);
    gauge72->setValue(value2);
    gauge73->setValue(value3);
    ui->labValue->setText(tr("当前值:%1 %2 %3").arg(value1).arg(value2).arg(value3));
}

void frmMain::on_btnProgressBar_clicked()
{
    this->ChangeVisible(false);
    myprogressbar1->setVisible(true);
    myprogressbar2->setVisible(true);
    myprogressbar3->setVisible(true);
}


void frmMain::on_btnBattery_clicked()
{
    this->ChangeVisible(false);
    mybattery1->setVisible(true);
    mybattery2->setVisible(true);
    mybattery3->setVisible(true);
    mybattery4->setVisible(true);
    updateTimer8->start();
}

void frmMain::UpdateData8()
{
    int value1=qrand()%100;
    int value2=qrand()%100;
    int value3=qrand()%100;
    int value4=qrand()%100;
    mybattery1->setValue(value1);
    mybattery2->setValue(value2);
    mybattery3->setValue(value3);
    mybattery4->setValue(value4);
    ui->labValue->setText(tr("当前值:%1 %2 %3 %4").arg(value1).arg(value2).arg(value3).arg(value4));
}

void frmMain::on_btnCoolBar_clicked()
{
    this->ChangeVisible(false);
    mycoolbar->setVisible(true);
}

void frmMain::UpdateData9(int value)
{
    ui->labValue->setText(tr("当前值:%1").arg(value));
}

void frmMain::on_btnIndicator_clicked()
{
    this->ChangeVisible(false);
    myindicator1->setVisible(true);
    myindicator2->setVisible(true);
    myindicator3->setVisible(true);
    myindicator4->setVisible(true);
    myindicator5->setVisible(true);
    updateTimer10->start();
}

void frmMain::UpdateData10()
{
    int value1=qrand()%100;
    int value2=qrand()%100;
    int value3=qrand()%100;
    int value4=qrand()%100;
    int value5=qrand()%100;
    myindicator1->setValue(value1);
    myindicator2->setValue(value2);
    myindicator3->setValue(value3);
    myindicator4->setValue(value4);
    myindicator5->setValue(value5);

    ui->labValue->setText(tr("当前值:%1 %2 %3 %4 %5").arg(value1).arg(value2).arg(value3).arg(value4).arg(value5));
}
