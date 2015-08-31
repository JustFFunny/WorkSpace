/********************************************************************************
** Form generated from reading UI file 'screenshotwidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOTWIDGET_H
#define UI_SCREENSHOTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenshotWidget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *layoutScreenshot;
    QLabel *labelRgb565;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_8;
    QVBoxLayout *verticalLayout_3;
    QPushButton *buttonRefreshScreenshot;
    QPushButton *buttonSaveScreenshot;
    QPushButton *buttonRotateLeft;
    QPushButton *buttonRotateRight;
    QSpacerItem *verticalSpacer_11;

    void setupUi(QWidget *ScreenshotWidget)
    {
        if (ScreenshotWidget->objectName().isEmpty())
            ScreenshotWidget->setObjectName(QString::fromUtf8("ScreenshotWidget"));
        ScreenshotWidget->resize(512, 399);
        ScreenshotWidget->setWindowTitle(QString::fromUtf8("Form"));
        gridLayoutWidget = new QWidget(ScreenshotWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 291, 241));
        layoutScreenshot = new QGridLayout(gridLayoutWidget);
        layoutScreenshot->setObjectName(QString::fromUtf8("layoutScreenshot"));
        layoutScreenshot->setContentsMargins(0, 0, 0, 0);
        labelRgb565 = new QLabel(gridLayoutWidget);
        labelRgb565->setObjectName(QString::fromUtf8("labelRgb565"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelRgb565->sizePolicy().hasHeightForWidth());
        labelRgb565->setSizePolicy(sizePolicy);
        labelRgb565->setText(QString::fromUtf8(""));

        layoutScreenshot->addWidget(labelRgb565, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutScreenshot->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutScreenshot->addItem(verticalSpacer_8, 0, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        buttonRefreshScreenshot = new QPushButton(gridLayoutWidget);
        buttonRefreshScreenshot->setObjectName(QString::fromUtf8("buttonRefreshScreenshot"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRefreshScreenshot->setIcon(icon);

        verticalLayout_3->addWidget(buttonRefreshScreenshot);

        buttonSaveScreenshot = new QPushButton(gridLayoutWidget);
        buttonSaveScreenshot->setObjectName(QString::fromUtf8("buttonSaveScreenshot"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonSaveScreenshot->setIcon(icon1);

        verticalLayout_3->addWidget(buttonSaveScreenshot);

        buttonRotateLeft = new QPushButton(gridLayoutWidget);
        buttonRotateLeft->setObjectName(QString::fromUtf8("buttonRotateLeft"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/rotate-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRotateLeft->setIcon(icon2);

        verticalLayout_3->addWidget(buttonRotateLeft);

        buttonRotateRight = new QPushButton(gridLayoutWidget);
        buttonRotateRight->setObjectName(QString::fromUtf8("buttonRotateRight"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/rotate-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRotateRight->setIcon(icon3);

        verticalLayout_3->addWidget(buttonRotateRight);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_11);


        layoutScreenshot->addLayout(verticalLayout_3, 1, 1, 1, 1);

        layoutScreenshot->setColumnStretch(1, 1);
        layoutScreenshot->setColumnStretch(2, 100);

        retranslateUi(ScreenshotWidget);

        QMetaObject::connectSlotsByName(ScreenshotWidget);
    } // setupUi

    void retranslateUi(QWidget *ScreenshotWidget)
    {
        buttonRefreshScreenshot->setText(QApplication::translate("ScreenshotWidget", "Refresh", 0, QApplication::UnicodeUTF8));
        buttonSaveScreenshot->setText(QApplication::translate("ScreenshotWidget", "Save", 0, QApplication::UnicodeUTF8));
        buttonRotateLeft->setText(QApplication::translate("ScreenshotWidget", "Rotate left", 0, QApplication::UnicodeUTF8));
        buttonRotateRight->setText(QApplication::translate("ScreenshotWidget", "Rotate right", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ScreenshotWidget);
    } // retranslateUi

};

namespace Ui {
    class ScreenshotWidget: public Ui_ScreenshotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOTWIDGET_H
