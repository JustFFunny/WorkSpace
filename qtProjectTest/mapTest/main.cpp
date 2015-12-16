/*1.如果硬是要读取不存在的关键字的value的话，可能读取的值不对，而且还不报错，如下。
 *可以通过计算 含有关键子个数来进行判断关键字是否存在。
 *
 *
 *  另外，在QHash和QMap中查找一个关键字的值，
 *可以使用value()函数和[ ]操作符。但是一般来说应该使用value()函数来进行查找。
 *因为[ ]操作符在查询的key不存在的时候，会自动在列表中创建此关键字的一个项，
 *从而造成不必要的内存开销。但是 为什么我再找到那个心创建的key的时候，没有该关键字的个数为0????
 *2.Qmap按关键字自动排序
 **/
#include <QCoreApplication>
#include <QMap>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString, int> map;
    map["one"] = 1;
    map["three"] = 3;
    map["seven"] = 7;
    map["oo"] = 7;
    qDebug()<<map.value("one") <<map["one"] ;//1   1
    qDebug()<<map.value("o");                //   0
    qDebug()<<map.count("one");            //含有关键字的个数 0 或者1来进行

    qDebug()<<map.keys(int(7)).count();
    return a.exec();
}
