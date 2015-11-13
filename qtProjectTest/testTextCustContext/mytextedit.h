#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>

class myTextEdit : public QWidget
{
    Q_OBJECT
public:
    explicit myTextEdit(QWidget *parent = 0);
    ~myTextEdit();
    void  setText(QString mes);
    QTextEdit *editor;
signals:

public slots:
    void textAreaChanged();
     void rightContextMenuSlot(QPoint );
};

#endif // MYTEXTEDIT_H
