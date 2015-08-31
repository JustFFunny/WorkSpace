#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QTextEdit>

class myWidget : public QTextEdit
{
    Q_OBJECT
public:
    explicit myWidget(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MYWIDGET_H
