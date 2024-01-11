
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{   
    #if 0
    printf("hello world\n");
    /* 当进程没有子进程时 */
    wait(NULL);
    printf("hello world\n");
    #endif

    int num = 100;
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        _exit(0);
    }
    if (pid == 0)
    {
        pid_t childPid = getpid();
        printf("child process : childPid:%d, num:%d\n", childPid, num);

        sleep(300);
    }
    else if (pid > 0)
    {
        pid_t parentPid = getpid();
        printf("parent process : parentPid:%d, num:%d\n", parentPid, num);
    }
    

    /* 父进程阻塞等待回收子进程的资源 */
    /* 返回值是：回收子进程的ID号 */
    int status = 0;
    pid_t waitPid =  wait(&status);
    int ret = WEXITSTATUS(status);
    
    printf("waitPid = %d\n", waitPid);
    printf("status = %d\n", status);
    printf("ret = %d\n", ret);


    printf("hello world\n");







    return 0;
}