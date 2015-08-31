/********************************************************************************
** Form generated from reading UI file 'audiowidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOWIDGET_H
#define UI_AUDIOWIDGET_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_all;
    QRadioButton *radioButton_mine;
    QRadioButton *radioButton_other;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *editTitle;
    QLineEdit *editSize;
    QLabel *labelAppsLocation;
    QLineEdit *editName;
    QLabel *labelAppsFileName;
    QLabel *labelIcon;
    QLabel *labelQRcode;
    QLineEdit *editDuration;
    QLineEdit *editAtist;
    QLabel *labelAppsPackageName;
    QLabel *labelName;
    QLabel *labelVersion;
    QLabel *labelAppsSize;
    QLineEdit *editFilePath;
    QPushButton *pushButton_in;
    QPushButton *pushButton_out;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_refresh;
    QProgressBar *progressBar;
    QLabel *msg_label;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AudioWidget)
    {
        if (AudioWidget->objectName().isEmpty())
            AudioWidget->setObjectName(QString::fromUtf8("AudioWidget"));
        AudioWidget->resize(735, 555);
        widget = new QWidget(AudioWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 1, 711, 596));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_all = new QRadioButton(widget);
        radioButton_all->setObjectName(QString::fromUtf8("radioButton_all"));
        radioButton_all->setMaximumSize(QSize(116, 16777215));

        horizontalLayout_2->addWidget(radioButton_all);

        radioButton_mine = new QRadioButton(widget);
        radioButton_mine->setObjectName(QString::fromUtf8("radioButton_mine"));
        radioButton_mine->setMaximumSize(QSize(116, 16777215));

        horizontalLayout_2->addWidget(radioButton_mine);

        radioButton_other = new QRadioButton(widget);
        radioButton_other->setObjectName(QString::fromUtf8("radioButton_other"));
        radioButton_other->setMaximumSize(QSize(116, 16777215));

        horizontalLayout_2->addWidget(radioButton_other);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(501, 0));

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        editTitle = new QLineEdit(widget);
        editTitle->setObjectName(QString::fromUtf8("editTitle"));
        editTitle->setMaximumSize(QSize(104, 16777215));
        editTitle->setText(QString::fromUtf8(""));
        editTitle->setReadOnly(true);

        gridLayout->addWidget(editTitle, 1, 2, 1, 1);

        editSize = new QLineEdit(widget);
        editSize->setObjectName(QString::fromUtf8("editSize"));
        editSize->setMaximumSize(QSize(199, 16777215));
        editSize->setText(QString::fromUtf8(""));
        editSize->setReadOnly(true);

        gridLayout->addWidget(editSize, 9, 0, 1, 3);

        labelAppsLocation = new QLabel(widget);
        labelAppsLocation->setObjectName(QString::fromUtf8("labelAppsLocation"));
        labelAppsLocation->setMaximumSize(QSize(199, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelAppsLocation->setFont(font);

        gridLayout->addWidget(labelAppsLocation, 10, 0, 1, 3);

        editName = new QLineEdit(widget);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setMaximumSize(QSize(104, 16777215));
        editName->setText(QString::fromUtf8(""));
        editName->setReadOnly(true);

        gridLayout->addWidget(editName, 3, 2, 1, 1);

        labelAppsFileName = new QLabel(widget);
        labelAppsFileName->setObjectName(QString::fromUtf8("labelAppsFileName"));
        labelAppsFileName->setMaximumSize(QSize(199, 16777215));
        labelAppsFileName->setFont(font);

        gridLayout->addWidget(labelAppsFileName, 6, 0, 1, 3);

        labelIcon = new QLabel(widget);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setMinimumSize(QSize(72, 72));
        labelIcon->setMaximumSize(QSize(72, 72));
        labelIcon->setText(QString::fromUtf8(""));
        labelIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/info.png")));
        labelIcon->setScaledContents(true);

        gridLayout->addWidget(labelIcon, 1, 0, 3, 1);

        labelQRcode = new QLabel(widget);
        labelQRcode->setObjectName(QString::fromUtf8("labelQRcode"));
        labelQRcode->setMaximumSize(QSize(9, 72));
        labelQRcode->setText(QString::fromUtf8(""));
        labelQRcode->setScaledContents(true);

        gridLayout->addWidget(labelQRcode, 1, 1, 1, 1);

        editDuration = new QLineEdit(widget);
        editDuration->setObjectName(QString::fromUtf8("editDuration"));
        editDuration->setMaximumSize(QSize(199, 16777215));
        editDuration->setReadOnly(true);

        gridLayout->addWidget(editDuration, 11, 0, 1, 3);

        editAtist = new QLineEdit(widget);
        editAtist->setObjectName(QString::fromUtf8("editAtist"));
        editAtist->setMaximumSize(QSize(199, 16777215));
        editAtist->setText(QString::fromUtf8(""));
        editAtist->setReadOnly(true);

        gridLayout->addWidget(editAtist, 5, 0, 1, 3);

        labelAppsPackageName = new QLabel(widget);
        labelAppsPackageName->setObjectName(QString::fromUtf8("labelAppsPackageName"));
        labelAppsPackageName->setMaximumSize(QSize(199, 16777215));
        labelAppsPackageName->setFont(font);

        gridLayout->addWidget(labelAppsPackageName, 4, 0, 1, 3);

        labelName = new QLabel(widget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setMaximumSize(QSize(104, 16777215));
        labelName->setFont(font);

        gridLayout->addWidget(labelName, 0, 2, 1, 1);

        labelVersion = new QLabel(widget);
        labelVersion->setObjectName(QString::fromUtf8("labelVersion"));
        labelVersion->setMaximumSize(QSize(104, 16777215));
        labelVersion->setFont(font);

        gridLayout->addWidget(labelVersion, 2, 2, 1, 1);

        labelAppsSize = new QLabel(widget);
        labelAppsSize->setObjectName(QString::fromUtf8("labelAppsSize"));
        labelAppsSize->setMaximumSize(QSize(199, 16777215));
        labelAppsSize->setFont(font);

        gridLayout->addWidget(labelAppsSize, 8, 0, 1, 3);

        editFilePath = new QLineEdit(widget);
        editFilePath->setObjectName(QString::fromUtf8("editFilePath"));
        editFilePath->setMaximumSize(QSize(199, 16777215));
        editFilePath->setText(QString::fromUtf8(""));
        editFilePath->setReadOnly(true);

        gridLayout->addWidget(editFilePath, 7, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);

        pushButton_in = new QPushButton(widget);
        pushButton_in->setObjectName(QString::fromUtf8("pushButton_in"));
        pushButton_in->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_in);

        pushButton_out = new QPushButton(widget);
        pushButton_out->setObjectName(QString::fromUtf8("pushButton_out"));
        pushButton_out->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_out);

        pushButton_delete = new QPushButton(widget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_delete);

        pushButton_refresh = new QPushButton(widget);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));
        pushButton_refresh->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_refresh);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximumSize(QSize(199, 16777215));
        progressBar->setAutoFillBackground(false);
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        msg_label = new QLabel(widget);
        msg_label->setObjectName(QString::fromUtf8("msg_label"));
        msg_label->setMaximumSize(QSize(199, 16777215));
        msg_label->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(msg_label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        radioButton_mine->raise();
        radioButton_all->raise();
        radioButton_other->raise();
        label->raise();

        retranslateUi(AudioWidget);

        QMetaObject::connectSlotsByName(AudioWidget);
    } // setupUi

    void retranslateUi(QWidget *AudioWidget)
    {
        AudioWidget->setWindowTitle(QApplication::translate("AudioWidget", "Form", 0, QApplication::UnicodeUTF8));
        radioButton_all->setText(QApplication::translate("AudioWidget", "all", 0, QApplication::UnicodeUTF8));
        radioButton_mine->setText(QApplication::translate("AudioWidget", "mine", 0, QApplication::UnicodeUTF8));
        radioButton_other->setText(QApplication::translate("AudioWidget", "other", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AudioWidget", "Num", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AudioWidget", "Title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AudioWidget", "Artist", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AudioWidget", "Size", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("AudioWidget", "Time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("AudioWidget", "File", 0, QApplication::UnicodeUTF8));
        labelAppsLocation->setText(QApplication::translate("AudioWidget", "Duration", 0, QApplication::UnicodeUTF8));
        labelAppsFileName->setText(QApplication::translate("AudioWidget", "File Path", 0, QApplication::UnicodeUTF8));
        labelAppsPackageName->setText(QApplication::translate("AudioWidget", "Artist", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("AudioWidget", "Title", 0, QApplication::UnicodeUTF8));
        labelVersion->setText(QApplication::translate("AudioWidget", "File Name", 0, QApplication::UnicodeUTF8));
        labelAppsSize->setText(QApplication::translate("AudioWidget", "Size", 0, QApplication::UnicodeUTF8));
        pushButton_in->setText(QApplication::translate("AudioWidget", "import", 0, QApplication::UnicodeUTF8));
        pushButton_out->setText(QApplication::translate("AudioWidget", "export", 0, QApplication::UnicodeUTF8));
        pushButton_delete->setText(QApplication::translate("AudioWidget", "delete", 0, QApplication::UnicodeUTF8));
        pushButton_refresh->setText(QApplication::translate("AudioWidget", "refresh", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QApplication::translate("AudioWidget", "%p%", 0, QApplication::UnicodeUTF8));
        msg_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AudioWidget: public Ui_AudioWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOWIDGET_H
