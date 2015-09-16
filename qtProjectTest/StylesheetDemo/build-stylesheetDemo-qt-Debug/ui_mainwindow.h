/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 14 09:39:56 2015
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
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QTextBrowser *textBrowser;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWebView *webView;
    QPushButton *ExitpushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(360, 640);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(110, 20));

        gridLayout_6->addWidget(lineEdit, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(317, 60, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_6->addItem(verticalSpacer, 1, 0, 1, 2);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_3->addWidget(radioButton_2, 0, 0, 1, 1);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_3->addWidget(radioButton, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_3->addWidget(checkBox_2, 2, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_3->addWidget(checkBox, 3, 0, 1, 1);


        gridLayout_6->addWidget(groupBox, 2, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_4->addWidget(textBrowser, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget = new QWidget(tab_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        webView = new QWebView(widget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("http://www.baidu.com/")));
        webView->setZoomFactor(1.5);

        gridLayout_2->addWidget(webView, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        ExitpushButton = new QPushButton(centralWidget);
        ExitpushButton->setObjectName(QString::fromUtf8("ExitpushButton"));

        gridLayout->addWidget(ExitpushButton, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "LineEdit", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        radioButton_2->setText(QApplication::translate("MainWindow", "RadioButton1", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "RadioButton2", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "CheckBox1", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "CheckBox2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial,Geneva,Helvetica,sans-serif'; font-size:12pt; font-weight:600; color:#000000;\">Qt Style Sheets</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman,serif'; color:#000000;\">Qt Style Sheets are a powerful mechanism that allows you to customize the appearance of widgets, in addition to what is already possible by subclassing\302\240</span><span style=\" font-family:'Times New Roman,serif';\">QStyle</span><"
                        "span style=\" font-family:'Times New Roman,serif'; color:#000000;\">. The concepts, terminology, and syntax of Qt Style Sheets are heavily inspired by HTML\302\240</span><span style=\" font-family:'Times New Roman,serif';\">Cascading Style Sheets (CSS)\302\240</span><span style=\" font-family:'Times New Roman,serif'; color:#000000;\">but adapted to the world of widgets.</span><span style=\" font-family:'MS Shell Dlg 2';\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman,serif'; color:#000000;\">Styles sheets are textual specifications that can be set on the whole application using\302\240</span><span style=\" font-family:'Times New Roman,serif';\">QApplication::setStyleSheet()</span><span style=\" font-family:'Times New Roman,serif'; color:#000000;\"> or on a specific widget (and its children) </span><span style=\" font-family:'Times New Roman,serif';\">using\302\240QWidget::se"
                        "tStyleSheet().</span><span style=\" font-family:'Times New Roman,serif'; color:#000000;\"> If several style sheets are set at different levels, Qt derives the effective style sheet from all of those that are set. This is called cascading.</span><span style=\" font-family:'MS Shell Dlg 2';\"> </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "WebPage", 0, QApplication::UnicodeUTF8));
        ExitpushButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
