/********************************************************************************
** Form generated from reading UI file 'shellwidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHELLWIDGET_H
#define UI_SHELLWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShellWidget
{
public:

    void setupUi(QWidget *ShellWidget)
    {
        if (ShellWidget->objectName().isEmpty())
            ShellWidget->setObjectName(QString::fromUtf8("ShellWidget"));
        ShellWidget->resize(735, 514);
        ShellWidget->setWindowTitle(QString::fromUtf8("Form"));

        retranslateUi(ShellWidget);

        QMetaObject::connectSlotsByName(ShellWidget);
    } // setupUi

    void retranslateUi(QWidget *ShellWidget)
    {
        Q_UNUSED(ShellWidget);
    } // retranslateUi

};

namespace Ui {
    class ShellWidget: public Ui_ShellWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHELLWIDGET_H
