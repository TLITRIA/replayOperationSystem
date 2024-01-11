#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{   


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

        while (1)
        {
            sleep(2);
            printf("orphan process\n");
        }

        int childState = 1;
        _exit(0);
        
    }
    else if (pid > 0)
    {
        pid_t parentPid = getpid();
        printf("parent process : parentPid:%d, num:%d\n", parentPid, num);
    }
    

    printf("hello world\n");



    return 0;
}