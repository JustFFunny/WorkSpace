/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created: Fri Aug 8 09:27:45 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QPushButton *btnGauge1;
    QFrame *fm;
    QPushButton *btnGauge2;
    QLabel *labValue;
    QPushButton *btnGauge3;
    QPushButton *btnGauge4;
    QPushButton *btnGauge5;
    QPushButton *btnGauge6;
    QPushButton *btnProgressBar;
    QPushButton *btnGauge7;
    QPushButton *btnBattery;
    QPushButton *btnCoolBar;
    QPushButton *btnIndicator;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->resize(676, 514);
        btnGauge1 = new QPushButton(frmMain);
        btnGauge1->setObjectName(QString::fromUtf8("btnGauge1"));
        btnGauge1->setGeometry(QRect(540, 10, 125, 31));
        btnGauge1->setCursor(QCursor(Qt::PointingHandCursor));
        fm = new QFrame(frmMain);
        fm->setObjectName(QString::fromUtf8("fm"));
        fm->setGeometry(QRect(10, 10, 521, 491));
        fm->setFrameShape(QFrame::StyledPanel);
        fm->setFrameShadow(QFrame::Raised);
        btnGauge2 = new QPushButton(frmMain);
        btnGauge2->setObjectName(QString::fromUtf8("btnGauge2"));
        btnGauge2->setGeometry(QRect(540, 50, 125, 31));
        btnGauge2->setCursor(QCursor(Qt::PointingHandCursor));
        labValue = new QLabel(frmMain);
        labValue->setObjectName(QString::fromUtf8("labValue"));
        labValue->setGeometry(QRect(540, 480, 131, 21));
        labValue->setStyleSheet(QString::fromUtf8(""));
        btnGauge3 = new QPushButton(frmMain);
        btnGauge3->setObjectName(QString::fromUtf8("btnGauge3"));
        btnGauge3->setGeometry(QRect(540, 90, 125, 31));
        btnGauge3->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge4 = new QPushButton(frmMain);
        btnGauge4->setObjectName(QString::fromUtf8("btnGauge4"));
        btnGauge4->setGeometry(QRect(540, 130, 125, 31));
        btnGauge4->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge5 = new QPushButton(frmMain);
        btnGauge5->setObjectName(QString::fromUtf8("btnGauge5"));
        btnGauge5->setGeometry(QRect(540, 170, 125, 31));
        btnGauge5->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge6 = new QPushButton(frmMain);
        btnGauge6->setObjectName(QString::fromUtf8("btnGauge6"));
        btnGauge6->setGeometry(QRect(540, 210, 125, 31));
        btnGauge6->setCursor(QCursor(Qt::PointingHandCursor));
        btnProgressBar = new QPushButton(frmMain);
        btnProgressBar->setObjectName(QString::fromUtf8("btnProgressBar"));
        btnProgressBar->setGeometry(QRect(540, 290, 125, 31));
        btnProgressBar->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge7 = new QPushButton(frmMain);
        btnGauge7->setObjectName(QString::fromUtf8("btnGauge7"));
        btnGauge7->setGeometry(QRect(540, 250, 125, 31));
        btnGauge7->setCursor(QCursor(Qt::PointingHandCursor));
        btnBattery = new QPushButton(frmMain);
        btnBattery->setObjectName(QString::fromUtf8("btnBattery"));
        btnBattery->setGeometry(QRect(540, 330, 125, 31));
        btnBattery->setCursor(QCursor(Qt::PointingHandCursor));
        btnCoolBar = new QPushButton(frmMain);
        btnCoolBar->setObjectName(QString::fromUtf8("btnCoolBar"));
        btnCoolBar->setGeometry(QRect(540, 370, 125, 31));
        btnCoolBar->setCursor(QCursor(Qt::PointingHandCursor));
        btnIndicator = new QPushButton(frmMain);
        btnIndicator->setObjectName(QString::fromUtf8("btnIndicator"));
        btnIndicator->setGeometry(QRect(540, 410, 125, 31));
        btnIndicator->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "\347\262\276\347\276\216\346\216\247\344\273\266\346\274\224\347\244\272(\346\235\245\346\272\220:QTCN\347\244\276\345\214\272 \346\225\264\347\220\206:\345\210\230\345\205\270\346\255\246)", 0, QApplication::UnicodeUTF8));
        btnGauge1->setText(QApplication::translate("frmMain", "\345\234\206\345\275\242\346\213\261\345\275\242\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        btnGauge2->setText(QApplication::translate("frmMain", "\345\234\206\345\275\242\346\214\207\351\222\210\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        labValue->setText(QApplication::translate("frmMain", "\345\275\223\345\211\215\345\200\274:", 0, QApplication::UnicodeUTF8));
        btnGauge3->setText(QApplication::translate("frmMain", "\345\267\246\345\217\263\346\273\221\345\235\227\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        btnGauge4->setText(QApplication::translate("frmMain", "\347\272\277\346\200\247\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        btnGauge5->setText(QApplication::translate("frmMain", "\345\234\206\345\275\242\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        btnGauge6->setText(QApplication::translate("frmMain", "\345\236\202\347\233\264\345\217\263\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        btnProgressBar->setText(QApplication::translate("frmMain", "\351\205\267\347\202\253\350\277\233\345\272\246\346\235\241", 0, QApplication::UnicodeUTF8));
        btnGauge7->setText(QApplication::translate("frmMain", "\345\236\202\347\233\264\345\267\246\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        btnBattery->setText(QApplication::translate("frmMain", "\347\224\265\346\272\220\346\214\207\347\244\272\344\273\252", 0, QApplication::UnicodeUTF8));
        btnCoolBar->setText(QApplication::translate("frmMain", "\346\244\255\345\234\206\346\273\221\345\235\227", 0, QApplication::UnicodeUTF8));
        btnIndicator->setText(QApplication::translate("frmMain", "\345\236\202\347\233\264\346\226\271\345\235\227\350\277\233\345\272\246\346\235\241", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
