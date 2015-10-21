#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTime>
#include <QCoreApplication>


class TestWidget : public QWidget
{
    Q_OBJECT
public:
    TestWidget(QWidget *parent = NULL);

    void autoAdjustHeight()
    {
        testEdit->setFixedHeight(testEdit->document()->size().rheight() + testEdit->frameWidth() * 2);
    }
    QTextEdit *testEdit;
    
};

#endif // TESTWIDGET_H
