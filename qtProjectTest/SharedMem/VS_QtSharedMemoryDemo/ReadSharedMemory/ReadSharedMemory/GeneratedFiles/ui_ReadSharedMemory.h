/********************************************************************************
** Form generated from reading UI file 'ReadSharedMemory.ui'
**
** Created: Thu May 2 15:52:23 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READSHAREDMEMORY_H
#define UI_READSHAREDMEMORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReadSharedMemoryClass
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *showButton;
    QPushButton *detachBtn;
    QPushButton *attachBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ReadSharedMemoryClass)
    {
        if (ReadSharedMemoryClass->objectName().isEmpty())
            ReadSharedMemoryClass->setObjectName(QString::fromUtf8("ReadSharedMemoryClass"));
        ReadSharedMemoryClass->resize(600, 400);
        centralWidget = new QWidget(ReadSharedMemoryClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 30, 341, 151));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(90, 200, 341, 141));
        showButton = new QPushButton(centralWidget);
        showButton->setObjectName(QString::fromUtf8("showButton"));
        showButton->setGeometry(QRect(490, 50, 75, 41));
        detachBtn = new QPushButton(centralWidget);
        detachBtn->setObjectName(QString::fromUtf8("detachBtn"));
        detachBtn->setGeometry(QRect(490, 130, 75, 41));
        attachBtn = new QPushButton(centralWidget);
        attachBtn->setObjectName(QString::fromUtf8("attachBtn"));
        attachBtn->setGeometry(QRect(490, 200, 75, 41));
        ReadSharedMemoryClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ReadSharedMemoryClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        ReadSharedMemoryClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ReadSharedMemoryClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ReadSharedMemoryClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ReadSharedMemoryClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ReadSharedMemoryClass->setStatusBar(statusBar);

        retranslateUi(ReadSharedMemoryClass);

        QMetaObject::connectSlotsByName(ReadSharedMemoryClass);
    } // setupUi

    void retranslateUi(QMainWindow *ReadSharedMemoryClass)
    {
        ReadSharedMemoryClass->setWindowTitle(QApplication::translate("ReadSharedMemoryClass", "ReadSharedMemory", 0, QApplication::UnicodeUTF8));
        showButton->setText(QApplication::translate("ReadSharedMemoryClass", "PushButton", 0, QApplication::UnicodeUTF8));
        detachBtn->setText(QApplication::translate("ReadSharedMemoryClass", "detach", 0, QApplication::UnicodeUTF8));
        attachBtn->setText(QApplication::translate("ReadSharedMemoryClass", "attach", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReadSharedMemoryClass: public Ui_ReadSharedMemoryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READSHAREDMEMORY_H
