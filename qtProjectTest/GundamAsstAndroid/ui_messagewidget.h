/********************************************************************************
** Form generated from reading UI file 'messagewidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEWIDGET_H
#define UI_MESSAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *layoutMessages;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_34;
    QSpacerItem *verticalSpacer_48;
    QSpacerItem *verticalSpacer_49;
    QPushButton *pushButton;

    void setupUi(QWidget *MessageWidget)
    {
        if (MessageWidget->objectName().isEmpty())
            MessageWidget->setObjectName(QString::fromUtf8("MessageWidget"));
        MessageWidget->resize(711, 501);
        MessageWidget->setWindowTitle(QString::fromUtf8("Form"));
        layoutWidget = new QWidget(MessageWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 561, 411));
        layoutMessages = new QGridLayout(layoutWidget);
        layoutMessages->setObjectName(QString::fromUtf8("layoutMessages"));
        layoutMessages->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        layoutMessages->addWidget(line_2, 1, 0, 1, 1);

        horizontalSpacer_34 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutMessages->addItem(horizontalSpacer_34, 1, 3, 1, 1);

        verticalSpacer_48 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutMessages->addItem(verticalSpacer_48, 0, 1, 1, 1);

        verticalSpacer_49 = new QSpacerItem(13, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutMessages->addItem(verticalSpacer_49, 4, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFocusPolicy(Qt::ClickFocus);

        layoutMessages->addWidget(pushButton, 3, 1, 1, 1);


        retranslateUi(MessageWidget);

        QMetaObject::connectSlotsByName(MessageWidget);
    } // setupUi

    void retranslateUi(QWidget *MessageWidget)
    {
        pushButton->setText(QApplication::translate("MessageWidget", "refresh list", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MessageWidget);
    } // retranslateUi

};

namespace Ui {
    class MessageWidget: public Ui_MessageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEWIDGET_H
