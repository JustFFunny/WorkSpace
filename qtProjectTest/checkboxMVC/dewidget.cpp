#include "dewidget.h"
#include <QHBoxLayout>
DeWidget::DeWidget(QWidget *parent) :
    QWidget(parent)
{
    m_label= new QLabel("HELLO WORLD,Welcome to mvc!");
    QHBoxLayout * mainlayout = new QHBoxLayout;
    mainlayout->addWidget(m_label);
    setLayout(mainlayout);
}
