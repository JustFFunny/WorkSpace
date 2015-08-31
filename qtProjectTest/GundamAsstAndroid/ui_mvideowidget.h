/********************************************************************************
** Form generated from reading UI file 'mvideowidget.ui'
**
** Created: Tue Jan 7 15:45:07 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MVIDEOWIDGET_H
#define UI_MVIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MVideoWidget
{
public:
    QWidget *move_widget;
    QPushButton *pushButton;

    void setupUi(QWidget *MVideoWidget)
    {
        if (MVideoWidget->objectName().isEmpty())
            MVideoWidget->setObjectName(QString::fromUtf8("MVideoWidget"));
        MVideoWidget->resize(750, 580);
        move_widget = new QWidget(MVideoWidget);
        move_widget->setObjectName(QString::fromUtf8("move_widget"));
        move_widget->setGeometry(QRect(200, 40, 511, 480));
        pushButton = new QPushButton(MVideoWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 180, 98, 27));

        retranslateUi(MVideoWidget);

        QMetaObject::connectSlotsByName(MVideoWidget);
    } // setupUi

    void retranslateUi(QWidget *MVideoWidget)
    {
        MVideoWidget->setWindowTitle(QApplication::translate("MVideoWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MVideoWidget", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MVideoWidget: public Ui_MVideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MVIDEOWIDGET_H
