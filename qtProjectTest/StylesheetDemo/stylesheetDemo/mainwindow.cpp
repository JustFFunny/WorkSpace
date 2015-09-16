#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebKit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QNetworkProxyFactory::setUseSystemConfiguration(true);

    ui->setupUi(this);
    scmode = Portrait;


    ui->textBrowser->setStyleSheet("\
            color: rgb(127, 0, 63);\
            background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, \
                                stop: 0 rgba(255, 0, 0, 30%), stop: 0.2 rgba(255, 128, 0, 30%), stop: 0.4 rgba(255, 255, 0, 30%), \
                                stop: 0.6 rgba(0, 255, 0, 30%), stop: 0.8 rgba(0, 128, 255, 30%), stop: 1 rgba(128, 0, 255, 30%)); \
            selection-color: white;\
            selection-background-color: rgb(191, 31, 127);\
            border: 2px groove gray;\
            border-radius: 30px;\
            padding: 2px 4px;");



    ui->webView->setStyleSheet("border: 1px groove gray; border-radius: 5px; background-color: rgba(255, 193, 245, 0%); ");


    ui->tabWidget->setStyleSheet("\
                                 QTabBar::tab {\
                                        color: rgb(84,2,119);\
                                        background-image: url(:/pics/wood.jpg); \
                                        border: 2px solid rgb(68,66,64);\
                                        border-bottom-color: rgb(68,66,64); \
                                        border-top-left-radius: 20px;\
                                        border-top-right-radius: 20px;\
                                        max-height: 21px;\
                                        min-width: 8ex;\
                                        padding: 2px;\
                                        } \
                                  QTabWidget::tab-bar {\
                                        alignment: center;\
                                        } \
                                  QTabBar::tab:!selected {\
                                        margin-top: 5px; \
                                        }\
                                  QTabBar::tab:selected {\
                                        color: rgb(255,0,128); \
                                        }\
                                  ");

    ui->ExitpushButton->setStyleSheet("\
                                      QPushButton {\
                                            color: white;\
                                            border-image: url(:/pics/button.png);\
                                            border-width: 12px;\
                                            padding: -12px 0px;\
                                            min-height: 25px;\
                                            min-width: 60px;\
                                            }\
                                      QPushButton:pressed {\
                                            color: lightgray;\
                                            border-image: url(:/pics/button-pressed.png); \
                                            padding-top: -10px;\
                                            padding-bottom: -16px;\
                                            }\
                                      ");


    ui->checkBox->setFocusPolicy(Qt::NoFocus);
    ui->checkBox_2->setFocusPolicy(Qt::NoFocus);
    ui->radioButton->setFocusPolicy(Qt::NoFocus);
    ui->radioButton_2->setFocusPolicy(Qt::NoFocus);

    QFile file(":/qss/stylesheetDemo.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    ui->tab->setStyleSheet(stylesheet);


    connect(ui->ExitpushButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent ( QResizeEvent * event )
{
    enum ScreenMode currentscreenMode;
    if(size().height()> size().width())
        currentscreenMode = Portrait;
    else
        currentscreenMode = Landscape;

    if (currentscreenMode!=scmode)
    {
        scmode = currentscreenMode;
        switch(scmode)
        {
        case Portrait:
            this->setStyleSheet("QMainWindow{ background-image: url(:/pics/bgPortrait.jpg)}");
            break;
        case Landscape:
            this->setStyleSheet("QMainWindow{ background-image: url(:/pics/bgLandscape.jpg)}");
            break;
        default:
            break;
        }
    }
}
