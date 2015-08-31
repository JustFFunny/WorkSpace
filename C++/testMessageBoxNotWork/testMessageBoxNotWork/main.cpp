#include <QApplication>
#include <QMessageBox>
#include <QObject>
#include <QLabel>
#include <QMovie>
#include <qmath.h>
#include <QDebug>

//strlen(...)是函数，要在运行时才能计算。参数必须是字符型指针（char*）。当数组名作为参数传入时，实际上数组就退化成指针了。
//它的功能是：返回字符串的长度。该字符串可能是自己定义的，也可能是内存中随机的，
//该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符NULL。返回的长度大小不包括NULL。
int  nstrlen(char * str)
{
    size_t length=0;
    if(str==0)
    {
        qDebug()<<-1;
        return -1;
    }
    while(*str!='\0')
    {
        qDebug()<<*(str);
        ++length;
        ++str;
    }
    qDebug()<<length;
    return length;
}
int n2strlen(char* str)//递归
{
    if(str==0)
    {
        qDebug()<<-1;
        return -1;
    }
    if(*str=='\0')
    {
        return 0;
    }
    else
    {
        return ( n2strlen(str+1 ) +1 );
    }
}

char * Wu_strCopy(char * des,const char * source)
{
//    assert(des!=0);//当des==0 断言错误
//    assert(source!=0);
    char * _temp=des;
    memcpy(des,source,strlen(source)+1);
    return  _temp;
}





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    QMessageBox::warning(0,QString::fromLocal8Bit("拷贝"),QString::fromLocal8Bit("你确定执行这个操作"),QString::fromLocal8Bit("确定"),QString::fromLocal8Bit("取消"));

    //    //QMessageBox::warning(0,QString::fromLocal8Bit("test"), QString::fromLocal8Bit("msg"), QString::fromLocal8Bit("Yes"), QString::fromLocal8Bit("No"), QString::fromLocal8Bit("Cancel"));
    //    QMessageBox::information(0, "sTitle", "sMessage", "确定", "取消");

    //    //对话框  关闭按钮 * 不起作用的 解决方案1
    //    QMessageBox mess(QMessageBox::Question, QString::fromLocal8Bit("删除提示"), "确认删除所选组件?", NULL);
    //    QPushButton *okButton = mess.addButton(QObject::tr("确定"), QMessageBox::AcceptRole);
    //    QPushButton *cancelButton = mess.addButton(QObject::tr("取消"),QMessageBox::RejectRole);
    //    mess.exec();
    //test2
    /*  QLabel *label=new QLabel();

    QMovie *movie = new QMovie("/home/wuqiankun/rotate.gif");
    label->setMovie(movie);
    movie->start();
    label->show();
   // label->hide()*/;


    //test3
    //   int i=5%5;

    //   int c=1,b=1;
    //   if(c==0|| b==2)
    //   {
    //         qDebug()<<QString::number(5%10);
    //   }

    //test   完成函数int  strlen(char *)
    char *name="onetwo";
    int _legnth=nstrlen(name);
    int _le=nstrlen("");
    char* _a=0;
    int _len=nstrlen(_a);


    return a.exec();
}
