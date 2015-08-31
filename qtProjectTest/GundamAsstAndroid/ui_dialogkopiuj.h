/********************************************************************************
** Form generated from reading UI file 'dialogkopiuj.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGKOPIUJ_H
#define UI_DIALOGKOPIUJ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogKopiuj
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *labelFile;
    QLabel *label_2;
    QLabel *labelFrom;
    QLabel *label;
    QLabel *labelTo;
    QLabel *label_5;
    QLabel *labelRemain;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QProgressBar *progressFile;
    QLabel *label_7;
    QProgressBar *progressTotal;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonCancel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *dialogKopiuj)
    {
        if (dialogKopiuj->objectName().isEmpty())
            dialogKopiuj->setObjectName(QString::fromUtf8("dialogKopiuj"));
        dialogKopiuj->resize(333, 180);
        gridLayoutWidget = new QWidget(dialogKopiuj);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 321, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        labelFile = new QLabel(gridLayoutWidget);
        labelFile->setObjectName(QString::fromUtf8("labelFile"));
        labelFile->setText(QString::fromUtf8("TextLabel"));

        gridLayout->addWidget(labelFile, 1, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        labelFrom = new QLabel(gridLayoutWidget);
        labelFrom->setObjectName(QString::fromUtf8("labelFrom"));
        labelFrom->setText(QString::fromUtf8("TextLabel"));

        gridLayout->addWidget(labelFrom, 2, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        labelTo = new QLabel(gridLayoutWidget);
        labelTo->setObjectName(QString::fromUtf8("labelTo"));
        labelTo->setText(QString::fromUtf8("TextLabel"));

        gridLayout->addWidget(labelTo, 3, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        labelRemain = new QLabel(gridLayoutWidget);
        labelRemain->setObjectName(QString::fromUtf8("labelRemain"));
        labelRemain->setText(QString::fromUtf8("TextLabel"));

        gridLayout->addWidget(labelRemain, 4, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        progressFile = new QProgressBar(gridLayoutWidget);
        progressFile->setObjectName(QString::fromUtf8("progressFile"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        progressFile->setPalette(palette);
        progressFile->setAcceptDrops(false);
        progressFile->setValue(0);
        progressFile->setAlignment(Qt::AlignCenter);
        progressFile->setFormat(QString::fromUtf8("%p%"));

        gridLayout_2->addWidget(progressFile, 0, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        progressTotal = new QProgressBar(gridLayoutWidget);
        progressTotal->setObjectName(QString::fromUtf8("progressTotal"));
        progressTotal->setValue(0);
        progressTotal->setAlignment(Qt::AlignCenter);
        progressTotal->setFormat(QString::fromUtf8("%p%"));

        gridLayout_2->addWidget(progressTotal, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 1, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_4->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        buttonCancel = new QPushButton(gridLayoutWidget);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        horizontalLayout_4->addWidget(buttonCancel);


        gridLayout->addLayout(horizontalLayout_4, 6, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 7, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 10);

        retranslateUi(dialogKopiuj);

        QMetaObject::connectSlotsByName(dialogKopiuj);
    } // setupUi

    void retranslateUi(QDialog *dialogKopiuj)
    {
        dialogKopiuj->setWindowTitle(QApplication::translate("dialogKopiuj", "Copying", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dialogKopiuj", "file:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialogKopiuj", "from:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialogKopiuj", "to:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dialogKopiuj", "items remaining:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("dialogKopiuj", "File:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("dialogKopiuj", "Total:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("dialogKopiuj", "close after finished", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("dialogKopiuj", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialogKopiuj: public Ui_dialogKopiuj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGKOPIUJ_H
