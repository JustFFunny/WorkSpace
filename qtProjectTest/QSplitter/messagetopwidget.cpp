#include "messagetopwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QSplitter>
#include <QSpacerItem>
#include <QLineEdit>
#include <QHBoxLayout>
MessagetopWidget::MessagetopWidget(QWidget *parent) :
    QWidget(parent)
{
    m_searchLineEdit =new SearchlineEdit;
    m_nameLable =new QLabel("contact");
    m_nameLable->setAlignment(Qt::AlignLeft| Qt::AlignVCenter);
   // m_nameLable->setFixedHeight(50);
    m_splitter=new QSplitter;
    m_splitter->setFrameShape(QFrame::NoFrame);
    m_splitter->addWidget(m_searchLineEdit);
    m_splitter->addWidget(m_nameLable);
    m_splitter->setStretchFactor(0,5);
    m_splitter->setStretchFactor(1, 5);
    m_splitter->setChildrenCollapsible(false);
    m_splitter->setHandleWidth(2);
    m_splitter->setStyleSheet("QSplitter::handle{background:red;}");
    m_mainLayout=new QHBoxLayout;
    m_mainLayout->addWidget(m_splitter);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(0,0,0,0);
    setLayout(m_mainLayout);
}

MessagetopWidget:: ~MessagetopWidget()
{
    delete m_searchLineEdit;
    delete m_nameLable;
    delete m_splitter;
    delete m_mainLayout;
}


/*Function name:setLableName(QString &)
 *Function:设置lable名字
 *参数：无
 **/
 void MessagetopWidget::setLableName(QString & nameStr)
 {
     m_nameLable->setText(nameStr);
 }
