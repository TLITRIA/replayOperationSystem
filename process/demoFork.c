#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{

    int num = 10;
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        return 0;
    }
    
    if (pid == 0)   /* 是子进程 */
    { 
        /* 休眠1S，让出CPU */
        sleep(1);
        
        
        pid_t childPid = getpid();
        printf("child process  childPid:%d, num:%d\n", childPid, num);
        
        pid_t parentPid = getppid();
        printf("child process  parentPid:%d, num:%d\n", parentPid, num);
        _exit(0);

        // while (1)
        // {
        //     sleep(1);
        // }
    }
    else if (pid > 0)   /* 是父进程 */
    {    
        
        pid_t parentPid = getpid();
        printf("parent process : parentPid:%d, num:%d\n", parentPid, num);
        
        num += 100;
        printf("parent process : parentPid:%d, num:%d\n", parentPid, num);

        // while (1)
        // {
        //     sleep(1);
        // }
        
        
    }
    
    
    printf("hello\n");
    return 0;
}

/* todo程序他退不出*/

 