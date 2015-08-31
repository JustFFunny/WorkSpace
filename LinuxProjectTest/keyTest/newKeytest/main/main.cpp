#include <QApplication>
//c语言的宏   __FUNCTION__    __LINE__    __FILE__// 双下划线
//可以 #define   DEBUGFORMAT       %s(%d)%s
//     #define   DEBUGINFO          __FUNCTION__    __LINE__    __FILE__
//另外密码是加密的
#include <unistd.h>    //unix 标准库头文件
#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pid_t my_pid, parent_pid;//*_t 均为int类型  //getpid()得到进程的ID ,getppid()得到父进程(创建调用该进程的进程)的ID()
        uid_t my_uid, my_euid;           //getuid() 得到进程所有者的ID   geteuid()
        gid_t my_gid, my_egid;
        struct passwd *my_info;
        my_pid = getpid();
        parent_pid = getppid();
        my_uid = getuid();
        my_euid = geteuid();
        my_gid = getgid();
        my_egid = getegid();
        my_info = getpwuid(my_uid);//可以指定用户id
        printf("Process ID：%d\n", my_pid);
        printf("Parent ID：%d\n", parent_pid);
        printf("User ID：%d\n", my_uid);
        printf("Effective User ID：%d\n", my_euid);
        printf("Group ID：%d\n", my_gid);
        printf("Effective Group ID：%d\n", my_egid);
 printf("%s\n(%d)\n%s\n",__FILE__,__LINE__,__FUNCTION__);//双下滑线
        if (my_info) {
            printf("My Login Name：%s\n", my_info->pw_name);
            printf("My Password ：%s\n", my_info->pw_passwd);
            printf("My User ID ：%d\n", my_info->pw_uid);
            printf("My Group ID ：%d\n", my_info->pw_gid);
            printf("My Real Name：%s\n", my_info->pw_gecos);
            printf("My Home Dir ：%s\n", my_info->pw_dir);
            printf("My Work Shell：%s\n", my_info->pw_shell);
        }

    return a.exec();
}
