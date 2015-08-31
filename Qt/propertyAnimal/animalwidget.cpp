#include "animalwidget.h"
#include <QPropertyAnimation>
#include <QPushButton>
#include <QHBoxLayout>

AnimalWidget::AnimalWidget(QWidget *parent) :
    QWidget(parent)
{
   QPushButton * m_widgte=new QPushButton;
   QHBoxLayout * H=new QHBoxLayout;
   H->addWidget(m_widgte);
   //m_widgte->setBaseSize(200,200);
   m_animal=new QPropertyAnimation(m_widgte,"geometry");
   m_animal->setDuration(300000);//sudu
   m_animal->setStartValue(QRect(0, 0, 100, 30));
   m_animal->setEndValue(QRect(250, 250, 100, 300));
   connect(m_widgte,SIGNAL(clicked()),this,SLOT(start()));
   this->setLayout(H);

}
void AnimalWidget::start()
{

  m_animal->start();
}
