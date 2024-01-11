#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

    int num = 10;
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        _exit(-1);
    }
    
    if (pid == 0)   /* 是子进程 */
    { 
        pid_t childPid = getpid();
        printf("child process  childPid:%d, num:%d\n", childPid, num);
        num += 100;
        pid_t parentPid = getppid();
        printf("child process  parentPid:%d, num:%d\n", parentPid, num);

        /* 将num写入文件 */
        int fd = open("./FileIPC.txt", O_RDWR | O_CREAT, 0644);
        if (fd == -1)
        {
            perror("open error");
        }

        write(fd, (void *)&num, sizeof(num));
        close(fd);

        // _exit(0);
    }
    else if (pid > 0)   /* 是父进程 */
    {    
        sleep(2);
        pid_t parentPid = getpid();
        printf("parent process : parentPid:%d, num:%d\n", parentPid, num);
        
        int fd = open("./FileIPC.txt", O_RDWR);
        if (fd == -1)
        {
            perror("open error");
        }
        

        int numRead = 0;
        read(fd, (void *)&numRead, sizeof(int));

        close(fd);


        
        printf("parent process : parentPid:%d, numRead:%d\n", parentPid, numRead);
    }
    
    
    printf("hello\n");
    return 0;
}

 