/********************************************************************************
** Form generated from reading UI file 'imagewidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIDGET_H
#define UI_IMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWidget
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton_in;
    QPushButton *pushButton_out;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *msg_label;

    void setupUi(QWidget *ImageWidget)
    {
        if (ImageWidget->objectName().isEmpty())
            ImageWidget->setObjectName(QString::fromUtf8("ImageWidget"));
        ImageWidget->resize(822, 504);
        tableWidget = new QTableWidget(ImageWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 261, 441));
        pushButton_in = new QPushButton(ImageWidget);
        pushButton_in->setObjectName(QString::fromUtf8("pushButton_in"));
        pushButton_in->setGeometry(QRect(20, 470, 98, 27));
        pushButton_out = new QPushButton(ImageWidget);
        pushButton_out->setObjectName(QString::fromUtf8("pushButton_out"));
        pushButton_out->setGeometry(QRect(170, 470, 98, 27));
        label = new QLabel(ImageWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 20, 491, 421));
        label->setFrameShape(QFrame::Box);
        progressBar = new QProgressBar(ImageWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(320, 470, 341, 23));
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        msg_label = new QLabel(ImageWidget);
        msg_label->setObjectName(QString::fromUtf8("msg_label"));
        msg_label->setGeometry(QRect(680, 470, 101, 21));

        retranslateUi(ImageWidget);

        QMetaObject::connectSlotsByName(ImageWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageWidget)
    {
        ImageWidget->setWindowTitle(QApplication::translate("ImageWidget", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ImageWidget", "num", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ImageWidget", "Title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ImageWidget", "size", 0, QApplication::UnicodeUTF8));
        pushButton_in->setText(QApplication::translate("ImageWidget", "import", 0, QApplication::UnicodeUTF8));
        pushButton_out->setText(QApplication::translate("ImageWidget", "export", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        msg_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageWidget: public Ui_ImageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIDGET_H
