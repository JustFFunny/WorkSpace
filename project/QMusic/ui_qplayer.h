/********************************************************************************
** Form generated from reading UI file 'qplayer.ui'
**
** Created: Thu Jan 7 10:27:00 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPLAYER_H
#define UI_QPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_QPlayer
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QPushButton *PrevButton;
    QPushButton *PlayButton;
    QPushButton *StopButton;
    QPushButton *NextButton;
    QPushButton *PauseButton;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::SeekSlider *seekSlider;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QPushButton *MuButton;
    QPushButton *AddButton;
    QPushButton *RemoveButton;
    QPushButton *StyleButton;
    QLCDNumber *lcdNumber;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *QPlayer)
    {
        if (QPlayer->objectName().isEmpty())
            QPlayer->setObjectName(QString::fromUtf8("QPlayer"));
        QPlayer->resize(250, 344);
        QPlayer->setMinimumSize(QSize(250, 344));
        QPlayer->setMaximumSize(QSize(250, 344));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ICON/style/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        QPlayer->setWindowIcon(icon);
        centralWidget = new QWidget(QPlayer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 60, 251, 55));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PrevButton = new QPushButton(layoutWidget);
        PrevButton->setObjectName(QString::fromUtf8("PrevButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Button/style/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        PrevButton->setIcon(icon1);
        PrevButton->setFlat(false);

        gridLayout->addWidget(PrevButton, 0, 0, 1, 1);

        PlayButton = new QPushButton(layoutWidget);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Button/style/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayButton->setIcon(icon2);
        PlayButton->setFlat(false);

        gridLayout->addWidget(PlayButton, 0, 1, 1, 1);

        StopButton = new QPushButton(layoutWidget);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Button/style/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        StopButton->setIcon(icon3);
        StopButton->setDefault(false);
        StopButton->setFlat(false);

        gridLayout->addWidget(StopButton, 0, 3, 1, 1);

        NextButton = new QPushButton(layoutWidget);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Button/style/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextButton->setIcon(icon4);
        NextButton->setFlat(false);

        gridLayout->addWidget(NextButton, 0, 4, 1, 1);

        PauseButton = new QPushButton(layoutWidget);
        PauseButton->setObjectName(QString::fromUtf8("PauseButton"));
        PauseButton->setEnabled(true);
        PauseButton->setInputMethodHints(Qt::ImhNone);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Button/style/push.png"), QSize(), QIcon::Normal, QIcon::Off);
        PauseButton->setIcon(icon5);

        gridLayout->addWidget(PauseButton, 0, 2, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);

        volumeSlider = new Phonon::VolumeSlider(layoutWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));

        formLayout->setWidget(0, QFormLayout::FieldRole, volumeSlider);

        seekSlider = new Phonon::SeekSlider(layoutWidget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, seekSlider);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 320, 251, 26));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        MuButton = new QPushButton(layoutWidget1);
        MuButton->setObjectName(QString::fromUtf8("MuButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Memu/style/mu.png"), QSize(), QIcon::Normal, QIcon::Off);
        MuButton->setIcon(icon6);

        gridLayout_3->addWidget(MuButton, 0, 0, 1, 1);

        AddButton = new QPushButton(layoutWidget1);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Memu/style/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon7);

        gridLayout_3->addWidget(AddButton, 0, 1, 1, 1);

        RemoveButton = new QPushButton(layoutWidget1);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Memu/style/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        RemoveButton->setIcon(icon8);

        gridLayout_3->addWidget(RemoveButton, 0, 2, 1, 1);

        StyleButton = new QPushButton(layoutWidget1);
        StyleButton->setObjectName(QString::fromUtf8("StyleButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Memu/style/style.png"), QSize(), QIcon::Normal, QIcon::Off);
        StyleButton->setIcon(icon9);

        gridLayout_3->addWidget(StyleButton, 0, 3, 1, 1);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(180, 30, 64, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\261\211\344\273\252\351\233\252\345\263\260\344\275\223\347\256\200"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lcdNumber->setFont(font);
        lcdNumber->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tableWidget = new QTableWidget(centralWidget);
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
        tableWidget->setGeometry(QRect(0, 111, 250, 211));
        tableWidget->setMinimumSize(QSize(250, 0));
        tableWidget->setMaximumSize(QSize(250, 16777215));
        QFont font1;
        font1.setPointSize(9);
        tableWidget->setFont(font1);
        tableWidget->setLineWidth(0);
        tableWidget->setAutoScroll(true);
        tableWidget->setAutoScrollMargin(4);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::DotLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget->horizontalHeader()->setMinimumSectionSize(18);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setDefaultSectionSize(18);
        tableWidget->verticalHeader()->setMinimumSectionSize(18);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(-20, 0, 91, 61));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(56, 56));
        pushButton->setAutoDefault(false);
        pushButton->setDefault(true);
        pushButton->setFlat(true);
        QPlayer->setCentralWidget(centralWidget);

        retranslateUi(QPlayer);

        QMetaObject::connectSlotsByName(QPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *QPlayer)
    {
        QPlayer->setWindowTitle(QApplication::translate("QPlayer", "QT\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
        PrevButton->setText(QString());
        PlayButton->setText(QString());
        StopButton->setText(QString());
        NextButton->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        PauseButton->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        PauseButton->setText(QString());
        MuButton->setText(QApplication::translate("QPlayer", "\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        AddButton->setText(QApplication::translate("QPlayer", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        RemoveButton->setText(QApplication::translate("QPlayer", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        StyleButton->setText(QApplication::translate("QPlayer", "\351\232\217\346\234\272", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QPlayer: public Ui_QPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPLAYER_H
