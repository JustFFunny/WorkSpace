#ifndef ANIMALWIDGET_H
#define ANIMALWIDGET_H

#include <QWidget>
class QPropertyAnimation;
class AnimalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AnimalWidget(QWidget *parent = 0);
    
signals:

public slots:
    void start();
protected:
    QPropertyAnimation * m_animal;

    
};

#endif // ANIMALWIDGET_H
