/********************************************************************************
** Form generated from reading UI file 'applicationwidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONWIDGET_H
#define UI_APPLICATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicationWidget
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *layoutApps;
    QSpacerItem *verticalSpacer_32;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *verticalSpacer_35;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_6;
    QLabel *labelAppsIcon;
    QLabel *labelAppsAppName;
    QLabel *labelAppsVersion;
    QLabel *labelAppsFileName;
    QLabel *labelAppsSize;
    QLineEdit *editAppsAppName;
    QLineEdit *editAppsVersion;
    QLineEdit *editAppsFileName;
    QLabel *labelAppsPackageName;
    QLineEdit *editAppsPackageName;
    QLineEdit *editAppsSize;
    QLabel *labelAppsLocation;
    QLineEdit *editAppsLocation;
    QLabel *labelQRcode;
    QPushButton *pushButton_uninstall;
    QPushButton *pushButton_copy;
    QPushButton *pushButton_install;
    QPushButton *pushButton_refresh;
    QProgressBar *progressApps;
    QSpacerItem *verticalSpacer_33;
    QSpacerItem *verticalSpacer_36;
    QLabel *appsLabelSelected;
    QSpacerItem *verticalSpacer_34;

    void setupUi(QWidget *ApplicationWidget)
    {
        if (ApplicationWidget->objectName().isEmpty())
            ApplicationWidget->setObjectName(QString::fromUtf8("ApplicationWidget"));
        ApplicationWidget->resize(735, 539);
        verticalLayoutWidget_3 = new QWidget(ApplicationWidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 731, 552));
        layoutApps = new QVBoxLayout(verticalLayoutWidget_3);
        layoutApps->setObjectName(QString::fromUtf8("layoutApps"));
        layoutApps->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_32 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutApps->addItem(verticalSpacer_32);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalSpacer_35 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(verticalSpacer_35);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(verticalLayoutWidget_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setFrameShape(QFrame::StyledPanel);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setDragDropMode(QAbstractItemView::NoDragDrop);
        tableView->setAlternatingRowColors(true);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setShowGrid(false);
        tableView->setGridStyle(Qt::NoPen);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableView);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        labelAppsIcon = new QLabel(verticalLayoutWidget_3);
        labelAppsIcon->setObjectName(QString::fromUtf8("labelAppsIcon"));
        labelAppsIcon->setMinimumSize(QSize(72, 72));
        labelAppsIcon->setMaximumSize(QSize(72, 72));
        labelAppsIcon->setText(QString::fromUtf8(""));
        labelAppsIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/info.png")));
        labelAppsIcon->setScaledContents(true);

        gridLayout_6->addWidget(labelAppsIcon, 0, 0, 5, 1);

        labelAppsAppName = new QLabel(verticalLayoutWidget_3);
        labelAppsAppName->setObjectName(QString::fromUtf8("labelAppsAppName"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelAppsAppName->setFont(font);

        gridLayout_6->addWidget(labelAppsAppName, 0, 2, 1, 1);

        labelAppsVersion = new QLabel(verticalLayoutWidget_3);
        labelAppsVersion->setObjectName(QString::fromUtf8("labelAppsVersion"));
        labelAppsVersion->setFont(font);

        gridLayout_6->addWidget(labelAppsVersion, 2, 2, 1, 1);

        labelAppsFileName = new QLabel(verticalLayoutWidget_3);
        labelAppsFileName->setObjectName(QString::fromUtf8("labelAppsFileName"));
        labelAppsFileName->setFont(font);

        gridLayout_6->addWidget(labelAppsFileName, 7, 0, 1, 3);

        labelAppsSize = new QLabel(verticalLayoutWidget_3);
        labelAppsSize->setObjectName(QString::fromUtf8("labelAppsSize"));
        labelAppsSize->setFont(font);

        gridLayout_6->addWidget(labelAppsSize, 9, 0, 1, 3);

        editAppsAppName = new QLineEdit(verticalLayoutWidget_3);
        editAppsAppName->setObjectName(QString::fromUtf8("editAppsAppName"));
        editAppsAppName->setText(QString::fromUtf8(""));
        editAppsAppName->setReadOnly(true);

        gridLayout_6->addWidget(editAppsAppName, 1, 2, 1, 1);

        editAppsVersion = new QLineEdit(verticalLayoutWidget_3);
        editAppsVersion->setObjectName(QString::fromUtf8("editAppsVersion"));
        editAppsVersion->setText(QString::fromUtf8(""));
        editAppsVersion->setReadOnly(true);

        gridLayout_6->addWidget(editAppsVersion, 3, 2, 1, 1);

        editAppsFileName = new QLineEdit(verticalLayoutWidget_3);
        editAppsFileName->setObjectName(QString::fromUtf8("editAppsFileName"));
        editAppsFileName->setText(QString::fromUtf8(""));
        editAppsFileName->setReadOnly(true);

        gridLayout_6->addWidget(editAppsFileName, 8, 0, 1, 3);

        labelAppsPackageName = new QLabel(verticalLayoutWidget_3);
        labelAppsPackageName->setObjectName(QString::fromUtf8("labelAppsPackageName"));
        labelAppsPackageName->setFont(font);

        gridLayout_6->addWidget(labelAppsPackageName, 5, 0, 1, 3);

        editAppsPackageName = new QLineEdit(verticalLayoutWidget_3);
        editAppsPackageName->setObjectName(QString::fromUtf8("editAppsPackageName"));
        editAppsPackageName->setText(QString::fromUtf8(""));
        editAppsPackageName->setReadOnly(true);

        gridLayout_6->addWidget(editAppsPackageName, 6, 0, 1, 3);

        editAppsSize = new QLineEdit(verticalLayoutWidget_3);
        editAppsSize->setObjectName(QString::fromUtf8("editAppsSize"));
        editAppsSize->setText(QString::fromUtf8(""));
        editAppsSize->setReadOnly(true);

        gridLayout_6->addWidget(editAppsSize, 10, 0, 1, 3);

        labelAppsLocation = new QLabel(verticalLayoutWidget_3);
        labelAppsLocation->setObjectName(QString::fromUtf8("labelAppsLocation"));
        labelAppsLocation->setFont(font);

        gridLayout_6->addWidget(labelAppsLocation, 11, 0, 1, 3);

        editAppsLocation = new QLineEdit(verticalLayoutWidget_3);
        editAppsLocation->setObjectName(QString::fromUtf8("editAppsLocation"));
        editAppsLocation->setReadOnly(true);

        gridLayout_6->addWidget(editAppsLocation, 12, 0, 1, 3);

        labelQRcode = new QLabel(verticalLayoutWidget_3);
        labelQRcode->setObjectName(QString::fromUtf8("labelQRcode"));
        labelQRcode->setMaximumSize(QSize(72, 72));
        labelQRcode->setText(QString::fromUtf8(""));
        labelQRcode->setScaledContents(true);

        gridLayout_6->addWidget(labelQRcode, 0, 1, 5, 1);


        verticalLayout_4->addLayout(gridLayout_6);

        pushButton_uninstall = new QPushButton(verticalLayoutWidget_3);
        pushButton_uninstall->setObjectName(QString::fromUtf8("pushButton_uninstall"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/uninstall.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_uninstall->setIcon(icon);

        verticalLayout_4->addWidget(pushButton_uninstall);

        pushButton_copy = new QPushButton(verticalLayoutWidget_3);
        pushButton_copy->setObjectName(QString::fromUtf8("pushButton_copy"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_copy->setIcon(icon1);

        verticalLayout_4->addWidget(pushButton_copy);

        pushButton_install = new QPushButton(verticalLayoutWidget_3);
        pushButton_install->setObjectName(QString::fromUtf8("pushButton_install"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/install.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_install->setIcon(icon2);

        verticalLayout_4->addWidget(pushButton_install);

        pushButton_refresh = new QPushButton(verticalLayoutWidget_3);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_refresh->setIcon(icon3);

        verticalLayout_4->addWidget(pushButton_refresh);

        progressApps = new QProgressBar(verticalLayoutWidget_3);
        progressApps->setObjectName(QString::fromUtf8("progressApps"));
        progressApps->setMaximum(1000);
        progressApps->setValue(0);
        progressApps->setAlignment(Qt::AlignCenter);
        progressApps->setFormat(QString::fromUtf8("%v/%m"));

        verticalLayout_4->addWidget(progressApps);

        verticalSpacer_33 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_33);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalSpacer_36 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(verticalSpacer_36);

        horizontalLayout_6->setStretch(1, 1);

        layoutApps->addLayout(horizontalLayout_6);

        appsLabelSelected = new QLabel(verticalLayoutWidget_3);
        appsLabelSelected->setObjectName(QString::fromUtf8("appsLabelSelected"));
        appsLabelSelected->setText(QString::fromUtf8(""));

        layoutApps->addWidget(appsLabelSelected);

        verticalSpacer_34 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutApps->addItem(verticalSpacer_34);

        layoutApps->setStretch(1, 1);

        retranslateUi(ApplicationWidget);

        QMetaObject::connectSlotsByName(ApplicationWidget);
    } // setupUi

    void retranslateUi(QWidget *ApplicationWidget)
    {
        ApplicationWidget->setWindowTitle(QApplication::translate("ApplicationWidget", "Form", 0, QApplication::UnicodeUTF8));
        labelAppsAppName->setText(QApplication::translate("ApplicationWidget", "App name", 0, QApplication::UnicodeUTF8));
        labelAppsVersion->setText(QApplication::translate("ApplicationWidget", "App version", 0, QApplication::UnicodeUTF8));
        labelAppsFileName->setText(QApplication::translate("ApplicationWidget", "File name", 0, QApplication::UnicodeUTF8));
        labelAppsSize->setText(QApplication::translate("ApplicationWidget", "File Size", 0, QApplication::UnicodeUTF8));
        labelAppsPackageName->setText(QApplication::translate("ApplicationWidget", "Package name", 0, QApplication::UnicodeUTF8));
        labelAppsLocation->setText(QApplication::translate("ApplicationWidget", "Level", 0, QApplication::UnicodeUTF8));
        pushButton_uninstall->setText(QApplication::translate("ApplicationWidget", "Uninstall", 0, QApplication::UnicodeUTF8));
        pushButton_copy->setText(QApplication::translate("ApplicationWidget", "Copy To PC", 0, QApplication::UnicodeUTF8));
        pushButton_install->setText(QApplication::translate("ApplicationWidget", "Install", 0, QApplication::UnicodeUTF8));
        pushButton_refresh->setText(QApplication::translate("ApplicationWidget", "Refresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ApplicationWidget: public Ui_ApplicationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONWIDGET_H
