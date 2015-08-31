#ifndef TRIANGLEEDITTEST_H
#define TRIANGLEEDITTEST_H

#include <QTextEdit>


#include <QWidget>

class TriangleEditTest : public QWidget
{
    Q_OBJECT
public:
    explicit TriangleEditTest(QWidget *parent = 0);
    void paintEvent(QPaintEvent * event);

signals:
    
public slots:
//   void  drawTRIangle();
    
};

#endif // TRIANGLEEDITTEST_H
