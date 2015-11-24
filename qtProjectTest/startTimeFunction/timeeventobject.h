#ifndef TIMEEVENTOBJECT_H
#define TIMEEVENTOBJECT_H

#include <QObject>
#include <QTimerEvent>

class TimeEventObject : public QObject
{
    Q_OBJECT
public:
    explicit TimeEventObject(QObject *parent = 0);
    
signals:
    
public slots:
protected:
    void timerEvent(QTimerEvent * timerEvent);
    
};

#endif // TIMEEVENTOBJECT_H
