#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <map>
#include <stdio.h>
#include <string.h>
#include <iostream>


//std::map<int ,string> mapInsert;
//bool mapInsert.insert(pair<int ,string>(1,"hello world"));
//咱们可以根据返回值,来查看插入是否成功
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<QString::number(1%15);
    //QMap
//        QMap<int,QString>  mapInsertAutoSort;
//        mapInsertAutoSort.insert(2,"2");
//        mapInsertAutoSort.insert(1,"1");

//        mapInsertAutoSort.insert(100,"100");
//        mapInsertAutoSort.insert(99,"99");
//        QMap<int,QString>::iterator it =mapInsertAutoSort.begin();
//        qDebug()<<"test checkout the map AutoSort:";
//        while(it!=mapInsertAutoSort.end())
//        {
//            qDebug()<<it.value();
//            ++it;
//        }


    //map
    std::map<int ,std::string>  mapInsertAutoSort;
    mapInsertAutoSort.insert(std::pair<int ,string>(2,"2"));
    mapInsertAutoSort.insert(std::pair<int ,string>(1,"1"));

    //    mapInsertAutoSort.insert(100,"100");
    //    mapInsertAutoSort.insert(99,"99");
    std::map<int,std::string>::iterator it =mapInsertAutoSort.begin();
    qDebug()<<"test checkout the map AutoSort:";
    while(it!=mapInsertAutoSort.end())
    {
        qDebug()<<it->first;
        ++it;
    }
//test2 shuzu de insert hui huigai yuan lai de zhi
    map<int, string> mapStudent;
    mapStudent[1] = "student_one";

    mapStudent[2] = "“student_three”";
    mapStudent[1] = "“student_two”";
    map<int, string>::iterator iter;
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
{
        cout<<iter->first<<"_____"<<iter->second<<std::endl;
}
    


    //test3   zhe zhong cha ru  ,ru guo  cun zai guan jian zi de hua  cha bu bu jin qu

    std::map<int, std::string> mapStudent2;
   pair<map<int, string>::iterator, bool> Insert_Pair;
    Insert_Pair = mapStudent2.insert(pair<int, string>(1, "student_one"));
       if(Insert_Pair.second == true)
       {
           cout<<"Insert Successfully"<<std::endl;
       }
       else
       {
           cout<<"Insert Failure"<<std::endl;
       }


       Insert_Pair = mapStudent2.insert(std::pair<int, string>(1, "student_two"));
       if(Insert_Pair.second == true)
       {
           cout<<"Insert Successfully"<<std::endl;
       }
       else
       {
           cout<<"Insert Failure"<<std::endl;
       }
       map<int, string>::iterator iter2;
       for(iter2 = mapStudent2.begin(); iter2 != mapStudent2.end(); iter2++)
{
           cout<<iter2->first<<iter2->second<<std::endl;
}






    return a.exec();
}
