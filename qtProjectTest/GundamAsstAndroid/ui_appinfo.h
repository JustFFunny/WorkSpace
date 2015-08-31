/********************************************************************************
** Form generated from reading UI file 'appinfo.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPINFO_H
#define UI_APPINFO_H

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

class Ui_appInfo
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelAppsIcon;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelQRcode;
    QLabel *labelAppsAppName;
    QLineEdit *editAppsAppName;
    QLabel *labelAppsVersion;
    QLineEdit *editAppsVersion;
    QLabel *labelAppsPackageName;
    QLineEdit *editAppsFileName;
    QLabel *labelAppsFileName;
    QLabel *labelAppsSize;
    QLineEdit *editAppsSize;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *editAppsPackageName;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *appInfo)
    {
        if (appInfo->objectName().isEmpty())
            appInfo->setObjectName(QString::fromUtf8("appInfo"));
        appInfo->resize(522, 365);
        gridLayoutWidget = new QWidget(appInfo);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 505, 332));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelAppsIcon = new QLabel(gridLayoutWidget);
        labelAppsIcon->setObjectName(QString::fromUtf8("labelAppsIcon"));
        labelAppsIcon->setMinimumSize(QSize(0, 0));
        labelAppsIcon->setMaximumSize(QSize(70, 70));
        labelAppsIcon->setText(QString::fromUtf8(""));
        labelAppsIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/info.png")));

        gridLayout->addWidget(labelAppsIcon, 1, 1, 4, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        labelQRcode = new QLabel(gridLayoutWidget);
        labelQRcode->setObjectName(QString::fromUtf8("labelQRcode"));
        labelQRcode->setMaximumSize(QSize(80, 80));
        labelQRcode->setText(QString::fromUtf8(""));

        gridLayout->addWidget(labelQRcode, 1, 2, 4, 1);

        labelAppsAppName = new QLabel(gridLayoutWidget);
        labelAppsAppName->setObjectName(QString::fromUtf8("labelAppsAppName"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelAppsAppName->setFont(font);

        gridLayout->addWidget(labelAppsAppName, 1, 3, 1, 1);

        editAppsAppName = new QLineEdit(gridLayoutWidget);
        editAppsAppName->setObjectName(QString::fromUtf8("editAppsAppName"));
        editAppsAppName->setText(QString::fromUtf8(""));
        editAppsAppName->setReadOnly(true);

        gridLayout->addWidget(editAppsAppName, 2, 3, 1, 1);

        labelAppsVersion = new QLabel(gridLayoutWidget);
        labelAppsVersion->setObjectName(QString::fromUtf8("labelAppsVersion"));
        labelAppsVersion->setFont(font);

        gridLayout->addWidget(labelAppsVersion, 3, 3, 1, 1);

        editAppsVersion = new QLineEdit(gridLayoutWidget);
        editAppsVersion->setObjectName(QString::fromUtf8("editAppsVersion"));
        editAppsVersion->setText(QString::fromUtf8(""));
        editAppsVersion->setReadOnly(true);

        gridLayout->addWidget(editAppsVersion, 4, 3, 1, 1);

        labelAppsPackageName = new QLabel(gridLayoutWidget);
        labelAppsPackageName->setObjectName(QString::fromUtf8("labelAppsPackageName"));
        labelAppsPackageName->setFont(font);

        gridLayout->addWidget(labelAppsPackageName, 5, 1, 1, 3);

        editAppsFileName = new QLineEdit(gridLayoutWidget);
        editAppsFileName->setObjectName(QString::fromUtf8("editAppsFileName"));
        editAppsFileName->setText(QString::fromUtf8(""));
        editAppsFileName->setReadOnly(true);

        gridLayout->addWidget(editAppsFileName, 8, 1, 1, 3);

        labelAppsFileName = new QLabel(gridLayoutWidget);
        labelAppsFileName->setObjectName(QString::fromUtf8("labelAppsFileName"));
        labelAppsFileName->setFont(font);

        gridLayout->addWidget(labelAppsFileName, 7, 1, 1, 3);

        labelAppsSize = new QLabel(gridLayoutWidget);
        labelAppsSize->setObjectName(QString::fromUtf8("labelAppsSize"));
        labelAppsSize->setFont(font);

        gridLayout->addWidget(labelAppsSize, 9, 1, 1, 3);

        editAppsSize = new QLineEdit(gridLayoutWidget);
        editAppsSize->setObjectName(QString::fromUtf8("editAppsSize"));
        editAppsSize->setText(QString::fromUtf8(""));
        editAppsSize->setReadOnly(true);

        gridLayout->addWidget(editAppsSize, 10, 1, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(horizontalSpacer_3, 12, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);

        editAppsPackageName = new QLineEdit(gridLayoutWidget);
        editAppsPackageName->setObjectName(QString::fromUtf8("editAppsPackageName"));
        editAppsPackageName->setText(QString::fromUtf8(""));
        editAppsPackageName->setReadOnly(true);

        gridLayout->addWidget(editAppsPackageName, 6, 1, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/market.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setIcon(icon);

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/install.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 11, 1, 1, 3);


        retranslateUi(appInfo);

        QMetaObject::connectSlotsByName(appInfo);
    } // setupUi

    void retranslateUi(QDialog *appInfo)
    {
        appInfo->setWindowTitle(QApplication::translate("appInfo", "App info", 0, QApplication::UnicodeUTF8));
        labelAppsAppName->setText(QApplication::translate("appInfo", "App name", 0, QApplication::UnicodeUTF8));
        labelAppsVersion->setText(QApplication::translate("appInfo", "App version", 0, QApplication::UnicodeUTF8));
        labelAppsPackageName->setText(QApplication::translate("appInfo", "Package name", 0, QApplication::UnicodeUTF8));
        labelAppsFileName->setText(QApplication::translate("appInfo", "File name", 0, QApplication::UnicodeUTF8));
        labelAppsSize->setText(QApplication::translate("appInfo", "File Size", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("appInfo", "Open in Market (PC)", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("appInfo", "Open in Market (Phone)", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("appInfo", "Install", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class appInfo: public Ui_appInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPINFO_H
