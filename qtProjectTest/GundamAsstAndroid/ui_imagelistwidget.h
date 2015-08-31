/********************************************************************************
** Form generated from reading UI file 'imagelistwidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGELISTWIDGET_H
#define UI_IMAGELISTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageListWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_show;
    QLabel *label_Title;
    QPushButton *pushButton_import;
    QPushButton *pushButton_export;
    QLabel *label_image;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_info;
    QProgressBar *progressBar;
    QLabel *label_num;

    void setupUi(QWidget *ImageListWidget)
    {
        if (ImageListWidget->objectName().isEmpty())
            ImageListWidget->setObjectName(QString::fromUtf8("ImageListWidget"));
        ImageListWidget->resize(753, 551);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageListWidget->sizePolicy().hasHeightForWidth());
        ImageListWidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(ImageListWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 741, 531));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_show = new QPushButton(layoutWidget);
        pushButton_show->setObjectName(QString::fromUtf8("pushButton_show"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_show->sizePolicy().hasHeightForWidth());
        pushButton_show->setSizePolicy(sizePolicy1);
        pushButton_show->setMinimumSize(QSize(0, 0));
        pushButton_show->setMaximumSize(QSize(30, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/show.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_show->setIcon(icon);

        horizontalLayout->addWidget(pushButton_show);

        label_Title = new QLabel(layoutWidget);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Title);

        pushButton_import = new QPushButton(layoutWidget);
        pushButton_import->setObjectName(QString::fromUtf8("pushButton_import"));
        pushButton_import->setMaximumSize(QSize(100, 25));

        horizontalLayout->addWidget(pushButton_import);

        pushButton_export = new QPushButton(layoutWidget);
        pushButton_export->setObjectName(QString::fromUtf8("pushButton_export"));
        pushButton_export->setMaximumSize(QSize(100, 25));

        horizontalLayout->addWidget(pushButton_export);


        verticalLayout->addLayout(horizontalLayout);

        label_image = new QLabel(layoutWidget);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setMinimumSize(QSize(0, 382));
        label_image->setFrameShape(QFrame::Panel);

        verticalLayout->addWidget(label_image);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);
        listWidget->setMinimumSize(QSize(0, 76));
        listWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_info = new QLabel(layoutWidget);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_info->sizePolicy().hasHeightForWidth());
        label_info->setSizePolicy(sizePolicy3);
        label_info->setMinimumSize(QSize(0, 0));
        label_info->setMaximumSize(QSize(16777215, 20));
        label_info->setFrameShape(QFrame::NoFrame);

        horizontalLayout_2->addWidget(label_info);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy4);
        progressBar->setMaximumSize(QSize(150, 20));
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        horizontalLayout_2->addWidget(progressBar);

        label_num = new QLabel(layoutWidget);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        sizePolicy3.setHeightForWidth(label_num->sizePolicy().hasHeightForWidth());
        label_num->setSizePolicy(sizePolicy3);
        label_num->setMinimumSize(QSize(0, 0));
        label_num->setMaximumSize(QSize(120, 20));
        label_num->setFrameShape(QFrame::NoFrame);
        label_num->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_num);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ImageListWidget);

        QMetaObject::connectSlotsByName(ImageListWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageListWidget)
    {
        ImageListWidget->setWindowTitle(QApplication::translate("ImageListWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_show->setText(QString());
        label_Title->setText(QString());
        pushButton_import->setText(QApplication::translate("ImageListWidget", "import", 0, QApplication::UnicodeUTF8));
        pushButton_export->setText(QApplication::translate("ImageListWidget", "export", 0, QApplication::UnicodeUTF8));
        label_image->setText(QString());
        label_info->setText(QString());
        label_num->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageListWidget: public Ui_ImageListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGELISTWIDGET_H
