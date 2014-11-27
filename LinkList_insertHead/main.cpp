//链表头插法
#include <iostream>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
struct   Node
{
    int data;
    Node * nextNode;
};
typedef Node *LinkList;
//在链表头部插入元素 前插
int creatLinkList(LinkList *linkList ,int n)
{
    srand(time(NULL));
    //创建头节点
    // linkList=NULL;
    * linkList=(LinkList)malloc(sizeof(Node));// linkList指向头节点的指针的指针
    if(!linkList)
    {
        //分配内存失败
    }
    ( *linkList)->data=n;
    ( *linkList)->nextNode=NULL;

    //分配链接 节点
    int i=0;
    Node *p=NULL;
    while(i<n)
    {
        p= (Node *)malloc(sizeof(Node));
        if(!p)
        {
            //分配内存失败
        }
        p->data=i;
        cout<<"p->data:"<<p->data<<" "<<i;
        p->nextNode= (*linkList)->nextNode;
        (*linkList)->nextNode=p;
        ++i;
        cout<<"\n";
    }
    //free(p);//不能free因为这块内存我们后面还要用;如果你free啦,这个结果不是垃圾值;
    //p=NULL;
    return 0;
}

//显示
void dispaly(LinkList linkList,int n)
{
    int i=0;
    //linkList=linkList->nextNode;
    while(i<=n)
    {
        cout<<linkList->data<<" ";
        linkList=linkList->nextNode;
        ++i;
    }
    cout<<"\n";
}


int main()
{
    LinkList link = NULL;
    creatLinkList(&link,10);
    dispaly(link,10);
    free(link);
    link=NULL;
    cout << "Hello World!" << endl;
    return 0;
}

