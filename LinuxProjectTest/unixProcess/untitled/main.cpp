#include <QApplication>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

//多进程 多程序并发执行
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    pid_t child;
    int status;
    printf("This will demostrate how to get child status\n");
     printf("parent ID :%d \n",getpid());
    if((child=fork())==-1)
    {
        printf("Fork Error :%s\n",strerror(errno));
        exit(1);
    }
    else if(child==0)
    {
        int i;
        printf("I am the child:%ld\n",getpid());
        for(i=0;i<1000000;i++) sin(i);
        i=5;
        printf("I exit with %d\n",i);
        exit(i);
    }
    printf("parent exe,child  退出 %d  %d\n",getpid(),wait(&status));
    printf("二次调用wait %d\n",wait(&status));
    while(((child=wait(&status))==-1)&(errno==EINTR));//wait 会使父进程 阻塞,直到子进程结束
    if(child==-1)
        printf("Wait Error:%s\n",strerror(errno));//strerror 函数会返回一个指定的错误号的错误信息的字符串
    else if(!status)
        printf("Child %ld terminated normally return status is zero\n",\
               child);
    else if(WIFEXITED(status))
        printf("Child %ld terminated normally return status is %d\n",\
               child,WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
        printf("Child %ld terminated due to signal %d znot caught\n", child,WTERMSIG(status));

    return a.exec();
}
