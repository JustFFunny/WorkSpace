/********************************************************************************
** Form generated from reading UI file 'filemanagerwidget.ui'
**
** Created: Tue Dec 24 15:11:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGERWIDGET_H
#define UI_FILEMANAGERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManagerWidget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *leftLabelTitle;
    QLabel *rightLabelTitle;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *leftPushButtonFolderUp;
    QComboBox *leftComboBox;
    QLineEdit *leftFileNameFilter;
    QPushButton *leftPushButtonPhoneComputerSwitch;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *rightPushButtonFolderUp;
    QComboBox *rightComboBox;
    QLineEdit *rightFileNameFilter;
    QToolButton *toolButtonFind;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonRename;
    QPushButton *pushButtonSelectAll;
    QPushButton *pushButton;
    QPushButton *pushButtonCopy;
    QPushButton *pushButtonNewDir;
    QPushButton *pushButtonRefresh;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonHiddenFiles;
    QVBoxLayout *computerLayout;
    QVBoxLayout *phoneLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *leftLabelSelectedCount;
    QLabel *rightLabelSelectedCount;

    void setupUi(QDialog *FileManagerWidget)
    {
        if (FileManagerWidget->objectName().isEmpty())
            FileManagerWidget->setObjectName(QString::fromUtf8("FileManagerWidget"));
        FileManagerWidget->resize(1048, 187);
        gridLayoutWidget = new QWidget(FileManagerWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 975, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leftLabelTitle = new QLabel(gridLayoutWidget);
        leftLabelTitle->setObjectName(QString::fromUtf8("leftLabelTitle"));
        leftLabelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(leftLabelTitle, 1, 1, 1, 1);

        rightLabelTitle = new QLabel(gridLayoutWidget);
        rightLabelTitle->setObjectName(QString::fromUtf8("rightLabelTitle"));
        rightLabelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(rightLabelTitle, 1, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        leftPushButtonFolderUp = new QPushButton(gridLayoutWidget);
        leftPushButtonFolderUp->setObjectName(QString::fromUtf8("leftPushButtonFolderUp"));
        leftPushButtonFolderUp->setMaximumSize(QSize(30, 25));
        leftPushButtonFolderUp->setFocusPolicy(Qt::NoFocus);
        leftPushButtonFolderUp->setText(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(leftPushButtonFolderUp);

        leftComboBox = new QComboBox(gridLayoutWidget);
        leftComboBox->setObjectName(QString::fromUtf8("leftComboBox"));
        leftComboBox->setMaximumSize(QSize(16777215, 25));
        leftComboBox->setFocusPolicy(Qt::ClickFocus);
        leftComboBox->setEditable(true);
        leftComboBox->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_4->addWidget(leftComboBox);

        leftFileNameFilter = new QLineEdit(gridLayoutWidget);
        leftFileNameFilter->setObjectName(QString::fromUtf8("leftFileNameFilter"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftFileNameFilter->sizePolicy().hasHeightForWidth());
        leftFileNameFilter->setSizePolicy(sizePolicy);
        leftFileNameFilter->setMinimumSize(QSize(0, 0));
        leftFileNameFilter->setMaximumSize(QSize(80, 25));
        leftFileNameFilter->setFocusPolicy(Qt::ClickFocus);
        leftFileNameFilter->setText(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(leftFileNameFilter);

        leftPushButtonPhoneComputerSwitch = new QPushButton(gridLayoutWidget);
        leftPushButtonPhoneComputerSwitch->setObjectName(QString::fromUtf8("leftPushButtonPhoneComputerSwitch"));
        leftPushButtonPhoneComputerSwitch->setMaximumSize(QSize(30, 25));
        leftPushButtonPhoneComputerSwitch->setFocusPolicy(Qt::NoFocus);
        leftPushButtonPhoneComputerSwitch->setStyleSheet(QString::fromUtf8(""));
        leftPushButtonPhoneComputerSwitch->setText(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(leftPushButtonPhoneComputerSwitch);


        gridLayout->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rightPushButtonFolderUp = new QPushButton(gridLayoutWidget);
        rightPushButtonFolderUp->setObjectName(QString::fromUtf8("rightPushButtonFolderUp"));
        rightPushButtonFolderUp->setMaximumSize(QSize(30, 25));
        rightPushButtonFolderUp->setFocusPolicy(Qt::NoFocus);
        rightPushButtonFolderUp->setText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(rightPushButtonFolderUp);

        rightComboBox = new QComboBox(gridLayoutWidget);
        rightComboBox->insertItems(0, QStringList()
         << QString::fromUtf8("/sdcard/")
         << QString::fromUtf8("/data/")
         << QString::fromUtf8("/data/app/")
         << QString::fromUtf8("/system/")
         << QString::fromUtf8("/system/app/")
        );
        rightComboBox->setObjectName(QString::fromUtf8("rightComboBox"));
        rightComboBox->setMaximumSize(QSize(16777215, 25));
        rightComboBox->setFocusPolicy(Qt::ClickFocus);
        rightComboBox->setEditable(true);
        rightComboBox->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_3->addWidget(rightComboBox);

        rightFileNameFilter = new QLineEdit(gridLayoutWidget);
        rightFileNameFilter->setObjectName(QString::fromUtf8("rightFileNameFilter"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rightFileNameFilter->sizePolicy().hasHeightForWidth());
        rightFileNameFilter->setSizePolicy(sizePolicy1);
        rightFileNameFilter->setMaximumSize(QSize(80, 25));
        rightFileNameFilter->setFocusPolicy(Qt::ClickFocus);
        rightFileNameFilter->setText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(rightFileNameFilter);

        toolButtonFind = new QToolButton(gridLayoutWidget);
        toolButtonFind->setObjectName(QString::fromUtf8("toolButtonFind"));
        toolButtonFind->setMaximumSize(QSize(25, 25));
        toolButtonFind->setFocusPolicy(Qt::ClickFocus);
        toolButtonFind->setText(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonFind->setIcon(icon);
        toolButtonFind->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(toolButtonFind);


        gridLayout->addLayout(horizontalLayout_3, 2, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButtonRename = new QPushButton(gridLayoutWidget);
        pushButtonRename->setObjectName(QString::fromUtf8("pushButtonRename"));
        sizePolicy.setHeightForWidth(pushButtonRename->sizePolicy().hasHeightForWidth());
        pushButtonRename->setSizePolicy(sizePolicy);
        pushButtonRename->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRename->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonRename);

        pushButtonSelectAll = new QPushButton(gridLayoutWidget);
        pushButtonSelectAll->setObjectName(QString::fromUtf8("pushButtonSelectAll"));
        sizePolicy.setHeightForWidth(pushButtonSelectAll->sizePolicy().hasHeightForWidth());
        pushButtonSelectAll->setSizePolicy(sizePolicy);
        pushButtonSelectAll->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/selectAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelectAll->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButtonSelectAll);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/install.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton);

        pushButtonCopy = new QPushButton(gridLayoutWidget);
        pushButtonCopy->setObjectName(QString::fromUtf8("pushButtonCopy"));
        sizePolicy.setHeightForWidth(pushButtonCopy->sizePolicy().hasHeightForWidth());
        pushButtonCopy->setSizePolicy(sizePolicy);
        pushButtonCopy->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCopy->setIcon(icon4);

        horizontalLayout_5->addWidget(pushButtonCopy);

        pushButtonNewDir = new QPushButton(gridLayoutWidget);
        pushButtonNewDir->setObjectName(QString::fromUtf8("pushButtonNewDir"));
        sizePolicy.setHeightForWidth(pushButtonNewDir->sizePolicy().hasHeightForWidth());
        pushButtonNewDir->setSizePolicy(sizePolicy);
        pushButtonNewDir->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/newDir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonNewDir->setIcon(icon5);

        horizontalLayout_5->addWidget(pushButtonNewDir);

        pushButtonRefresh = new QPushButton(gridLayoutWidget);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        sizePolicy.setHeightForWidth(pushButtonRefresh->sizePolicy().hasHeightForWidth());
        pushButtonRefresh->setSizePolicy(sizePolicy);
        pushButtonRefresh->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRefresh->setIcon(icon6);

        horizontalLayout_5->addWidget(pushButtonRefresh);

        pushButtonDelete = new QPushButton(gridLayoutWidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        sizePolicy.setHeightForWidth(pushButtonDelete->sizePolicy().hasHeightForWidth());
        pushButtonDelete->setSizePolicy(sizePolicy);
        pushButtonDelete->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDelete->setIcon(icon7);

        horizontalLayout_5->addWidget(pushButtonDelete);

        pushButtonHiddenFiles = new QPushButton(gridLayoutWidget);
        pushButtonHiddenFiles->setObjectName(QString::fromUtf8("pushButtonHiddenFiles"));
        sizePolicy.setHeightForWidth(pushButtonHiddenFiles->sizePolicy().hasHeightForWidth());
        pushButtonHiddenFiles->setSizePolicy(sizePolicy);
        pushButtonHiddenFiles->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/hidden.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonHiddenFiles->setIcon(icon8);

        horizontalLayout_5->addWidget(pushButtonHiddenFiles);


        gridLayout->addLayout(horizontalLayout_5, 4, 1, 1, 2);

        computerLayout = new QVBoxLayout();
        computerLayout->setObjectName(QString::fromUtf8("computerLayout"));

        gridLayout->addLayout(computerLayout, 3, 1, 1, 1);

        phoneLayout = new QVBoxLayout();
        phoneLayout->setObjectName(QString::fromUtf8("phoneLayout"));

        gridLayout->addLayout(phoneLayout, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        leftLabelSelectedCount = new QLabel(gridLayoutWidget);
        leftLabelSelectedCount->setObjectName(QString::fromUtf8("leftLabelSelectedCount"));
        leftLabelSelectedCount->setText(QString::fromUtf8("0 selected"));

        gridLayout->addWidget(leftLabelSelectedCount, 5, 1, 1, 1);

        rightLabelSelectedCount = new QLabel(gridLayoutWidget);
        rightLabelSelectedCount->setObjectName(QString::fromUtf8("rightLabelSelectedCount"));
        rightLabelSelectedCount->setText(QString::fromUtf8("0 selected"));

        gridLayout->addWidget(rightLabelSelectedCount, 5, 2, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(FileManagerWidget);

        QMetaObject::connectSlotsByName(FileManagerWidget);
    } // setupUi

    void retranslateUi(QDialog *FileManagerWidget)
    {
        FileManagerWidget->setWindowTitle(QApplication::translate("FileManagerWidget", "Dialog", 0, QApplication::UnicodeUTF8));
        leftLabelTitle->setText(QApplication::translate("FileManagerWidget", "computer", 0, QApplication::UnicodeUTF8));
        rightLabelTitle->setText(QApplication::translate("FileManagerWidget", "phone", 0, QApplication::UnicodeUTF8));
        leftFileNameFilter->setPlaceholderText(QApplication::translate("FileManagerWidget", "filter", 0, QApplication::UnicodeUTF8));
        rightFileNameFilter->setPlaceholderText(QApplication::translate("FileManagerWidget", "filter", 0, QApplication::UnicodeUTF8));
        pushButtonRename->setText(QApplication::translate("FileManagerWidget", "F2 rename", 0, QApplication::UnicodeUTF8));
        pushButtonSelectAll->setText(QApplication::translate("FileManagerWidget", "F3 select all/none", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FileManagerWidget", "F4 install", 0, QApplication::UnicodeUTF8));
        pushButtonCopy->setText(QApplication::translate("FileManagerWidget", "F5 copy", 0, QApplication::UnicodeUTF8));
        pushButtonNewDir->setText(QApplication::translate("FileManagerWidget", "F6 new dir", 0, QApplication::UnicodeUTF8));
        pushButtonRefresh->setText(QApplication::translate("FileManagerWidget", "F7 refresh", 0, QApplication::UnicodeUTF8));
        pushButtonDelete->setText(QApplication::translate("FileManagerWidget", "F8 delete", 0, QApplication::UnicodeUTF8));
        pushButtonHiddenFiles->setText(QApplication::translate("FileManagerWidget", "F9 hidden files", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileManagerWidget: public Ui_FileManagerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGERWIDGET_H
