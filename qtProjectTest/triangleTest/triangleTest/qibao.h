#ifndef QIBAO_H
#define QIBAO_H

#include <QWidget>
#include "triangleedittest.h"

class Qibao : public QWidget
{
    Q_OBJECT
public:
    explicit Qibao(QWidget *parent = 0);
    TriangleEditTest * _trigngle;
signals:
    
public slots:

    
};

#endif // QIBAO_H
