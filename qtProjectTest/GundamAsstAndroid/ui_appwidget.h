/********************************************************************************
** Form generated from reading UI file 'appwidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPWIDGET_H
#define UI_APPWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppWidget
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *layoutApps;
    QSpacerItem *verticalSpacer_32;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *verticalSpacer_35;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBoxApps;
    QHBoxLayout *horizontalLayout;
    QLineEdit *editFilter;
    QComboBox *comboFilter;
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
    QLineEdit *editCyrketVersion;
    QLabel *labelCyrketVersion;
    QToolButton *toolButtonUninstall;
    QStackedWidget *stackedWidgetApps;
    QWidget *stackedAppsPageApps;
    QWidget *layoutWidget;
    QVBoxLayout *horizontalLayoutStackedApps;
    QToolButton *toolButtonBackup;
    QWidget *stackedAppsPageBackups;
    QWidget *layoutWidget_2;
    QVBoxLayout *horizontalLayoutBackup;
    QToolButton *toolButtonRestore;
    QToolButton *toolButtonRemoveBackup;
    QToolButton *buttonRefreshApps;
    QToolButton *buttonOpenMarket;
    QToolButton *buttonAppBrain;
    QProgressBar *progressApps;
    QSpacerItem *verticalSpacer_33;
    QSpacerItem *verticalSpacer_36;
    QLabel *appsLabelSelected;
    QSpacerItem *verticalSpacer_34;

    void setupUi(QWidget *AppWidget)
    {
        if (AppWidget->objectName().isEmpty())
            AppWidget->setObjectName(QString::fromUtf8("AppWidget"));
        AppWidget->resize(786, 702);
        AppWidget->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayoutWidget_3 = new QWidget(AppWidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 771, 685));
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
        comboBoxApps = new QComboBox(verticalLayoutWidget_3);
        comboBoxApps->setObjectName(QString::fromUtf8("comboBoxApps"));
        comboBoxApps->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_2->addWidget(comboBoxApps);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        editFilter = new QLineEdit(verticalLayoutWidget_3);
        editFilter->setObjectName(QString::fromUtf8("editFilter"));

        horizontalLayout->addWidget(editFilter);

        comboFilter = new QComboBox(verticalLayoutWidget_3);
        comboFilter->setObjectName(QString::fromUtf8("comboFilter"));

        horizontalLayout->addWidget(comboFilter);


        verticalLayout_2->addLayout(horizontalLayout);

        tableView = new QTableView(verticalLayoutWidget_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

        editCyrketVersion = new QLineEdit(verticalLayoutWidget_3);
        editCyrketVersion->setObjectName(QString::fromUtf8("editCyrketVersion"));
        editCyrketVersion->setReadOnly(true);

        gridLayout_6->addWidget(editCyrketVersion, 14, 0, 1, 3);

        labelCyrketVersion = new QLabel(verticalLayoutWidget_3);
        labelCyrketVersion->setObjectName(QString::fromUtf8("labelCyrketVersion"));
        labelCyrketVersion->setEnabled(true);
        labelCyrketVersion->setFont(font);

        gridLayout_6->addWidget(labelCyrketVersion, 13, 0, 1, 3);


        verticalLayout_4->addLayout(gridLayout_6);

        toolButtonUninstall = new QToolButton(verticalLayoutWidget_3);
        toolButtonUninstall->setObjectName(QString::fromUtf8("toolButtonUninstall"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonUninstall->sizePolicy().hasHeightForWidth());
        toolButtonUninstall->setSizePolicy(sizePolicy);
        toolButtonUninstall->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/uninstall.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonUninstall->setIcon(icon);
        toolButtonUninstall->setIconSize(QSize(20, 20));
        toolButtonUninstall->setPopupMode(QToolButton::MenuButtonPopup);
        toolButtonUninstall->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_4->addWidget(toolButtonUninstall);

        stackedWidgetApps = new QStackedWidget(verticalLayoutWidget_3);
        stackedWidgetApps->setObjectName(QString::fromUtf8("stackedWidgetApps"));
        stackedAppsPageApps = new QWidget();
        stackedAppsPageApps->setObjectName(QString::fromUtf8("stackedAppsPageApps"));
        layoutWidget = new QWidget(stackedAppsPageApps);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 291, 64));
        horizontalLayoutStackedApps = new QVBoxLayout(layoutWidget);
        horizontalLayoutStackedApps->setObjectName(QString::fromUtf8("horizontalLayoutStackedApps"));
        horizontalLayoutStackedApps->setContentsMargins(0, 0, 0, 0);
        toolButtonBackup = new QToolButton(layoutWidget);
        toolButtonBackup->setObjectName(QString::fromUtf8("toolButtonBackup"));
        sizePolicy.setHeightForWidth(toolButtonBackup->sizePolicy().hasHeightForWidth());
        toolButtonBackup->setSizePolicy(sizePolicy);
        toolButtonBackup->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/backup.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonBackup->setIcon(icon1);
        toolButtonBackup->setIconSize(QSize(20, 20));
        toolButtonBackup->setPopupMode(QToolButton::MenuButtonPopup);
        toolButtonBackup->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayoutStackedApps->addWidget(toolButtonBackup);

        stackedWidgetApps->addWidget(stackedAppsPageApps);
        stackedAppsPageBackups = new QWidget();
        stackedAppsPageBackups->setObjectName(QString::fromUtf8("stackedAppsPageBackups"));
        layoutWidget_2 = new QWidget(stackedAppsPageBackups);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, -1, 231, 64));
        horizontalLayoutBackup = new QVBoxLayout(layoutWidget_2);
        horizontalLayoutBackup->setObjectName(QString::fromUtf8("horizontalLayoutBackup"));
        horizontalLayoutBackup->setContentsMargins(0, 0, 0, 0);
        toolButtonRestore = new QToolButton(layoutWidget_2);
        toolButtonRestore->setObjectName(QString::fromUtf8("toolButtonRestore"));
        sizePolicy.setHeightForWidth(toolButtonRestore->sizePolicy().hasHeightForWidth());
        toolButtonRestore->setSizePolicy(sizePolicy);
        toolButtonRestore->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/restore.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRestore->setIcon(icon2);
        toolButtonRestore->setIconSize(QSize(20, 20));
        toolButtonRestore->setPopupMode(QToolButton::MenuButtonPopup);
        toolButtonRestore->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayoutBackup->addWidget(toolButtonRestore);

        toolButtonRemoveBackup = new QToolButton(layoutWidget_2);
        toolButtonRemoveBackup->setObjectName(QString::fromUtf8("toolButtonRemoveBackup"));
        sizePolicy.setHeightForWidth(toolButtonRemoveBackup->sizePolicy().hasHeightForWidth());
        toolButtonRemoveBackup->setSizePolicy(sizePolicy);
        toolButtonRemoveBackup->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRemoveBackup->setIcon(icon3);
        toolButtonRemoveBackup->setIconSize(QSize(20, 20));
        toolButtonRemoveBackup->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayoutBackup->addWidget(toolButtonRemoveBackup);

        stackedWidgetApps->addWidget(stackedAppsPageBackups);

        verticalLayout_4->addWidget(stackedWidgetApps);

        buttonRefreshApps = new QToolButton(verticalLayoutWidget_3);
        buttonRefreshApps->setObjectName(QString::fromUtf8("buttonRefreshApps"));
        sizePolicy.setHeightForWidth(buttonRefreshApps->sizePolicy().hasHeightForWidth());
        buttonRefreshApps->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRefreshApps->setIcon(icon4);
        buttonRefreshApps->setIconSize(QSize(20, 20));
        buttonRefreshApps->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_4->addWidget(buttonRefreshApps);

        buttonOpenMarket = new QToolButton(verticalLayoutWidget_3);
        buttonOpenMarket->setObjectName(QString::fromUtf8("buttonOpenMarket"));
        sizePolicy.setHeightForWidth(buttonOpenMarket->sizePolicy().hasHeightForWidth());
        buttonOpenMarket->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/market.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOpenMarket->setIcon(icon5);
        buttonOpenMarket->setIconSize(QSize(20, 20));
        buttonOpenMarket->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_4->addWidget(buttonOpenMarket);

        buttonAppBrain = new QToolButton(verticalLayoutWidget_3);
        buttonAppBrain->setObjectName(QString::fromUtf8("buttonAppBrain"));
        sizePolicy.setHeightForWidth(buttonAppBrain->sizePolicy().hasHeightForWidth());
        buttonAppBrain->setSizePolicy(sizePolicy);
        buttonAppBrain->setIcon(icon5);
        buttonAppBrain->setIconSize(QSize(20, 20));
        buttonAppBrain->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_4->addWidget(buttonAppBrain);

        progressApps = new QProgressBar(verticalLayoutWidget_3);
        progressApps->setObjectName(QString::fromUtf8("progressApps"));
        progressApps->setMaximum(0);
        progressApps->setValue(0);
        progressApps->setAlignment(Qt::AlignCenter);
        progressApps->setFormat(QString::fromUtf8("%v/%m"));

        verticalLayout_4->addWidget(progressApps);

        verticalSpacer_33 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_33);

        verticalLayout_4->setStretch(7, 1);

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

        retranslateUi(AppWidget);

        stackedWidgetApps->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AppWidget);
    } // setupUi

    void retranslateUi(QWidget *AppWidget)
    {
        comboBoxApps->clear();
        comboBoxApps->insertItems(0, QStringList()
         << QApplication::translate("AppWidget", "applications", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppWidget", "backups", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AppWidget", "system apps", 0, QApplication::UnicodeUTF8)
        );
        editFilter->setPlaceholderText(QApplication::translate("AppWidget", "filter", 0, QApplication::UnicodeUTF8));
        labelAppsAppName->setText(QApplication::translate("AppWidget", "App name", 0, QApplication::UnicodeUTF8));
        labelAppsVersion->setText(QApplication::translate("AppWidget", "App version", 0, QApplication::UnicodeUTF8));
        labelAppsFileName->setText(QApplication::translate("AppWidget", "File name", 0, QApplication::UnicodeUTF8));
        labelAppsSize->setText(QApplication::translate("AppWidget", "File Size", 0, QApplication::UnicodeUTF8));
        labelAppsPackageName->setText(QApplication::translate("AppWidget", "Package name", 0, QApplication::UnicodeUTF8));
        labelAppsLocation->setText(QApplication::translate("AppWidget", "Location", 0, QApplication::UnicodeUTF8));
        labelCyrketVersion->setText(QApplication::translate("AppWidget", "Latest version", 0, QApplication::UnicodeUTF8));
        toolButtonUninstall->setText(QApplication::translate("AppWidget", "uninstall", 0, QApplication::UnicodeUTF8));
        toolButtonBackup->setText(QApplication::translate("AppWidget", "backup", 0, QApplication::UnicodeUTF8));
        toolButtonRestore->setText(QApplication::translate("AppWidget", "restore", 0, QApplication::UnicodeUTF8));
        toolButtonRemoveBackup->setText(QApplication::translate("AppWidget", "remove", 0, QApplication::UnicodeUTF8));
        buttonRefreshApps->setText(QApplication::translate("AppWidget", "Refresh", 0, QApplication::UnicodeUTF8));
        buttonOpenMarket->setText(QApplication::translate("AppWidget", "Open in Market (Phone)", 0, QApplication::UnicodeUTF8));
        buttonAppBrain->setText(QApplication::translate("AppWidget", "Open in Market (PC)", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AppWidget);
    } // retranslateUi

};

namespace Ui {
    class AppWidget: public Ui_AppWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPWIDGET_H
