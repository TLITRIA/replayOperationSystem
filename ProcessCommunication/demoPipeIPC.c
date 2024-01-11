#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>

#define PIPE_NUM 2  
int main()
{

    int pipefd[PIPE_NUM] = {0};
    memset(pipefd, 0, sizeof(int) * PIPE_NUM);

    /* 创建管道  0：读端-父 1：写端-子 */
    pipe(pipefd);

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        _exit(-1);
    }


    if (pid == 0)
    {
        /* 规定子进程写，则关闭读通道 */
        close(pipefd[0]);


        /* 子进程写 */
        sleep(2);
        int num = 2900;
        write(pipefd[1], (void *)&num, sizeof(num));

        #if 0
        int childReadNum = 0;
        read(pipefd[0], (void *)&childReadNum, sizeof(childReadNum));
        printf("child process: childReadNum:%d\n", childReadNum);
        #endif
        close(pipefd[1]);
    }
    else if (pid > 0)
    {
        sleep(1);

        close(pipefd[1]);
        /* 3步把read设置非阻塞 */
        int flags = fcntl(pipefd[0], F_GETFL);
        
        flags |= O_NONBLOCK;
        printf("flag:%d\n", flags);
        int ret = fcntl(pipefd[0], F_SETFL, flags);
        if (ret == -1)
        {
            perror("fcntl setfd error");
        }
        
#if 1
        /* 父进程读 */
        int readNum = 0;
        ret = read(pipefd[0], (void *)&readNum, sizeof(readNum));
        printf("parent|ret:%d\n", ret);


        close(pipefd[0]);

        printf("parent process: readNum:%d\n", readNum);
#endif
        

        _exit(0);
    }

    while (1)
    {
        sleep(3);
    }
    
    


    return 0;
}