
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
#if 0
    /* 打开（创建）文件 */
    int fd = open("./mmap.txt", O_RDWR, 0644);
    if (fd == -1)
    {
        perror("open error");
        _exit(-1);
    }
    

    void* ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap error");
        _exit(-1);
    }
    

    /* 关闭文件 */
    close(fd);


    /* 从映射内存读取数据 */
    printf("ptr:%s", (char *)ptr);

    /*  */
    strcpy((char *)ptr, "666\0");


    int ret = munmap(ptr, 1024);
    if (ret == -1)
    {
        perror("munmap error");
        _exit(-1);
    }
#endif
    
/* 父子进程实现通信 */

    /* 打开（创建）文件 */
    int fd = open("./mmap.txt", O_RDWR, 0644);
    if (fd == -1)
    {
        perror("open error");
        _exit(-1);
    }

    /* 进程 */
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return 0;
    }
    
    if (pid == 0)
    { 
        /* 休眠1S，让出CPU */
        sleep(1);
        
        /* 子进程 */
        pid_t childPid = getpid();
        
        /* 父进程 */
        pid_t parentPid = getppid();

    }
    else if (pid > 0)
    {    
        /* 父进程 */1
        pid_t parentPid = getpid();
    }




    return 0;
}
