/********************************************************************************
** Form generated from reading UI file 'WriteSharedMemory.ui'
**
** Created: Sat Apr 27 16:54:01 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITESHAREDMEMORY_H
#define UI_WRITESHAREDMEMORY_H

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

class Ui_WriteSharedMemoryClass
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *loadButton;
    QPushButton *initBtn;
    QPushButton *detachBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WriteSharedMemoryClass)
    {
        if (WriteSharedMemoryClass->objectName().isEmpty())
            WriteSharedMemoryClass->setObjectName(QString::fromUtf8("WriteSharedMemoryClass"));
        WriteSharedMemoryClass->resize(600, 400);
        centralWidget = new QWidget(WriteSharedMemoryClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(120, 10, 321, 151));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(120, 190, 321, 131));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(490, 52, 75, 41));
        initBtn = new QPushButton(centralWidget);
        initBtn->setObjectName(QString::fromUtf8("initBtn"));
        initBtn->setGeometry(QRect(490, 150, 75, 51));
        detachBtn = new QPushButton(centralWidget);
        detachBtn->setObjectName(QString::fromUtf8("detachBtn"));
        detachBtn->setGeometry(QRect(490, 230, 75, 51));
        WriteSharedMemoryClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WriteSharedMemoryClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        WriteSharedMemoryClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WriteSharedMemoryClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WriteSharedMemoryClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WriteSharedMemoryClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WriteSharedMemoryClass->setStatusBar(statusBar);

        retranslateUi(WriteSharedMemoryClass);

        QMetaObject::connectSlotsByName(WriteSharedMemoryClass);
    } // setupUi

    void retranslateUi(QMainWindow *WriteSharedMemoryClass)
    {
        WriteSharedMemoryClass->setWindowTitle(QApplication::translate("WriteSharedMemoryClass", "WriteSharedMemory", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("WriteSharedMemoryClass", "PushButton", 0, QApplication::UnicodeUTF8));
        initBtn->setText(QApplication::translate("WriteSharedMemoryClass", "init", 0, QApplication::UnicodeUTF8));
        detachBtn->setText(QApplication::translate("WriteSharedMemoryClass", "detach", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WriteSharedMemoryClass: public Ui_WriteSharedMemoryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITESHAREDMEMORY_H
