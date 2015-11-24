/*
*@function:startTime 定义一个定时器,每个时间就会自动调用timeEvent函数.
*@author  :wuqiankun
*@mail    :qiankun@nfschina.com
*/

#include "timeeventobject.h"
#include <QTimerEvent>
#include <QDebug>
#include <QString>

TimeEventObject::TimeEventObject(QObject *parent) :
    QObject(parent)
{
    startTimer(500);
    startTimer(600);
}

void TimeEventObject::timerEvent(QTimerEvent * timerEvent)
{

    qDebug()<<"timeID"<<QString("%1").arg(timerEvent->timerId());
}
