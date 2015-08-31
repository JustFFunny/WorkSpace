/********************************************************************************
** Form generated from reading UI file 'fastbootwidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FASTBOOTWIDGET_H
#define UI_FASTBOOTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FastbootWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *layoutFastboot;
    QPushButton *buttonFlashSPL;
    QSpacerItem *verticalSpacer_4;
    QPushButton *buttonFlashRecovery;
    QPushButton *buttonFlashRadio;
    QPushButton *buttonBootIMG;

    void setupUi(QWidget *FastbootWidget)
    {
        if (FastbootWidget->objectName().isEmpty())
            FastbootWidget->setObjectName(QString::fromUtf8("FastbootWidget"));
        FastbootWidget->resize(425, 343);
        FastbootWidget->setWindowTitle(QString::fromUtf8("Form"));
        layoutWidget = new QWidget(FastbootWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 371, 321));
        layoutFastboot = new QGridLayout(layoutWidget);
        layoutFastboot->setObjectName(QString::fromUtf8("layoutFastboot"));
        layoutFastboot->setContentsMargins(0, 0, 0, 0);
        buttonFlashSPL = new QPushButton(layoutWidget);
        buttonFlashSPL->setObjectName(QString::fromUtf8("buttonFlashSPL"));
        buttonFlashSPL->setFocusPolicy(Qt::ClickFocus);

        layoutFastboot->addWidget(buttonFlashSPL, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutFastboot->addItem(verticalSpacer_4, 2, 0, 1, 1);

        buttonFlashRecovery = new QPushButton(layoutWidget);
        buttonFlashRecovery->setObjectName(QString::fromUtf8("buttonFlashRecovery"));
        buttonFlashRecovery->setFocusPolicy(Qt::ClickFocus);

        layoutFastboot->addWidget(buttonFlashRecovery, 0, 1, 1, 1);

        buttonFlashRadio = new QPushButton(layoutWidget);
        buttonFlashRadio->setObjectName(QString::fromUtf8("buttonFlashRadio"));
        buttonFlashRadio->setFocusPolicy(Qt::ClickFocus);

        layoutFastboot->addWidget(buttonFlashRadio, 0, 2, 1, 1);

        buttonBootIMG = new QPushButton(layoutWidget);
        buttonBootIMG->setObjectName(QString::fromUtf8("buttonBootIMG"));
        buttonBootIMG->setFocusPolicy(Qt::ClickFocus);

        layoutFastboot->addWidget(buttonBootIMG, 0, 3, 1, 1);


        retranslateUi(FastbootWidget);

        QMetaObject::connectSlotsByName(FastbootWidget);
    } // setupUi

    void retranslateUi(QWidget *FastbootWidget)
    {
        buttonFlashSPL->setText(QApplication::translate("FastbootWidget", "Flash SPL", 0, QApplication::UnicodeUTF8));
        buttonFlashRecovery->setText(QApplication::translate("FastbootWidget", "Flash recovery", 0, QApplication::UnicodeUTF8));
        buttonFlashRadio->setText(QApplication::translate("FastbootWidget", "Flash radio", 0, QApplication::UnicodeUTF8));
        buttonBootIMG->setText(QApplication::translate("FastbootWidget", "Boot IMG", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(FastbootWidget);
    } // retranslateUi

};

namespace Ui {
    class FastbootWidget: public Ui_FastbootWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FASTBOOTWIDGET_H
