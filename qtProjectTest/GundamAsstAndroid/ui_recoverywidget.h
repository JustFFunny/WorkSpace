/********************************************************************************
** Form generated from reading UI file 'recoverywidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOVERYWIDGET_H
#define UI_RECOVERYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecoveryWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *layoutRecovery;
    QSpacerItem *verticalSpacer_3;
    QPushButton *buttonNandroidBackup;
    QPushButton *buttonBartBackup;
    QPushButton *buttonClearBattery;
    QPushButton *buttonWipeData;
    QPushButton *buttonMountSD;
    QPushButton *buttonNandroidRestore;
    QPushButton *buttonBartRestore;
    QPushButton *buttonFixUID;
    QPushButton *buttonFlashZip;
    QSpacerItem *horizontalSpacer_4;
    QStackedWidget *stackedRecovery;
    QWidget *pageNandroidBackup;
    QWidget *layoutWidget_2;
    QGridLayout *layoutNandroidBackup;
    QSpacerItem *verticalSpacer_15;
    QCheckBox *checkNandroidBackupString;
    QLineEdit *editNandroidBackupString;
    QPushButton *buttonNandroidBackupStart;
    QSpacerItem *horizontalSpacer_13;
    QCheckBox *checkNandroidBackupPath;
    QLineEdit *editNandroidBackupPath;
    QSpacerItem *horizontalSpacer_14;
    QCheckBox *checkNandroidBackupBoot;
    QCheckBox *checkNandroidBackupCache;
    QCheckBox *checkNandroidBackupData;
    QCheckBox *checkNandroidBackupExt;
    QCheckBox *checkNandroidBackupMisc;
    QCheckBox *checkNandroidBackupRecovery;
    QCheckBox *checkNandroidBackupSystem;
    QSpacerItem *horizontalSpacer_6;
    QTextBrowser *textNandroidBackup;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_14;
    QWidget *pageNandroidRestore;
    QWidget *layoutWidget_3;
    QGridLayout *layoutNandroidRestore;
    QSpacerItem *verticalSpacer_16;
    QSpacerItem *horizontalSpacer_16;
    QComboBox *comboNandroidRestore;
    QPushButton *buttonNandroidRestoreStart;
    QSpacerItem *horizontalSpacer_15;
    QCheckBox *checkNandroidRestoreBoot;
    QCheckBox *checkNandroidRestoreCache;
    QCheckBox *checkNandroidRestoreData;
    QCheckBox *checkNandroidRestoreExt;
    QCheckBox *checkNandroidRestoreMisc;
    QCheckBox *checkNandroidRestoreRecovery;
    QCheckBox *checkNandroidRestoreSystem;
    QSpacerItem *horizontalSpacer_17;
    QTextBrowser *textNandroidRestore;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_17;
    QWidget *pageBart;
    QWidget *pageFixUID;
    QWidget *layoutWidget_4;
    QGridLayout *layoutFixUID;
    QSpacerItem *verticalSpacer_20;
    QTextBrowser *textFixUID;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *verticalSpacer_21;
    QWidget *pageWipeData;
    QWidget *layoutWidget_5;
    QGridLayout *layoutWipeData;
    QSpacerItem *verticalSpacer_22;
    QTextBrowser *textWipeData;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *horizontalSpacer_24;
    QSpacerItem *verticalSpacer_23;
    QWidget *pageFlashZIP;
    QWidget *layoutWidget_6;
    QGridLayout *layoutFlashZIP;
    QSpacerItem *verticalSpacer_24;
    QTextBrowser *textFlashZIP;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_26;
    QSpacerItem *verticalSpacer_25;
    QWidget *pageRecoveryStart;
    QWidget *layoutWidget_7;
    QGridLayout *layoutRecoveryStart;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *horizontalSpacer_19;
    QLabel *labelRecoveryStart;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *verticalSpacer_19;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *RecoveryWidget)
    {
        if (RecoveryWidget->objectName().isEmpty())
            RecoveryWidget->setObjectName(QString::fromUtf8("RecoveryWidget"));
        RecoveryWidget->resize(692, 486);
        RecoveryWidget->setWindowTitle(QString::fromUtf8("Form"));
        layoutWidget = new QWidget(RecoveryWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 725, 461));
        layoutRecovery = new QGridLayout(layoutWidget);
        layoutRecovery->setObjectName(QString::fromUtf8("layoutRecovery"));
        layoutRecovery->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutRecovery->addItem(verticalSpacer_3, 0, 2, 1, 2);

        buttonNandroidBackup = new QPushButton(layoutWidget);
        buttonNandroidBackup->setObjectName(QString::fromUtf8("buttonNandroidBackup"));
        buttonNandroidBackup->setEnabled(true);
        buttonNandroidBackup->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonNandroidBackup, 1, 1, 1, 1);

        buttonBartBackup = new QPushButton(layoutWidget);
        buttonBartBackup->setObjectName(QString::fromUtf8("buttonBartBackup"));
        buttonBartBackup->setEnabled(false);
        buttonBartBackup->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonBartBackup, 1, 2, 1, 1);

        buttonClearBattery = new QPushButton(layoutWidget);
        buttonClearBattery->setObjectName(QString::fromUtf8("buttonClearBattery"));
        buttonClearBattery->setEnabled(false);
        buttonClearBattery->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonClearBattery, 1, 3, 1, 2);

        buttonWipeData = new QPushButton(layoutWidget);
        buttonWipeData->setObjectName(QString::fromUtf8("buttonWipeData"));

        layoutRecovery->addWidget(buttonWipeData, 1, 5, 1, 1);

        buttonMountSD = new QPushButton(layoutWidget);
        buttonMountSD->setObjectName(QString::fromUtf8("buttonMountSD"));
        buttonMountSD->setEnabled(false);
        buttonMountSD->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonMountSD, 1, 6, 1, 1);

        buttonNandroidRestore = new QPushButton(layoutWidget);
        buttonNandroidRestore->setObjectName(QString::fromUtf8("buttonNandroidRestore"));
        buttonNandroidRestore->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonNandroidRestore, 2, 1, 1, 1);

        buttonBartRestore = new QPushButton(layoutWidget);
        buttonBartRestore->setObjectName(QString::fromUtf8("buttonBartRestore"));
        buttonBartRestore->setEnabled(false);
        buttonBartRestore->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonBartRestore, 2, 2, 1, 1);

        buttonFixUID = new QPushButton(layoutWidget);
        buttonFixUID->setObjectName(QString::fromUtf8("buttonFixUID"));
        buttonFixUID->setEnabled(false);
        buttonFixUID->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonFixUID, 2, 3, 1, 2);

        buttonFlashZip = new QPushButton(layoutWidget);
        buttonFlashZip->setObjectName(QString::fromUtf8("buttonFlashZip"));
        buttonFlashZip->setFocusPolicy(Qt::ClickFocus);

        layoutRecovery->addWidget(buttonFlashZip, 2, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutRecovery->addItem(horizontalSpacer_4, 3, 0, 1, 1);

        stackedRecovery = new QStackedWidget(layoutWidget);
        stackedRecovery->setObjectName(QString::fromUtf8("stackedRecovery"));
        pageNandroidBackup = new QWidget();
        pageNandroidBackup->setObjectName(QString::fromUtf8("pageNandroidBackup"));
        layoutWidget_2 = new QWidget(pageNandroidBackup);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 20, 590, 308));
        layoutNandroidBackup = new QGridLayout(layoutWidget_2);
        layoutNandroidBackup->setObjectName(QString::fromUtf8("layoutNandroidBackup"));
        layoutNandroidBackup->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_15 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutNandroidBackup->addItem(verticalSpacer_15, 0, 4, 1, 1);

        checkNandroidBackupString = new QCheckBox(layoutWidget_2);
        checkNandroidBackupString->setObjectName(QString::fromUtf8("checkNandroidBackupString"));

        layoutNandroidBackup->addWidget(checkNandroidBackupString, 1, 2, 1, 1);

        editNandroidBackupString = new QLineEdit(layoutWidget_2);
        editNandroidBackupString->setObjectName(QString::fromUtf8("editNandroidBackupString"));

        layoutNandroidBackup->addWidget(editNandroidBackupString, 1, 3, 1, 4);

        buttonNandroidBackupStart = new QPushButton(layoutWidget_2);
        buttonNandroidBackupStart->setObjectName(QString::fromUtf8("buttonNandroidBackupStart"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonNandroidBackupStart->sizePolicy().hasHeightForWidth());
        buttonNandroidBackupStart->setSizePolicy(sizePolicy);

        layoutNandroidBackup->addWidget(buttonNandroidBackupStart, 1, 7, 2, 2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutNandroidBackup->addItem(horizontalSpacer_13, 2, 1, 1, 1);

        checkNandroidBackupPath = new QCheckBox(layoutWidget_2);
        checkNandroidBackupPath->setObjectName(QString::fromUtf8("checkNandroidBackupPath"));

        layoutNandroidBackup->addWidget(checkNandroidBackupPath, 2, 2, 1, 1);

        editNandroidBackupPath = new QLineEdit(layoutWidget_2);
        editNandroidBackupPath->setObjectName(QString::fromUtf8("editNandroidBackupPath"));

        layoutNandroidBackup->addWidget(editNandroidBackupPath, 2, 3, 1, 4);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutNandroidBackup->addItem(horizontalSpacer_14, 2, 9, 1, 1);

        checkNandroidBackupBoot = new QCheckBox(layoutWidget_2);
        checkNandroidBackupBoot->setObjectName(QString::fromUtf8("checkNandroidBackupBoot"));
        checkNandroidBackupBoot->setText(QString::fromUtf8("Boot"));

        layoutNandroidBackup->addWidget(checkNandroidBackupBoot, 3, 2, 1, 1);

        checkNandroidBackupCache = new QCheckBox(layoutWidget_2);
        checkNandroidBackupCache->setObjectName(QString::fromUtf8("checkNandroidBackupCache"));
        checkNandroidBackupCache->setText(QString::fromUtf8("Cache"));

        layoutNandroidBackup->addWidget(checkNandroidBackupCache, 3, 3, 1, 1);

        checkNandroidBackupData = new QCheckBox(layoutWidget_2);
        checkNandroidBackupData->setObjectName(QString::fromUtf8("checkNandroidBackupData"));
        checkNandroidBackupData->setText(QString::fromUtf8("Data"));

        layoutNandroidBackup->addWidget(checkNandroidBackupData, 3, 4, 1, 1);

        checkNandroidBackupExt = new QCheckBox(layoutWidget_2);
        checkNandroidBackupExt->setObjectName(QString::fromUtf8("checkNandroidBackupExt"));
        checkNandroidBackupExt->setText(QString::fromUtf8("Ext"));

        layoutNandroidBackup->addWidget(checkNandroidBackupExt, 3, 5, 1, 1);

        checkNandroidBackupMisc = new QCheckBox(layoutWidget_2);
        checkNandroidBackupMisc->setObjectName(QString::fromUtf8("checkNandroidBackupMisc"));
        checkNandroidBackupMisc->setText(QString::fromUtf8("Misc"));

        layoutNandroidBackup->addWidget(checkNandroidBackupMisc, 3, 6, 1, 1);

        checkNandroidBackupRecovery = new QCheckBox(layoutWidget_2);
        checkNandroidBackupRecovery->setObjectName(QString::fromUtf8("checkNandroidBackupRecovery"));
        checkNandroidBackupRecovery->setText(QString::fromUtf8("Recovery"));

        layoutNandroidBackup->addWidget(checkNandroidBackupRecovery, 3, 7, 1, 1);

        checkNandroidBackupSystem = new QCheckBox(layoutWidget_2);
        checkNandroidBackupSystem->setObjectName(QString::fromUtf8("checkNandroidBackupSystem"));
        checkNandroidBackupSystem->setText(QString::fromUtf8("System"));

        layoutNandroidBackup->addWidget(checkNandroidBackupSystem, 3, 8, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutNandroidBackup->addItem(horizontalSpacer_6, 4, 0, 1, 1);

        textNandroidBackup = new QTextBrowser(layoutWidget_2);
        textNandroidBackup->setObjectName(QString::fromUtf8("textNandroidBackup"));
        textNandroidBackup->setFocusPolicy(Qt::ClickFocus);
        textNandroidBackup->setTextInteractionFlags(Qt::NoTextInteraction);

        layoutNandroidBackup->addWidget(textNandroidBackup, 4, 1, 2, 9);

        horizontalSpacer_12 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutNandroidBackup->addItem(horizontalSpacer_12, 5, 10, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutNandroidBackup->addItem(verticalSpacer_14, 6, 4, 1, 1);

        stackedRecovery->addWidget(pageNandroidBackup);
        pageNandroidRestore = new QWidget();
        pageNandroidRestore->setObjectName(QString::fromUtf8("pageNandroidRestore"));
        layoutWidget_3 = new QWidget(pageNandroidRestore);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 20, 560, 285));
        layoutNandroidRestore = new QGridLayout(layoutWidget_3);
        layoutNandroidRestore->setObjectName(QString::fromUtf8("layoutNandroidRestore"));
        layoutNandroidRestore->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_16 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutNandroidRestore->addItem(verticalSpacer_16, 0, 4, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutNandroidRestore->addItem(horizontalSpacer_16, 1, 1, 1, 1);

        comboNandroidRestore = new QComboBox(layoutWidget_3);
        comboNandroidRestore->setObjectName(QString::fromUtf8("comboNandroidRestore"));

        layoutNandroidRestore->addWidget(comboNandroidRestore, 1, 2, 1, 6);

        buttonNandroidRestoreStart = new QPushButton(layoutWidget_3);
        buttonNandroidRestoreStart->setObjectName(QString::fromUtf8("buttonNandroidRestoreStart"));
        sizePolicy.setHeightForWidth(buttonNandroidRestoreStart->sizePolicy().hasHeightForWidth());
        buttonNandroidRestoreStart->setSizePolicy(sizePolicy);

        layoutNandroidRestore->addWidget(buttonNandroidRestoreStart, 1, 8, 1, 2);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutNandroidRestore->addItem(horizontalSpacer_15, 1, 10, 1, 1);

        checkNandroidRestoreBoot = new QCheckBox(layoutWidget_3);
        checkNandroidRestoreBoot->setObjectName(QString::fromUtf8("checkNandroidRestoreBoot"));
        checkNandroidRestoreBoot->setText(QString::fromUtf8("Boot"));

        layoutNandroidRestore->addWidget(checkNandroidRestoreBoot, 2, 2, 1, 1);

        checkNandroidRestoreCache = new QCheckBox(layoutWidget_3);
        checkNandroidRestoreCache->setObjectName(QString::fromUtf8("checkNandroidRestoreCache"));
        checkNandroidRestoreCache->setText(QString::fromUtf8("Cache"));

        layoutNandroidRestore->addWidget(checkNandroidRestoreCache, 2, 3, 1, 1);

        checkNandroidRestoreData = new QCheckBox(layoutWidget_3);
        checkNandroidRestoreData->setObjectName(QString::fromUtf8("checkNandroidRestoreData"));
        checkNandroidRestoreData->setText(QString::fromUtf8("Data"));

        layoutNandroidRestore->addWidget(checkNandroidRestoreData, 2, 4, 1, 1);

        checkNandroidRestoreExt = new QCheckBox(layoutWidget_3);
        checkNandroidRestoreExt->setObjectName(QString::fromUtf8("checkNandroidRestoreExt"));
        checkNandroidRestoreExt->setText(QString::fromUtf8("Ext"));

        layoutNandroidRestore->addWidget(checkNandroidRestoreExt, 2, 5, 1, 1);

        checkNandroidRestoreMisc = new QCheckBox(layoutWidget_3);
        checkNandroidRestoreMisc->setObjectName(QString::fromUtf8("checkNandroidRestoreMisc"));
        checkNandroidRestoreMisc->setText(QString::fromUtf8("Misc"));

        layoutNandroidRestore->addWidget(checkNandroidRestoreMisc, 2, 6, 1, 1);

        checkNandroidRestoreRecovery = new QCheckBox(layoutWidget_3);
        checkNandroidRestoreRecovery->setObjectName(QString::fromUtf8("checkNandroidRestoreRecovery"));
        checkNandroidRestoreRecovery->setText(QString::fromUtf8("Recovery"));

        layoutNandroidRestore->addWidget(checkNandroidRestoreRecovery, 2, 7, 1, 2);

        checkNandroidRestoreSystem = new QCheckBox(layoutWidget_3);
        checkNandroidRestoreSystem->setObjectName(QString::fromUtf8("checkNandroidRestoreSystem"));
        checkNandroidRestoreSystem->setText(QString::fromUtf8("System"));

        layoutNandroidRestore->addWidget(checkNandroidRestoreSystem, 2, 9, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutNandroidRestore->addItem(horizontalSpacer_17, 3, 0, 1, 1);

        textNandroidRestore = new QTextBrowser(layoutWidget_3);
        textNandroidRestore->setObjectName(QString::fromUtf8("textNandroidRestore"));
        textNandroidRestore->setFocusPolicy(Qt::ClickFocus);
        textNandroidRestore->setTextInteractionFlags(Qt::NoTextInteraction);

        layoutNandroidRestore->addWidget(textNandroidRestore, 3, 1, 1, 10);

        horizontalSpacer_18 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutNandroidRestore->addItem(horizontalSpacer_18, 3, 11, 1, 1);

        verticalSpacer_17 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutNandroidRestore->addItem(verticalSpacer_17, 4, 4, 1, 1);

        stackedRecovery->addWidget(pageNandroidRestore);
        pageBart = new QWidget();
        pageBart->setObjectName(QString::fromUtf8("pageBart"));
        stackedRecovery->addWidget(pageBart);
        pageFixUID = new QWidget();
        pageFixUID->setObjectName(QString::fromUtf8("pageFixUID"));
        layoutWidget_4 = new QWidget(pageFixUID);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(40, 30, 280, 244));
        layoutFixUID = new QGridLayout(layoutWidget_4);
        layoutFixUID->setObjectName(QString::fromUtf8("layoutFixUID"));
        layoutFixUID->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_20 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutFixUID->addItem(verticalSpacer_20, 0, 1, 1, 1);

        textFixUID = new QTextBrowser(layoutWidget_4);
        textFixUID->setObjectName(QString::fromUtf8("textFixUID"));
        textFixUID->setTextInteractionFlags(Qt::NoTextInteraction);

        layoutFixUID->addWidget(textFixUID, 1, 1, 2, 1);

        horizontalSpacer_22 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutFixUID->addItem(horizontalSpacer_22, 1, 2, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutFixUID->addItem(horizontalSpacer_21, 2, 0, 1, 1);

        verticalSpacer_21 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutFixUID->addItem(verticalSpacer_21, 3, 1, 1, 1);

        stackedRecovery->addWidget(pageFixUID);
        pageWipeData = new QWidget();
        pageWipeData->setObjectName(QString::fromUtf8("pageWipeData"));
        layoutWidget_5 = new QWidget(pageWipeData);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(110, 50, 280, 244));
        layoutWipeData = new QGridLayout(layoutWidget_5);
        layoutWipeData->setObjectName(QString::fromUtf8("layoutWipeData"));
        layoutWipeData->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_22 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutWipeData->addItem(verticalSpacer_22, 0, 1, 1, 1);

        textWipeData = new QTextBrowser(layoutWidget_5);
        textWipeData->setObjectName(QString::fromUtf8("textWipeData"));
        textWipeData->setTextInteractionFlags(Qt::NoTextInteraction);

        layoutWipeData->addWidget(textWipeData, 1, 1, 2, 1);

        horizontalSpacer_23 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutWipeData->addItem(horizontalSpacer_23, 1, 2, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutWipeData->addItem(horizontalSpacer_24, 2, 0, 1, 1);

        verticalSpacer_23 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutWipeData->addItem(verticalSpacer_23, 3, 1, 1, 1);

        stackedRecovery->addWidget(pageWipeData);
        pageFlashZIP = new QWidget();
        pageFlashZIP->setObjectName(QString::fromUtf8("pageFlashZIP"));
        layoutWidget_6 = new QWidget(pageFlashZIP);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(100, 30, 280, 244));
        layoutFlashZIP = new QGridLayout(layoutWidget_6);
        layoutFlashZIP->setObjectName(QString::fromUtf8("layoutFlashZIP"));
        layoutFlashZIP->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_24 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutFlashZIP->addItem(verticalSpacer_24, 0, 1, 1, 1);

        textFlashZIP = new QTextBrowser(layoutWidget_6);
        textFlashZIP->setObjectName(QString::fromUtf8("textFlashZIP"));
        textFlashZIP->setTextInteractionFlags(Qt::NoTextInteraction);

        layoutFlashZIP->addWidget(textFlashZIP, 1, 1, 2, 1);

        horizontalSpacer_25 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutFlashZIP->addItem(horizontalSpacer_25, 1, 2, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutFlashZIP->addItem(horizontalSpacer_26, 2, 0, 1, 1);

        verticalSpacer_25 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutFlashZIP->addItem(verticalSpacer_25, 3, 1, 1, 1);

        stackedRecovery->addWidget(pageFlashZIP);
        pageRecoveryStart = new QWidget();
        pageRecoveryStart->setObjectName(QString::fromUtf8("pageRecoveryStart"));
        layoutWidget_7 = new QWidget(pageRecoveryStart);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(70, 50, 229, 114));
        layoutRecoveryStart = new QGridLayout(layoutWidget_7);
        layoutRecoveryStart->setObjectName(QString::fromUtf8("layoutRecoveryStart"));
        layoutRecoveryStart->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutRecoveryStart->addItem(verticalSpacer_18, 0, 1, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutRecoveryStart->addItem(horizontalSpacer_19, 1, 0, 1, 1);

        labelRecoveryStart = new QLabel(layoutWidget_7);
        labelRecoveryStart->setObjectName(QString::fromUtf8("labelRecoveryStart"));

        layoutRecoveryStart->addWidget(labelRecoveryStart, 1, 1, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutRecoveryStart->addItem(horizontalSpacer_20, 1, 2, 1, 1);

        verticalSpacer_19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutRecoveryStart->addItem(verticalSpacer_19, 2, 1, 1, 1);

        stackedRecovery->addWidget(pageRecoveryStart);

        layoutRecovery->addWidget(stackedRecovery, 3, 1, 1, 6);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutRecovery->addItem(horizontalSpacer_5, 3, 7, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutRecovery->addItem(verticalSpacer_2, 4, 4, 1, 1);


        retranslateUi(RecoveryWidget);

        stackedRecovery->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(RecoveryWidget);
    } // setupUi

    void retranslateUi(QWidget *RecoveryWidget)
    {
        buttonNandroidBackup->setText(QApplication::translate("RecoveryWidget", "Nandroid backup", 0, QApplication::UnicodeUTF8));
        buttonBartBackup->setText(QApplication::translate("RecoveryWidget", "Bart backup", 0, QApplication::UnicodeUTF8));
        buttonClearBattery->setText(QApplication::translate("RecoveryWidget", "Clear battery stats", 0, QApplication::UnicodeUTF8));
        buttonWipeData->setText(QApplication::translate("RecoveryWidget", "Wipe data", 0, QApplication::UnicodeUTF8));
        buttonMountSD->setText(QApplication::translate("RecoveryWidget", "Mount SDcard to computer", 0, QApplication::UnicodeUTF8));
        buttonNandroidRestore->setText(QApplication::translate("RecoveryWidget", "Nandroid restore", 0, QApplication::UnicodeUTF8));
        buttonBartRestore->setText(QApplication::translate("RecoveryWidget", "Bart restore", 0, QApplication::UnicodeUTF8));
        buttonFixUID->setText(QApplication::translate("RecoveryWidget", "Fix UID mismatches", 0, QApplication::UnicodeUTF8));
        buttonFlashZip->setText(QApplication::translate("RecoveryWidget", "Flash zip", 0, QApplication::UnicodeUTF8));
        checkNandroidBackupString->setText(QApplication::translate("RecoveryWidget", "Substring", 0, QApplication::UnicodeUTF8));
        buttonNandroidBackupStart->setText(QApplication::translate("RecoveryWidget", "Backup", 0, QApplication::UnicodeUTF8));
        checkNandroidBackupPath->setText(QApplication::translate("RecoveryWidget", "Path", 0, QApplication::UnicodeUTF8));
        buttonNandroidRestoreStart->setText(QApplication::translate("RecoveryWidget", "Restore", 0, QApplication::UnicodeUTF8));
        labelRecoveryStart->setText(QApplication::translate("RecoveryWidget", "Choose one of options above", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(RecoveryWidget);
    } // retranslateUi

};

namespace Ui {
    class RecoveryWidget: public Ui_RecoveryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOVERYWIDGET_H
