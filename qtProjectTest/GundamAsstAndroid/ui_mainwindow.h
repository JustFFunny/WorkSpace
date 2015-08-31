/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUsb;
    QAction *actionWifi;
    QAction *actionO_programie;
    QAction *actionPolski;
    QAction *actionAdbReboot;
    QAction *actionAdbRebootBootloader;
    QAction *actionAdbRebootRecovery;
    QAction *actionFastbootReboot;
    QAction *actionFastbootRebootBootloader;
    QAction *actionFastbootPowerOff;
    QAction *actionAdbPowerOff;
    QAction *actionCheck_for_updates;
    QAction *actionEnter_register_key;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageDisconnected;
    QWidget *layoutWidget1;
    QGridLayout *layoutDisconnected;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuTryb;
    QMenu *menu_Pomoc;
    QMenu *menu;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(764, 594);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(false);
        actionUsb = new QAction(MainWindow);
        actionUsb->setObjectName(QString::fromUtf8("actionUsb"));
        actionWifi = new QAction(MainWindow);
        actionWifi->setObjectName(QString::fromUtf8("actionWifi"));
        actionWifi->setVisible(true);
        actionO_programie = new QAction(MainWindow);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        actionO_programie->setAutoRepeat(false);
        actionO_programie->setVisible(false);
        actionPolski = new QAction(MainWindow);
        actionPolski->setObjectName(QString::fromUtf8("actionPolski"));
        actionAdbReboot = new QAction(MainWindow);
        actionAdbReboot->setObjectName(QString::fromUtf8("actionAdbReboot"));
        actionAdbReboot->setEnabled(true);
        actionAdbRebootBootloader = new QAction(MainWindow);
        actionAdbRebootBootloader->setObjectName(QString::fromUtf8("actionAdbRebootBootloader"));
        actionAdbRebootBootloader->setVisible(true);
        actionAdbRebootRecovery = new QAction(MainWindow);
        actionAdbRebootRecovery->setObjectName(QString::fromUtf8("actionAdbRebootRecovery"));
        actionAdbRebootRecovery->setVisible(true);
        actionFastbootReboot = new QAction(MainWindow);
        actionFastbootReboot->setObjectName(QString::fromUtf8("actionFastbootReboot"));
        actionFastbootReboot->setVisible(true);
        actionFastbootRebootBootloader = new QAction(MainWindow);
        actionFastbootRebootBootloader->setObjectName(QString::fromUtf8("actionFastbootRebootBootloader"));
        actionFastbootRebootBootloader->setVisible(true);
        actionFastbootPowerOff = new QAction(MainWindow);
        actionFastbootPowerOff->setObjectName(QString::fromUtf8("actionFastbootPowerOff"));
        actionFastbootPowerOff->setEnabled(true);
        actionFastbootPowerOff->setVisible(true);
        actionAdbPowerOff = new QAction(MainWindow);
        actionAdbPowerOff->setObjectName(QString::fromUtf8("actionAdbPowerOff"));
        actionAdbPowerOff->setVisible(true);
        actionCheck_for_updates = new QAction(MainWindow);
        actionCheck_for_updates->setObjectName(QString::fromUtf8("actionCheck_for_updates"));
        actionCheck_for_updates->setAutoRepeat(false);
        actionCheck_for_updates->setVisible(false);
        actionEnter_register_key = new QAction(MainWindow);
        actionEnter_register_key->setObjectName(QString::fromUtf8("actionEnter_register_key"));
        actionEnter_register_key->setAutoRepeat(false);
        actionEnter_register_key->setVisible(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 741, 541));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 5, 0);
        stackedWidget = new QStackedWidget(layoutWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        pageDisconnected = new QWidget();
        pageDisconnected->setObjectName(QString::fromUtf8("pageDisconnected"));
        layoutWidget1 = new QWidget(pageDisconnected);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 681, 501));
        layoutDisconnected = new QGridLayout(layoutWidget1);
        layoutDisconnected->setSpacing(6);
        layoutDisconnected->setContentsMargins(11, 11, 11, 11);
        layoutDisconnected->setObjectName(QString::fromUtf8("layoutDisconnected"));
        layoutDisconnected->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutDisconnected->addItem(verticalSpacer_6, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        layoutDisconnected->addWidget(label_3, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutDisconnected->addItem(verticalSpacer_5, 4, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutDisconnected->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutDisconnected->addItem(horizontalSpacer_7, 2, 0, 1, 1);

        progressBar = new QProgressBar(layoutWidget1);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(0);
        progressBar->setValue(0);

        layoutDisconnected->addWidget(progressBar, 2, 1, 1, 1);

        stackedWidget->addWidget(pageDisconnected);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 764, 28));
        menuTryb = new QMenu(menuBar);
        menuTryb->setObjectName(QString::fromUtf8("menuTryb"));
        menu_Pomoc = new QMenu(menuBar);
        menu_Pomoc->setObjectName(QString::fromUtf8("menu_Pomoc"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setWindowTitle(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuTryb->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_Pomoc->menuAction());
        menuTryb->addAction(actionUsb);
        menuTryb->addAction(actionWifi);
        menu_Pomoc->addAction(actionO_programie);
        menu_Pomoc->addAction(actionCheck_for_updates);
        menu_Pomoc->addAction(actionEnter_register_key);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gundam - Your android manager", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionUsb->setText(QApplication::translate("MainWindow", "usb", 0, QApplication::UnicodeUTF8));
        actionWifi->setText(QApplication::translate("MainWindow", "wifi", 0, QApplication::UnicodeUTF8));
        actionO_programie->setText(QApplication::translate("MainWindow", "about", 0, QApplication::UnicodeUTF8));
        actionPolski->setText(QApplication::translate("MainWindow", "polski", 0, QApplication::UnicodeUTF8));
        actionAdbReboot->setText(QApplication::translate("MainWindow", "Reboot", 0, QApplication::UnicodeUTF8));
        actionAdbRebootBootloader->setText(QApplication::translate("MainWindow", "Reboot bootloader", 0, QApplication::UnicodeUTF8));
        actionAdbRebootRecovery->setText(QApplication::translate("MainWindow", "Reboot recovery", 0, QApplication::UnicodeUTF8));
        actionFastbootReboot->setText(QApplication::translate("MainWindow", "Reboot", 0, QApplication::UnicodeUTF8));
        actionFastbootRebootBootloader->setText(QApplication::translate("MainWindow", "Reboot bootloader", 0, QApplication::UnicodeUTF8));
        actionFastbootPowerOff->setText(QApplication::translate("MainWindow", "Power off", 0, QApplication::UnicodeUTF8));
        actionAdbPowerOff->setText(QApplication::translate("MainWindow", "Power off", 0, QApplication::UnicodeUTF8));
        actionCheck_for_updates->setText(QApplication::translate("MainWindow", "check for updates", 0, QApplication::UnicodeUTF8));
        actionEnter_register_key->setText(QApplication::translate("MainWindow", "enter register key", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "CONNECT YOUR PHONE", 0, QApplication::UnicodeUTF8));
        menuTryb->setTitle(QApplication::translate("MainWindow", "&Connection", 0, QApplication::UnicodeUTF8));
        menu_Pomoc->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "&Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
