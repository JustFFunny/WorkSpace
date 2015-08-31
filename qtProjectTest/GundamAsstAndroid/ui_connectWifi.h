/********************************************************************************
** Form generated from reading UI file 'connectWifi.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTWIFI_H
#define UI_CONNECTWIFI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectWifi
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *adresEdit;
    QLabel *label;
    QLineEdit *portEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *polaczButton;
    QPushButton *zamknijButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ConnectWifi)
    {
        if (ConnectWifi->objectName().isEmpty())
            ConnectWifi->setObjectName(QString::fromUtf8("ConnectWifi"));
        ConnectWifi->setWindowModality(Qt::ApplicationModal);
        ConnectWifi->setEnabled(true);
        ConnectWifi->resize(234, 112);
        ConnectWifi->setStyleSheet(QString::fromUtf8(""));
        gridLayoutWidget = new QWidget(ConnectWifi);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 238, 116));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(30, 17));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        adresEdit = new QLineEdit(gridLayoutWidget);
        adresEdit->setObjectName(QString::fromUtf8("adresEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(adresEdit->sizePolicy().hasHeightForWidth());
        adresEdit->setSizePolicy(sizePolicy);
        adresEdit->setMinimumSize(QSize(0, 0));
        adresEdit->setInputMask(QString::fromUtf8("000.000.000.000;_"));
        adresEdit->setText(QString::fromUtf8("..."));

        gridLayout->addWidget(adresEdit, 2, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(21, 17));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        portEdit = new QLineEdit(gridLayoutWidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(portEdit->sizePolicy().hasHeightForWidth());
        portEdit->setSizePolicy(sizePolicy1);
        portEdit->setMinimumSize(QSize(0, 0));
        portEdit->setMaximumSize(QSize(71, 24));
        portEdit->setInputMask(QString::fromUtf8("00000; "));
        portEdit->setText(QString::fromUtf8(""));

        gridLayout->addWidget(portEdit, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        polaczButton = new QPushButton(gridLayoutWidget);
        polaczButton->setObjectName(QString::fromUtf8("polaczButton"));

        horizontalLayout->addWidget(polaczButton);

        zamknijButton = new QPushButton(gridLayoutWidget);
        zamknijButton->setObjectName(QString::fromUtf8("zamknijButton"));

        horizontalLayout->addWidget(zamknijButton);


        gridLayout->addLayout(horizontalLayout, 4, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 2, 1, 1);


        retranslateUi(ConnectWifi);

        QMetaObject::connectSlotsByName(ConnectWifi);
    } // setupUi

    void retranslateUi(QDialog *ConnectWifi)
    {
        ConnectWifi->setWindowTitle(QApplication::translate("ConnectWifi", "Connect", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConnectWifi", "Address", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConnectWifi", "Port", 0, QApplication::UnicodeUTF8));
        polaczButton->setText(QApplication::translate("ConnectWifi", "Connect", 0, QApplication::UnicodeUTF8));
        zamknijButton->setText(QApplication::translate("ConnectWifi", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectWifi: public Ui_ConnectWifi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWIFI_H
