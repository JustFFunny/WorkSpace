#include "qibao.h"
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLabel>
#include "pcoverwidget.h"

Qibao::Qibao(QWidget *parent) :
    QWidget(parent)
{
   QHBoxLayout * _hlayout=new QHBoxLayout;
   // QVBoxLayout * _hlayout=new QVBoxLayout;
//    _trigngle =new TriangleEditTest;
   QVBoxLayout * _V2=new QVBoxLayout;
   QTextEdit * _textEdit=new QTextEdit;
   Widget * _w=new Widget;
   _V2 ->addWidget(_w);
    // QLabel * _lable =new QLabel;
     //_lable->setText("name");
_hlayout->addWidget(_textEdit );//_trigngle
//_hlayout->addWidget( _lable);
_textEdit->setText("hello");
QHBoxLayout * mainlayout=new QHBoxLayout;
mainlayout->addLayout(_hlayout);
mainlayout->addLayout(_V2);
mainlayout->setMargin(0);
mainlayout->setSpacing(0);
//this->setGeometry(0,0,300,300);

this->setLayout(mainlayout);

}
