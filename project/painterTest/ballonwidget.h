#ifndef BALLONWIDGET_H
#define BALLONWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QRect>

class BallonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BallonWidget(QWidget *parent=0,QString  mess="inbox" );
    ~BallonWidget();
    QRect boundingRect();
signals:
    
public slots:
    void paintEvent(QPaintEvent *);

private:
    QString  m_message;

    
};

#endif // BALLONWIDGET_H
