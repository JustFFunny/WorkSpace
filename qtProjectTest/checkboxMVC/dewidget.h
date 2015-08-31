#ifndef DEWIDGET_H
#define DEWIDGET_H

#include <QWidget>
#include <QLabel>
class DeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DeWidget(QWidget *parent = 0);
    
signals:
    
public slots:
private:
    QLabel * m_label;
};

#endif // DEWIDGET_H
