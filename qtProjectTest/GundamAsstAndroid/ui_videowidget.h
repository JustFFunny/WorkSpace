/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created: Sat Aug 2 16:51:35 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

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

class Ui_VideoWidget
{
public:
    QWidget *layoutWidget;
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
    QLabel *labelName;
    QLabel *labelIcon;
    QLabel *labelQRcode;
    QLineEdit *editTitle;
    QLabel *labelVersion;
    QLineEdit *editName;
    QLabel *labelAppsFileName;
    QLineEdit *editFilePath;
    QLabel *labelAppsSize;
    QLineEdit *editSize;
    QLabel *labelAppsLocation;
    QLineEdit *editDuration;
    QPushButton *pushButton_in;
    QPushButton *pushButton_out;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_refresh;
    QProgressBar *progressBar;
    QLabel *msg_label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        VideoWidget->resize(736, 539);
        layoutWidget = new QWidget(VideoWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 12, 711, 524));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_all = new QRadioButton(layoutWidget);
        radioButton_all->setObjectName(QString::fromUtf8("radioButton_all"));
        radioButton_all->setMaximumSize(QSize(116, 16777215));

        horizontalLayout_2->addWidget(radioButton_all);

        radioButton_mine = new QRadioButton(layoutWidget);
        radioButton_mine->setObjectName(QString::fromUtf8("radioButton_mine"));
        radioButton_mine->setMaximumSize(QSize(116, 16777215));

        horizontalLayout_2->addWidget(radioButton_mine);

        radioButton_other = new QRadioButton(layoutWidget);
        radioButton_other->setObjectName(QString::fromUtf8("radioButton_other"));
        radioButton_other->setMaximumSize(QSize(116, 16777215));

        horizontalLayout_2->addWidget(radioButton_other);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(layoutWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(501, 0));

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelName = new QLabel(layoutWidget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setMaximumSize(QSize(104, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelName->setFont(font);

        gridLayout->addWidget(labelName, 0, 2, 1, 1);

        labelIcon = new QLabel(layoutWidget);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setMinimumSize(QSize(72, 72));
        labelIcon->setMaximumSize(QSize(72, 72));
        labelIcon->setText(QString::fromUtf8(""));
        labelIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/info.png")));
        labelIcon->setScaledContents(true);

        gridLayout->addWidget(labelIcon, 1, 0, 3, 1);

        labelQRcode = new QLabel(layoutWidget);
        labelQRcode->setObjectName(QString::fromUtf8("labelQRcode"));
        labelQRcode->setMaximumSize(QSize(9, 72));
        labelQRcode->setText(QString::fromUtf8(""));
        labelQRcode->setScaledContents(true);

        gridLayout->addWidget(labelQRcode, 1, 1, 1, 1);

        editTitle = new QLineEdit(layoutWidget);
        editTitle->setObjectName(QString::fromUtf8("editTitle"));
        editTitle->setMaximumSize(QSize(104, 16777215));
        editTitle->setText(QString::fromUtf8(""));
        editTitle->setReadOnly(true);

        gridLayout->addWidget(editTitle, 1, 2, 1, 1);

        labelVersion = new QLabel(layoutWidget);
        labelVersion->setObjectName(QString::fromUtf8("labelVersion"));
        labelVersion->setMaximumSize(QSize(104, 16777215));
        labelVersion->setFont(font);

        gridLayout->addWidget(labelVersion, 2, 2, 1, 1);

        editName = new QLineEdit(layoutWidget);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setMaximumSize(QSize(104, 16777215));
        editName->setText(QString::fromUtf8(""));
        editName->setReadOnly(true);

        gridLayout->addWidget(editName, 3, 2, 1, 1);

        labelAppsFileName = new QLabel(layoutWidget);
        labelAppsFileName->setObjectName(QString::fromUtf8("labelAppsFileName"));
        labelAppsFileName->setMaximumSize(QSize(199, 16777215));
        labelAppsFileName->setFont(font);

        gridLayout->addWidget(labelAppsFileName, 4, 0, 1, 3);

        editFilePath = new QLineEdit(layoutWidget);
        editFilePath->setObjectName(QString::fromUtf8("editFilePath"));
        editFilePath->setMaximumSize(QSize(199, 16777215));
        editFilePath->setText(QString::fromUtf8(""));
        editFilePath->setReadOnly(true);

        gridLayout->addWidget(editFilePath, 5, 0, 1, 3);

        labelAppsSize = new QLabel(layoutWidget);
        labelAppsSize->setObjectName(QString::fromUtf8("labelAppsSize"));
        labelAppsSize->setMaximumSize(QSize(199, 16777215));
        labelAppsSize->setFont(font);

        gridLayout->addWidget(labelAppsSize, 6, 0, 1, 3);

        editSize = new QLineEdit(layoutWidget);
        editSize->setObjectName(QString::fromUtf8("editSize"));
        editSize->setMaximumSize(QSize(199, 16777215));
        editSize->setText(QString::fromUtf8(""));
        editSize->setReadOnly(true);

        gridLayout->addWidget(editSize, 7, 0, 1, 3);

        labelAppsLocation = new QLabel(layoutWidget);
        labelAppsLocation->setObjectName(QString::fromUtf8("labelAppsLocation"));
        labelAppsLocation->setMaximumSize(QSize(199, 16777215));
        labelAppsLocation->setFont(font);

        gridLayout->addWidget(labelAppsLocation, 8, 0, 1, 3);

        editDuration = new QLineEdit(layoutWidget);
        editDuration->setObjectName(QString::fromUtf8("editDuration"));
        editDuration->setMaximumSize(QSize(199, 16777215));
        editDuration->setReadOnly(true);

        gridLayout->addWidget(editDuration, 9, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);

        pushButton_in = new QPushButton(layoutWidget);
        pushButton_in->setObjectName(QString::fromUtf8("pushButton_in"));
        pushButton_in->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_in);

        pushButton_out = new QPushButton(layoutWidget);
        pushButton_out->setObjectName(QString::fromUtf8("pushButton_out"));
        pushButton_out->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_out);

        pushButton_delete = new QPushButton(layoutWidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_delete);

        pushButton_refresh = new QPushButton(layoutWidget);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));
        pushButton_refresh->setMaximumSize(QSize(199, 16777215));

        verticalLayout->addWidget(pushButton_refresh);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximumSize(QSize(199, 16777215));
        progressBar->setAutoFillBackground(false);
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        msg_label = new QLabel(layoutWidget);
        msg_label->setObjectName(QString::fromUtf8("msg_label"));
        msg_label->setMaximumSize(QSize(199, 16777215));
        msg_label->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(msg_label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QApplication::translate("VideoWidget", "Form", 0, QApplication::UnicodeUTF8));
        radioButton_all->setText(QApplication::translate("VideoWidget", "all", 0, QApplication::UnicodeUTF8));
        radioButton_mine->setText(QApplication::translate("VideoWidget", "mine", 0, QApplication::UnicodeUTF8));
        radioButton_other->setText(QApplication::translate("VideoWidget", "other", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("VideoWidget", "num", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("VideoWidget", "title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("VideoWidget", "size", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("VideoWidget", "time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("VideoWidget", "file", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("VideoWidget", "Title", 0, QApplication::UnicodeUTF8));
        labelVersion->setText(QApplication::translate("VideoWidget", "File Name", 0, QApplication::UnicodeUTF8));
        labelAppsFileName->setText(QApplication::translate("VideoWidget", "File Path", 0, QApplication::UnicodeUTF8));
        labelAppsSize->setText(QApplication::translate("VideoWidget", "Size", 0, QApplication::UnicodeUTF8));
        labelAppsLocation->setText(QApplication::translate("VideoWidget", "Duration", 0, QApplication::UnicodeUTF8));
        pushButton_in->setText(QApplication::translate("VideoWidget", "import", 0, QApplication::UnicodeUTF8));
        pushButton_out->setText(QApplication::translate("VideoWidget", "export", 0, QApplication::UnicodeUTF8));
        pushButton_delete->setText(QApplication::translate("VideoWidget", "delete", 0, QApplication::UnicodeUTF8));
        pushButton_refresh->setText(QApplication::translate("VideoWidget", "refresh", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QApplication::translate("VideoWidget", "%p%", 0, QApplication::UnicodeUTF8));
        msg_label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
