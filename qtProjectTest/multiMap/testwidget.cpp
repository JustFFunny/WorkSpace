#include "testwidget.h"

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mailLayout = new QVBoxLayout;

    testEdit = new QTextEdit(this);
    testEdit->setMaximumWidth(100);
    mailLayout->addWidget(testEdit);
    mailLayout->addWidget(new QTextEdit);

    setLayout(mailLayout);
}
