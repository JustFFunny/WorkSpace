#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <QObject>
#include <QPoint>

class TestObject : public QObject
{
    Q_OBJECT
public:
    explicit TestObject(QObject *parent = 0);
    
signals:
    
public slots:
    void output(const QPoint & pos);
    void TestshortCut();

};
/*
 *class TestObject:public QObject
{
    Q_OBJECT
public:
    TestObject(QObject *parent ):QObject(parent){}
//    ~TestObject(){}
public slots:
    void output(const QPoint & pos)
    {
        qDebug()<<"test";
    }

private:

};
 **/
#endif // TESTOBJECT_H
