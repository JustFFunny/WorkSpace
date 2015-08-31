/********************************************************************************
** Form generated from reading UI file 'contactdialog.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTDIALOG_H
#define UI_CONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactDialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLineEdit *lineEdit_number;
    QPushButton *pushButton_quit;
    QPushButton *pushButton_save;

    void setupUi(QDialog *ContactDialog)
    {
        if (ContactDialog->objectName().isEmpty())
            ContactDialog->setObjectName(QString::fromUtf8("ContactDialog"));
        ContactDialog->resize(295, 148);
        widget = new QWidget(ContactDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 281, 131));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_number = new QLineEdit(widget);
        lineEdit_number->setObjectName(QString::fromUtf8("lineEdit_number"));

        gridLayout->addWidget(lineEdit_number, 1, 1, 1, 2);

        pushButton_quit = new QPushButton(widget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));

        gridLayout->addWidget(pushButton_quit, 2, 2, 1, 1);

        pushButton_save = new QPushButton(widget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        gridLayout->addWidget(pushButton_save, 2, 0, 1, 1);


        retranslateUi(ContactDialog);

        QMetaObject::connectSlotsByName(ContactDialog);
    } // setupUi

    void retranslateUi(QDialog *ContactDialog)
    {
        ContactDialog->setWindowTitle(QApplication::translate("ContactDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ContactDialog", "Name     :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ContactDialog", "Number:", 0, QApplication::UnicodeUTF8));
        pushButton_quit->setText(QApplication::translate("ContactDialog", "Quit", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("ContactDialog", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactDialog: public Ui_ContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTDIALOG_H
