#include <QApplication>
#include <QFontMetrics>
#include <QDebug>
#include <QWidget>
#include "mytextedit.h"
#include <QTextDocument>


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString _str="aaa \n bbb！";
//    QFontMetrics _font(QFont());
//   int num= _font.width ( _str ) ;

//    qDebug()<<_str.remove("\n");
    QString _s="\naaa";
//    int fontSize = fontMetrics().width( _s );
//    qDebug()<<QString::number(fontSize);


    myTextEdit * edit=new myTextEdit(0);

//    edit->show();
//    edit->setText(_s);

  float fsize=1.0;
  QString ss = QString().setNum(fsize,'f',1);
  qDebug()<<ss;

  qDebug()<<QString("All: %1 %2").arg(QString::number(11)).arg("hello");



  time_t now;
  struct tm *timenow;
  time(&now);
  timenow = localtime(&now);
  qDebug()<<QString::number(timenow->tm_year+1900)<< timenow->tm_mon<<timenow->tm_mday;



    return a.exec();
}
/* QTextEdit *editor = new QTextEdit(this);

   //editor->setContentsMargins(2,2,0,2);

   editor->setFixedWidth(600);

   editor->setFixedHeight(25);

   editor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   editor->setObjectName("TEXTAREA");

   connect(editor->document(),SIGNAL(contentsChanged()),this,SLOT(textAreaChanged()));



   //将控件放入表格

   QTableWidget *table = new QTableWidget(10,6);



   table.setFixedHeight(610);



   table.setSpan(0,0,1,6);

   table.setCellWidget(0,0, editor);



  //信号接收

   void textAreaChanged()
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
                           editor->setFixedHeight(newheight);

                           table ->setRowHeight(0, newheight);
                     }
               }

        }
    }
*/
