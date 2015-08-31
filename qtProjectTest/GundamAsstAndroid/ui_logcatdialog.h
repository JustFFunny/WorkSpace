/********************************************************************************
** Form generated from reading UI file 'logcatdialog.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGCATDIALOG_H
#define UI_LOGCATDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogcatDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *layoutLogcat;
    QCheckBox *checkBoxDebug;
    QCheckBox *checkBoxWarnings;
    QCheckBox *checkBoxInformations;
    QCheckBox *checkBoxErrors;
    QTableView *tableView;
    QTextBrowser *textBrowser;
    QCheckBox *checkBoxVerbose;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *spinBoxBufferLimit;
    QLabel *label;
    QCheckBox *checkBoxAutoScroll;
    QPushButton *pushButtonClearLogcat;

    void setupUi(QDialog *LogcatDialog)
    {
        if (LogcatDialog->objectName().isEmpty())
            LogcatDialog->setObjectName(QString::fromUtf8("LogcatDialog"));
        LogcatDialog->resize(604, 445);
        gridLayoutWidget = new QWidget(LogcatDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 591, 431));
        layoutLogcat = new QGridLayout(gridLayoutWidget);
        layoutLogcat->setObjectName(QString::fromUtf8("layoutLogcat"));
        layoutLogcat->setContentsMargins(0, 0, 0, 0);
        checkBoxDebug = new QCheckBox(gridLayoutWidget);
        checkBoxDebug->setObjectName(QString::fromUtf8("checkBoxDebug"));
        checkBoxDebug->setChecked(true);

        layoutLogcat->addWidget(checkBoxDebug, 1, 1, 1, 1);

        checkBoxWarnings = new QCheckBox(gridLayoutWidget);
        checkBoxWarnings->setObjectName(QString::fromUtf8("checkBoxWarnings"));
        checkBoxWarnings->setChecked(true);

        layoutLogcat->addWidget(checkBoxWarnings, 1, 3, 1, 1);

        checkBoxInformations = new QCheckBox(gridLayoutWidget);
        checkBoxInformations->setObjectName(QString::fromUtf8("checkBoxInformations"));
        checkBoxInformations->setChecked(true);

        layoutLogcat->addWidget(checkBoxInformations, 1, 2, 1, 1);

        checkBoxErrors = new QCheckBox(gridLayoutWidget);
        checkBoxErrors->setObjectName(QString::fromUtf8("checkBoxErrors"));
        checkBoxErrors->setChecked(true);

        layoutLogcat->addWidget(checkBoxErrors, 1, 4, 1, 1);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setDragDropOverwriteMode(false);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setWordWrap(false);
        tableView->setCornerButtonEnabled(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        layoutLogcat->addWidget(tableView, 4, 1, 1, 10);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setFocusPolicy(Qt::ClickFocus);

        layoutLogcat->addWidget(textBrowser, 5, 1, 1, 10);

        checkBoxVerbose = new QCheckBox(gridLayoutWidget);
        checkBoxVerbose->setObjectName(QString::fromUtf8("checkBoxVerbose"));
        checkBoxVerbose->setChecked(true);

        layoutLogcat->addWidget(checkBoxVerbose, 1, 5, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        layoutLogcat->addWidget(lineEdit, 2, 1, 1, 3);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        layoutLogcat->addWidget(comboBox, 2, 4, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutLogcat->addItem(horizontalSpacer, 2, 10, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutLogcat->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layoutLogcat->addItem(verticalSpacer_2, 6, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutLogcat->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layoutLogcat->addItem(horizontalSpacer_3, 4, 11, 1, 1);

        spinBoxBufferLimit = new QSpinBox(gridLayoutWidget);
        spinBoxBufferLimit->setObjectName(QString::fromUtf8("spinBoxBufferLimit"));
        spinBoxBufferLimit->setMaximum(9999);

        layoutLogcat->addWidget(spinBoxBufferLimit, 2, 7, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        layoutLogcat->addWidget(label, 1, 7, 1, 1);

        checkBoxAutoScroll = new QCheckBox(gridLayoutWidget);
        checkBoxAutoScroll->setObjectName(QString::fromUtf8("checkBoxAutoScroll"));

        layoutLogcat->addWidget(checkBoxAutoScroll, 2, 8, 1, 1);

        pushButtonClearLogcat = new QPushButton(gridLayoutWidget);
        pushButtonClearLogcat->setObjectName(QString::fromUtf8("pushButtonClearLogcat"));
        pushButtonClearLogcat->setFocusPolicy(Qt::NoFocus);

        layoutLogcat->addWidget(pushButtonClearLogcat, 2, 9, 1, 1);


        retranslateUi(LogcatDialog);

        QMetaObject::connectSlotsByName(LogcatDialog);
    } // setupUi

    void retranslateUi(QDialog *LogcatDialog)
    {
        LogcatDialog->setWindowTitle(QApplication::translate("LogcatDialog", "Logcat", 0, QApplication::UnicodeUTF8));
        checkBoxDebug->setText(QApplication::translate("LogcatDialog", "Debug", 0, QApplication::UnicodeUTF8));
        checkBoxWarnings->setText(QApplication::translate("LogcatDialog", "Warning", 0, QApplication::UnicodeUTF8));
        checkBoxInformations->setText(QApplication::translate("LogcatDialog", "Information", 0, QApplication::UnicodeUTF8));
        checkBoxErrors->setText(QApplication::translate("LogcatDialog", "Error", 0, QApplication::UnicodeUTF8));
        checkBoxVerbose->setText(QApplication::translate("LogcatDialog", "Verbose", 0, QApplication::UnicodeUTF8));
        lineEdit->setPlaceholderText(QApplication::translate("LogcatDialog", "filter", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LogcatDialog", "Sender", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogcatDialog", "Message", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("LogcatDialog", "Buffer limit", 0, QApplication::UnicodeUTF8));
        checkBoxAutoScroll->setText(QApplication::translate("LogcatDialog", "autoscroll", 0, QApplication::UnicodeUTF8));
        pushButtonClearLogcat->setText(QApplication::translate("LogcatDialog", "clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogcatDialog: public Ui_LogcatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGCATDIALOG_H
