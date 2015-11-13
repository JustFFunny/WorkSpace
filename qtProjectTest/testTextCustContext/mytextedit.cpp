#include "mytextedit.h"
#include  <QDebug>

myTextEdit::myTextEdit(QWidget *parent) :
    QWidget(parent)
{
    editor = new QTextEdit(this);
    connect(editor->document(),SIGNAL(contentsChanged()),this,SLOT(textAreaChanged()));
    editor->setReadOnly(true);
    editor->setFixedWidth(174);
   // editor->setText("a");
    editor->setFixedHeight(50);
    editor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // editor->setObjectName("TEXTAREA");
    editor->setStyleSheet(tr("QTextEdit{padding-left:4px;}"));
    editor->setContextMenuPolicy(Qt::NoContextMenu);

    editor->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(editor,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(rightContextMenuSlot(QPoint )));
    this->show();
}
 myTextEdit::~myTextEdit()
{
}

 void myTextEdit::rightContextMenuSlot(QPoint )
 {
     qDebug()<<"hello";
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
                editor->setFixedHeight(newheight+5);
                this->setFixedHeight(newheight);
            }
        }

    }
}

void myTextEdit::setText(QString mes)
{
    editor->setHtml(mes);
}
