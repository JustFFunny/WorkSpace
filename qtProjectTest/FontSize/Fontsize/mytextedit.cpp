#include "mytextedit.h"

myTextEdit::myTextEdit(QWidget *parent,QString mes) :
    QWidget(parent)
{
    editor= new QTextEdit(this);
 connect(editor->document(),SIGNAL(contentsChanged()),this,SLOT(textAreaChanged()));
      //editor->setContentsMargins(2,2,0,2);
     // editor->setText(mes);

      editor->setFixedWidth(174);
      editor->setText("a");
      editor->setFixedHeight(500);

      editor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

      editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

      editor->setObjectName("TEXTAREA");


}

void myTextEdit::textAreaChanged()
{
     QTextDocument *document = qobject_cast<QTextDocument*>(sender());

     if (document)
     {
            QTextEdit *editor = qobject_cast<QTextEdit*>(document->parent()->parent());

            if (editor)
            {
                  int newheight = document->size().rheight();

                  if (newheight != editor->height())
                  {
                        //editor->setFixedHeight(newheight);
                        this->setFixedHeight(newheight);

                       // table ->setRowHeight(0, newheight);
                  }
            }

     }
 }

void myTextEdit::setText(QString mes)
{
  editor->setText(mes);
}
