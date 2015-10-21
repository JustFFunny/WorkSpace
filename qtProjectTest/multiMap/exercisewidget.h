#ifndef EXERCISEWIDGET_H
#define EXERCISEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>


class ExerciseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ExerciseWidget(QWidget *parent = 0);
    
signals:
    
public slots:
      void changeText();
    
private:
   QLabel* label;
   QPushButton * button;
};
QString getText();

#endif // EXERCISEWIDGET_H
