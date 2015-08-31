/********************************************************************************
** Form generated from reading UI file 'filewidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWIDGET_H
#define UI_FILEWIDGET_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileWidget
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
    QPushButton *pushButtonRefresh_2;
    QPushButton *pushButtonRefresh;
    QVBoxLayout *computerLayout;
    QVBoxLayout *phoneLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *leftLabelSelectedCount;
    QLabel *rightLabelSelectedCount;

    void setupUi(QWidget *FileWidget)
    {
        if (FileWidget->objectName().isEmpty())
            FileWidget->setObjectName(QString::fromUtf8("FileWidget"));
        FileWidget->resize(992, 208);
        FileWidget->setWindowTitle(QString::fromUtf8("Form"));
        FileWidget->setWindowOpacity(1);
        gridLayoutWidget = new QWidget(FileWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 975, 160));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftPushButtonPhoneComputerSwitch->setIcon(icon);

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
        rightComboBox->addItem(QString());
        rightComboBox->addItem(QString::fromUtf8("/sdcard/"));
        rightComboBox->addItem(QString::fromUtf8("/system/"));
        rightComboBox->addItem(QString::fromUtf8("/system/app/"));
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
        toolButtonFind->setEnabled(true);
        toolButtonFind->setMaximumSize(QSize(25, 25));
        toolButtonFind->setFocusPolicy(Qt::ClickFocus);
        toolButtonFind->setText(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/phone.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonFind->setIcon(icon1);
        toolButtonFind->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(toolButtonFind);


        gridLayout->addLayout(horizontalLayout_3, 2, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButtonRefresh_2 = new QPushButton(gridLayoutWidget);
        pushButtonRefresh_2->setObjectName(QString::fromUtf8("pushButtonRefresh_2"));
        sizePolicy.setHeightForWidth(pushButtonRefresh_2->sizePolicy().hasHeightForWidth());
        pushButtonRefresh_2->setSizePolicy(sizePolicy);
        pushButtonRefresh_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRefresh_2->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButtonRefresh_2);

        pushButtonRefresh = new QPushButton(gridLayoutWidget);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        sizePolicy.setHeightForWidth(pushButtonRefresh->sizePolicy().hasHeightForWidth());
        pushButtonRefresh->setSizePolicy(sizePolicy);
        pushButtonRefresh->setFocusPolicy(Qt::NoFocus);
        pushButtonRefresh->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButtonRefresh);


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

        retranslateUi(FileWidget);

        QMetaObject::connectSlotsByName(FileWidget);
    } // setupUi

    void retranslateUi(QWidget *FileWidget)
    {
        leftLabelTitle->setText(QApplication::translate("FileWidget", "computer", 0, QApplication::UnicodeUTF8));
        rightLabelTitle->setText(QApplication::translate("FileWidget", "phone", 0, QApplication::UnicodeUTF8));
        leftFileNameFilter->setPlaceholderText(QApplication::translate("FileWidget", "filter", 0, QApplication::UnicodeUTF8));
        rightComboBox->setItemText(0, QApplication::translate("FileWidget", "/", 0, QApplication::UnicodeUTF8));

        rightFileNameFilter->setPlaceholderText(QApplication::translate("FileWidget", "filter", 0, QApplication::UnicodeUTF8));
        pushButtonRefresh_2->setText(QApplication::translate("FileWidget", "F7 refresh", 0, QApplication::UnicodeUTF8));
        pushButtonRefresh->setText(QApplication::translate("FileWidget", "F8 refresh", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(FileWidget);
    } // retranslateUi

};

namespace Ui {
    class FileWidget: public Ui_FileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWIDGET_H
