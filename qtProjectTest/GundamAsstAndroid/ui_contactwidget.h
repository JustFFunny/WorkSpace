/********************************************************************************
** Form generated from reading UI file 'contactwidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTWIDGET_H
#define UI_CONTACTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactWidget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_11;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_47;
    QLabel *labelAppsIcon;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QLineEdit *lineEditContactsId;
    QLineEdit *lineEditContactsName;
    QLineEdit *lineEditContactsNumber;

    void setupUi(QWidget *ContactWidget)
    {
        if (ContactWidget->objectName().isEmpty())
            ContactWidget->setObjectName(QString::fromUtf8("ContactWidget"));
        ContactWidget->resize(735, 539);
        widget = new QWidget(ContactWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 711, 521));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout->addWidget(tableWidget);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_26 = new QLabel(widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setText(QString::fromUtf8("Number:"));

        gridLayout_2->addWidget(label_26, 4, 1, 1, 1);

        label_28 = new QLabel(widget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setText(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_28, 6, 0, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setText(QString::fromUtf8("Name    :"));

        gridLayout_2->addWidget(label_11, 3, 1, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setText(QString::fromUtf8("ID            :"));

        gridLayout_2->addWidget(label_9, 2, 1, 1, 1);

        verticalSpacer_47 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_47, 7, 1, 1, 1);

        labelAppsIcon = new QLabel(widget);
        labelAppsIcon->setObjectName(QString::fromUtf8("labelAppsIcon"));
        labelAppsIcon->setMinimumSize(QSize(72, 72));
        labelAppsIcon->setMaximumSize(QSize(72, 72));
        labelAppsIcon->setText(QString::fromUtf8(""));
        labelAppsIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/contactDefault.png")));
        labelAppsIcon->setScaledContents(true);

        gridLayout_2->addWidget(labelAppsIcon, 1, 1, 1, 1);

        pushButton_add = new QPushButton(widget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/install.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_add->setIcon(icon);

        gridLayout_2->addWidget(pushButton_add, 6, 1, 1, 1);

        pushButton_del = new QPushButton(widget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/uninstall.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_del->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_del, 6, 2, 1, 1);

        lineEditContactsId = new QLineEdit(widget);
        lineEditContactsId->setObjectName(QString::fromUtf8("lineEditContactsId"));
        lineEditContactsId->setReadOnly(true);

        gridLayout_2->addWidget(lineEditContactsId, 2, 2, 1, 2);

        lineEditContactsName = new QLineEdit(widget);
        lineEditContactsName->setObjectName(QString::fromUtf8("lineEditContactsName"));
        lineEditContactsName->setReadOnly(true);

        gridLayout_2->addWidget(lineEditContactsName, 3, 2, 1, 2);

        lineEditContactsNumber = new QLineEdit(widget);
        lineEditContactsNumber->setObjectName(QString::fromUtf8("lineEditContactsNumber"));
        lineEditContactsNumber->setReadOnly(true);

        gridLayout_2->addWidget(lineEditContactsNumber, 4, 2, 1, 2);


        horizontalLayout->addLayout(gridLayout_2);


        retranslateUi(ContactWidget);

        QMetaObject::connectSlotsByName(ContactWidget);
    } // setupUi

    void retranslateUi(QWidget *ContactWidget)
    {
        ContactWidget->setWindowTitle(QApplication::translate("ContactWidget", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("ContactWidget", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("ContactWidget", "Number", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("ContactWidget", "Remark", 0, QApplication::UnicodeUTF8));
        pushButton_add->setText(QApplication::translate("ContactWidget", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_del->setText(QApplication::translate("ContactWidget", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactWidget: public Ui_ContactWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTWIDGET_H
