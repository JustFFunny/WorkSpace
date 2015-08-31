#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QString>

class myTextEdit : public QWidget
{
    Q_OBJECT
public:
    explicit myTextEdit(QWidget *parent = 0,QString mes=0);
QTextEdit *editor;
signals:
    
public slots:
     void textAreaChanged();
     void setText(QString mes);
};

#endif // MYTEXTEDIT_H
