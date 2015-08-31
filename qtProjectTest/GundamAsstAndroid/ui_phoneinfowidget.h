/********************************************************************************
** Form generated from reading UI file 'phoneinfowidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEINFOWIDGET_H
#define UI_PHONEINFOWIDGET_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneInfoWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEditSdcardSize_2;
    QLabel *labelSdcardUsed_2;
    QLabel *labelSdcardSize_2;
    QLineEdit *lineEditSdcardAvailable_2;
    QLabel *label_18;
    QLineEdit *lineEditSdcardUsed_2;
    QLabel *labelSdcardAvailable_2;
    QProgressBar *progressBarSdcard_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditDataUsed;
    QLineEdit *lineEditDataAvailable;
    QProgressBar *progressBarData;
    QLineEdit *lineEditDataSize;
    QLabel *labelDataSize;
    QLabel *label;
    QLabel *labelDataUsed;
    QLabel *labelDataAvailable;
    QGridLayout *gridLayout;
    QLabel *labelSdcardSize;
    QLabel *labelSdcardAvailable;
    QLineEdit *lineEditSdcardAvailable;
    QLineEdit *lineEditSdcardSize;
    QLabel *label_17;
    QLineEdit *lineEditSdcardUsed;
    QProgressBar *progressBarSdcard;
    QLabel *labelSdcardUsed;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_3;
    QLabel *labelModel;
    QLineEdit *lineEditModel;
    QLabel *labelOperator;
    QLineEdit *lineEditNumber;
    QLabel *labelRadio;
    QLineEdit *lineEditImei;
    QLineEdit *lineEditMac;
    QLabel *labelSerialNumber;
    QLabel *labelMac;
    QLineEdit *lineEditOperator;
    QLabel *labelNumber;
    QLineEdit *lineEditSerialNumber;
    QGridLayout *gridLayout_5;
    QProgressBar *progressBarBatteryLevel;
    QLabel *labelBatteryLevel;
    QGridLayout *gridLayout_4;
    QLabel *labelRgb565;
    QPushButton *buttonRefreshScreenshot;
    QPushButton *buttonSaveScreenshot;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;

    void setupUi(QWidget *PhoneInfoWidget)
    {
        if (PhoneInfoWidget->objectName().isEmpty())
            PhoneInfoWidget->setObjectName(QString::fromUtf8("PhoneInfoWidget"));
        PhoneInfoWidget->resize(735, 538);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PhoneInfoWidget->sizePolicy().hasHeightForWidth());
        PhoneInfoWidget->setSizePolicy(sizePolicy);
        PhoneInfoWidget->setWindowTitle(QString::fromUtf8("Form"));
        layoutWidget = new QWidget(PhoneInfoWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 691, 424));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setSpacing(5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lineEditSdcardSize_2 = new QLineEdit(layoutWidget);
        lineEditSdcardSize_2->setObjectName(QString::fromUtf8("lineEditSdcardSize_2"));
        lineEditSdcardSize_2->setText(QString::fromUtf8(""));
        lineEditSdcardSize_2->setReadOnly(true);

        gridLayout_6->addWidget(lineEditSdcardSize_2, 1, 2, 1, 1);

        labelSdcardUsed_2 = new QLabel(layoutWidget);
        labelSdcardUsed_2->setObjectName(QString::fromUtf8("labelSdcardUsed_2"));

        gridLayout_6->addWidget(labelSdcardUsed_2, 1, 3, 1, 1);

        labelSdcardSize_2 = new QLabel(layoutWidget);
        labelSdcardSize_2->setObjectName(QString::fromUtf8("labelSdcardSize_2"));

        gridLayout_6->addWidget(labelSdcardSize_2, 1, 1, 1, 1);

        lineEditSdcardAvailable_2 = new QLineEdit(layoutWidget);
        lineEditSdcardAvailable_2->setObjectName(QString::fromUtf8("lineEditSdcardAvailable_2"));
        lineEditSdcardAvailable_2->setText(QString::fromUtf8(""));
        lineEditSdcardAvailable_2->setReadOnly(true);

        gridLayout_6->addWidget(lineEditSdcardAvailable_2, 1, 6, 1, 1);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setText(QString::fromUtf8("/sdcard"));

        gridLayout_6->addWidget(label_18, 0, 0, 1, 1);

        lineEditSdcardUsed_2 = new QLineEdit(layoutWidget);
        lineEditSdcardUsed_2->setObjectName(QString::fromUtf8("lineEditSdcardUsed_2"));
        lineEditSdcardUsed_2->setText(QString::fromUtf8(""));
        lineEditSdcardUsed_2->setReadOnly(true);

        gridLayout_6->addWidget(lineEditSdcardUsed_2, 1, 4, 1, 1);

        labelSdcardAvailable_2 = new QLabel(layoutWidget);
        labelSdcardAvailable_2->setObjectName(QString::fromUtf8("labelSdcardAvailable_2"));

        gridLayout_6->addWidget(labelSdcardAvailable_2, 1, 5, 1, 1);

        progressBarSdcard_2 = new QProgressBar(layoutWidget);
        progressBarSdcard_2->setObjectName(QString::fromUtf8("progressBarSdcard_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBarSdcard_2->sizePolicy().hasHeightForWidth());
        progressBarSdcard_2->setSizePolicy(sizePolicy1);
        progressBarSdcard_2->setMinimumSize(QSize(41, 0));
        progressBarSdcard_2->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"border: 1px solid black;\n"
"text-align: center;\n"
"padding: 1px;\n"
"border-top-right-radius: 7px;\n"
"border-top-left-radius: 7px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"height:2\n"
"}\n"
"QProgressBar::chunk {\n"
"border-top-right-radius: 7px;\n"
"border-top-left-radius: 7px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"border: 1px solid black;\n"
"background-color:#46a\n"
"}"));
        progressBarSdcard_2->setValue(0);
        progressBarSdcard_2->setOrientation(Qt::Horizontal);
        progressBarSdcard_2->setFormat(QString::fromUtf8("%p%"));

        gridLayout_6->addWidget(progressBarSdcard_2, 0, 1, 1, 7);


        gridLayout_7->addLayout(gridLayout_6, 5, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEditDataUsed = new QLineEdit(layoutWidget);
        lineEditDataUsed->setObjectName(QString::fromUtf8("lineEditDataUsed"));
        lineEditDataUsed->setText(QString::fromUtf8(""));
        lineEditDataUsed->setReadOnly(true);

        gridLayout_2->addWidget(lineEditDataUsed, 1, 4, 1, 1);

        lineEditDataAvailable = new QLineEdit(layoutWidget);
        lineEditDataAvailable->setObjectName(QString::fromUtf8("lineEditDataAvailable"));
        lineEditDataAvailable->setText(QString::fromUtf8(""));
        lineEditDataAvailable->setReadOnly(true);

        gridLayout_2->addWidget(lineEditDataAvailable, 1, 7, 1, 1);

        progressBarData = new QProgressBar(layoutWidget);
        progressBarData->setObjectName(QString::fromUtf8("progressBarData"));
        sizePolicy1.setHeightForWidth(progressBarData->sizePolicy().hasHeightForWidth());
        progressBarData->setSizePolicy(sizePolicy1);
        progressBarData->setMinimumSize(QSize(0, 0));
        progressBarData->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"border: 1px solid black;\n"
"text-align: center;\n"
"padding: 1px;\n"
"border-top-right-radius: 7px;\n"
"border-top-left-radius: 7px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"height:2\n"
"}\n"
"QProgressBar::chunk {\n"
"border-top-right-radius: 7px;\n"
"border-top-left-radius: 7px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"border: 1px solid black;\n"
"background-color:#46a\n"
"}"));
        progressBarData->setValue(0);
        progressBarData->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBarData->setOrientation(Qt::Horizontal);
        progressBarData->setFormat(QString::fromUtf8("%p%"));

        gridLayout_2->addWidget(progressBarData, 0, 1, 1, 7);

        lineEditDataSize = new QLineEdit(layoutWidget);
        lineEditDataSize->setObjectName(QString::fromUtf8("lineEditDataSize"));
        lineEditDataSize->setText(QString::fromUtf8(""));
        lineEditDataSize->setReadOnly(true);

        gridLayout_2->addWidget(lineEditDataSize, 1, 2, 1, 1);

        labelDataSize = new QLabel(layoutWidget);
        labelDataSize->setObjectName(QString::fromUtf8("labelDataSize"));

        gridLayout_2->addWidget(labelDataSize, 1, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setText(QString::fromUtf8("/data    "));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        labelDataUsed = new QLabel(layoutWidget);
        labelDataUsed->setObjectName(QString::fromUtf8("labelDataUsed"));

        gridLayout_2->addWidget(labelDataUsed, 1, 3, 1, 1);

        labelDataAvailable = new QLabel(layoutWidget);
        labelDataAvailable->setObjectName(QString::fromUtf8("labelDataAvailable"));

        gridLayout_2->addWidget(labelDataAvailable, 1, 5, 1, 2);


        gridLayout_7->addLayout(gridLayout_2, 3, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelSdcardSize = new QLabel(layoutWidget);
        labelSdcardSize->setObjectName(QString::fromUtf8("labelSdcardSize"));

        gridLayout->addWidget(labelSdcardSize, 1, 1, 1, 2);

        labelSdcardAvailable = new QLabel(layoutWidget);
        labelSdcardAvailable->setObjectName(QString::fromUtf8("labelSdcardAvailable"));

        gridLayout->addWidget(labelSdcardAvailable, 1, 6, 1, 1);

        lineEditSdcardAvailable = new QLineEdit(layoutWidget);
        lineEditSdcardAvailable->setObjectName(QString::fromUtf8("lineEditSdcardAvailable"));
        lineEditSdcardAvailable->setText(QString::fromUtf8(""));
        lineEditSdcardAvailable->setReadOnly(true);

        gridLayout->addWidget(lineEditSdcardAvailable, 1, 7, 1, 1);

        lineEditSdcardSize = new QLineEdit(layoutWidget);
        lineEditSdcardSize->setObjectName(QString::fromUtf8("lineEditSdcardSize"));
        lineEditSdcardSize->setText(QString::fromUtf8(""));
        lineEditSdcardSize->setReadOnly(true);

        gridLayout->addWidget(lineEditSdcardSize, 1, 3, 1, 1);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setText(QString::fromUtf8("/sdcard"));

        gridLayout->addWidget(label_17, 0, 0, 1, 1);

        lineEditSdcardUsed = new QLineEdit(layoutWidget);
        lineEditSdcardUsed->setObjectName(QString::fromUtf8("lineEditSdcardUsed"));
        lineEditSdcardUsed->setText(QString::fromUtf8(""));
        lineEditSdcardUsed->setReadOnly(true);

        gridLayout->addWidget(lineEditSdcardUsed, 1, 5, 1, 1);

        progressBarSdcard = new QProgressBar(layoutWidget);
        progressBarSdcard->setObjectName(QString::fromUtf8("progressBarSdcard"));
        sizePolicy1.setHeightForWidth(progressBarSdcard->sizePolicy().hasHeightForWidth());
        progressBarSdcard->setSizePolicy(sizePolicy1);
        progressBarSdcard->setMinimumSize(QSize(41, 0));
        progressBarSdcard->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"border: 1px solid black;\n"
"text-align: center;\n"
"padding: 1px;\n"
"border-top-right-radius: 7px;\n"
"border-top-left-radius: 7px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"height:2\n"
"}\n"
"QProgressBar::chunk {\n"
"border-top-right-radius: 7px;\n"
"border-top-left-radius: 7px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"border: 1px solid black;\n"
"background-color:#46a\n"
"}"));
        progressBarSdcard->setValue(0);
        progressBarSdcard->setOrientation(Qt::Horizontal);
        progressBarSdcard->setFormat(QString::fromUtf8("%p%"));

        gridLayout->addWidget(progressBarSdcard, 0, 1, 1, 7);

        labelSdcardUsed = new QLabel(layoutWidget);
        labelSdcardUsed->setObjectName(QString::fromUtf8("labelSdcardUsed"));

        gridLayout->addWidget(labelSdcardUsed, 1, 4, 1, 1);


        gridLayout_7->addLayout(gridLayout, 4, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_7->addWidget(label_2, 6, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelModel = new QLabel(layoutWidget);
        labelModel->setObjectName(QString::fromUtf8("labelModel"));

        gridLayout_3->addWidget(labelModel, 0, 0, 1, 1);

        lineEditModel = new QLineEdit(layoutWidget);
        lineEditModel->setObjectName(QString::fromUtf8("lineEditModel"));
        lineEditModel->setText(QString::fromUtf8(""));
        lineEditModel->setReadOnly(true);

        gridLayout_3->addWidget(lineEditModel, 0, 1, 1, 1);

        labelOperator = new QLabel(layoutWidget);
        labelOperator->setObjectName(QString::fromUtf8("labelOperator"));

        gridLayout_3->addWidget(labelOperator, 1, 0, 1, 1);

        lineEditNumber = new QLineEdit(layoutWidget);
        lineEditNumber->setObjectName(QString::fromUtf8("lineEditNumber"));
        lineEditNumber->setText(QString::fromUtf8(""));
        lineEditNumber->setReadOnly(true);

        gridLayout_3->addWidget(lineEditNumber, 3, 1, 1, 1);

        labelRadio = new QLabel(layoutWidget);
        labelRadio->setObjectName(QString::fromUtf8("labelRadio"));
        sizePolicy.setHeightForWidth(labelRadio->sizePolicy().hasHeightForWidth());
        labelRadio->setSizePolicy(sizePolicy);
        labelRadio->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(labelRadio, 5, 0, 1, 1);

        lineEditImei = new QLineEdit(layoutWidget);
        lineEditImei->setObjectName(QString::fromUtf8("lineEditImei"));
        lineEditImei->setText(QString::fromUtf8(""));
        lineEditImei->setReadOnly(true);

        gridLayout_3->addWidget(lineEditImei, 5, 1, 1, 1);

        lineEditMac = new QLineEdit(layoutWidget);
        lineEditMac->setObjectName(QString::fromUtf8("lineEditMac"));
        lineEditMac->setText(QString::fromUtf8(""));
        lineEditMac->setReadOnly(true);

        gridLayout_3->addWidget(lineEditMac, 4, 1, 1, 1);

        labelSerialNumber = new QLabel(layoutWidget);
        labelSerialNumber->setObjectName(QString::fromUtf8("labelSerialNumber"));

        gridLayout_3->addWidget(labelSerialNumber, 2, 0, 1, 1);

        labelMac = new QLabel(layoutWidget);
        labelMac->setObjectName(QString::fromUtf8("labelMac"));

        gridLayout_3->addWidget(labelMac, 4, 0, 1, 1);

        lineEditOperator = new QLineEdit(layoutWidget);
        lineEditOperator->setObjectName(QString::fromUtf8("lineEditOperator"));
        lineEditOperator->setText(QString::fromUtf8(""));
        lineEditOperator->setReadOnly(true);

        gridLayout_3->addWidget(lineEditOperator, 1, 1, 1, 1);

        labelNumber = new QLabel(layoutWidget);
        labelNumber->setObjectName(QString::fromUtf8("labelNumber"));

        gridLayout_3->addWidget(labelNumber, 3, 0, 1, 1);

        lineEditSerialNumber = new QLineEdit(layoutWidget);
        lineEditSerialNumber->setObjectName(QString::fromUtf8("lineEditSerialNumber"));
        lineEditSerialNumber->setText(QString::fromUtf8(""));
        lineEditSerialNumber->setReadOnly(true);

        gridLayout_3->addWidget(lineEditSerialNumber, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        progressBarBatteryLevel = new QProgressBar(layoutWidget);
        progressBarBatteryLevel->setObjectName(QString::fromUtf8("progressBarBatteryLevel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBarBatteryLevel->sizePolicy().hasHeightForWidth());
        progressBarBatteryLevel->setSizePolicy(sizePolicy2);
        progressBarBatteryLevel->setMinimumSize(QSize(67, 0));
        progressBarBatteryLevel->setCursor(QCursor(Qt::SizeBDiagCursor));
        progressBarBatteryLevel->setLayoutDirection(Qt::LeftToRight);
        progressBarBatteryLevel->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"border: 1px solid black;\n"
"text-align: center;\n"
"padding: 1px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #fff,\n"
"stop: 0.4999 #eee,\n"
"stop: 0.5 #ddd,\n"
"stop: 1 #eee );\n"
"width: 18px;\n"
"}\n"
"QProgressBar::chunk {\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #78d,\n"
"stop: 0.4999 #46a,\n"
"stop: 0.5 #45a,\n"
"stop: 1 #238 );\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"border: 1px solid black;\n"
"}"));
        progressBarBatteryLevel->setValue(0);
        progressBarBatteryLevel->setAlignment(Qt::AlignCenter);
        progressBarBatteryLevel->setOrientation(Qt::Vertical);
        progressBarBatteryLevel->setInvertedAppearance(false);
        progressBarBatteryLevel->setFormat(QString::fromUtf8("%p%"));

        gridLayout_5->addWidget(progressBarBatteryLevel, 0, 2, 1, 1);

        labelBatteryLevel = new QLabel(layoutWidget);
        labelBatteryLevel->setObjectName(QString::fromUtf8("labelBatteryLevel"));
        labelBatteryLevel->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(labelBatteryLevel, 0, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout_5);


        gridLayout_7->addLayout(horizontalLayout, 1, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        labelRgb565 = new QLabel(layoutWidget);
        labelRgb565->setObjectName(QString::fromUtf8("labelRgb565"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelRgb565->sizePolicy().hasHeightForWidth());
        labelRgb565->setSizePolicy(sizePolicy3);
        labelRgb565->setBaseSize(QSize(150, 228));
        labelRgb565->setLayoutDirection(Qt::LeftToRight);
        labelRgb565->setFrameShape(QFrame::Box);
        labelRgb565->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelRgb565, 0, 1, 1, 2);

        buttonRefreshScreenshot = new QPushButton(layoutWidget);
        buttonRefreshScreenshot->setObjectName(QString::fromUtf8("buttonRefreshScreenshot"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRefreshScreenshot->setIcon(icon);

        gridLayout_4->addWidget(buttonRefreshScreenshot, 1, 1, 1, 1);

        buttonSaveScreenshot = new QPushButton(layoutWidget);
        buttonSaveScreenshot->setObjectName(QString::fromUtf8("buttonSaveScreenshot"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonSaveScreenshot->setIcon(icon1);

        gridLayout_4->addWidget(buttonSaveScreenshot, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(17, 0));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 1, 0, 5, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_7->addWidget(label_3, 0, 0, 1, 2);


        retranslateUi(PhoneInfoWidget);

        QMetaObject::connectSlotsByName(PhoneInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *PhoneInfoWidget)
    {
        labelSdcardUsed_2->setText(QApplication::translate("PhoneInfoWidget", "used:", 0, QApplication::UnicodeUTF8));
        labelSdcardSize_2->setText(QApplication::translate("PhoneInfoWidget", "size:", 0, QApplication::UnicodeUTF8));
        labelSdcardAvailable_2->setText(QApplication::translate("PhoneInfoWidget", "available:", 0, QApplication::UnicodeUTF8));
        labelDataSize->setText(QApplication::translate("PhoneInfoWidget", "size:", 0, QApplication::UnicodeUTF8));
        labelDataUsed->setText(QApplication::translate("PhoneInfoWidget", "used:", 0, QApplication::UnicodeUTF8));
        labelDataAvailable->setText(QApplication::translate("PhoneInfoWidget", "available:", 0, QApplication::UnicodeUTF8));
        labelSdcardSize->setText(QApplication::translate("PhoneInfoWidget", "size:", 0, QApplication::UnicodeUTF8));
        labelSdcardAvailable->setText(QApplication::translate("PhoneInfoWidget", "available:", 0, QApplication::UnicodeUTF8));
        labelSdcardUsed->setText(QApplication::translate("PhoneInfoWidget", "used:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        labelModel->setText(QApplication::translate("PhoneInfoWidget", "Model", 0, QApplication::UnicodeUTF8));
        labelOperator->setText(QApplication::translate("PhoneInfoWidget", "Operator", 0, QApplication::UnicodeUTF8));
        labelRadio->setText(QApplication::translate("PhoneInfoWidget", "IMEI", 0, QApplication::UnicodeUTF8));
        labelSerialNumber->setText(QApplication::translate("PhoneInfoWidget", "Serial number", 0, QApplication::UnicodeUTF8));
        labelMac->setText(QApplication::translate("PhoneInfoWidget", "Mac", 0, QApplication::UnicodeUTF8));
        labelNumber->setText(QApplication::translate("PhoneInfoWidget", "Number", 0, QApplication::UnicodeUTF8));
        labelBatteryLevel->setText(QApplication::translate("PhoneInfoWidget", "Battery level", 0, QApplication::UnicodeUTF8));
        labelRgb565->setText(QString());
        buttonRefreshScreenshot->setText(QApplication::translate("PhoneInfoWidget", "Refresh", 0, QApplication::UnicodeUTF8));
        buttonSaveScreenshot->setText(QApplication::translate("PhoneInfoWidget", "Save", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_3->setText(QString());
        Q_UNUSED(PhoneInfoWidget);
    } // retranslateUi

};

namespace Ui {
    class PhoneInfoWidget: public Ui_PhoneInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEINFOWIDGET_H
