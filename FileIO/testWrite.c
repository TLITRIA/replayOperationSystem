#include <stdio.h>
#include <string.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

// #define BUFFER_SIZE 10

int main()
{   
    #if 0
    /* 打开文件 */
    int fd = open("./hello.txt", O_WRONLY);
    if (fd == -1)
    {
        perror("open error");
    }

    /* 向文件中写数据 */
    char *ptr = "helloworld";
    int bytes = write(fd, ptr, strlen(ptr));
    if (bytes < 0)
    {
        perror("writer error");
    }
    else
    {
        printf("bytes:%d\n", bytes);
    }
    
    
    /* 关闭文件 */
    close(fd);
    #endif

    #if 0
    /* 打开文件 */
    int fd = open("./hello.txt", O_RDWR | O_TRUNC);
    if (fd == -1)
    {
        perror("open error");
    }

    close(fd);
    #endif

    #if 1
    /* 追加打开文件 */
    int fd = open("./hello.txt", O_RDWR | O_APPEND);
    if (fd == -1)
    {
        perror("open error");
    }

    char ptr[] = "123\n";
    write(fd, ptr, strlen(ptr));

    close(fd);
    #endif

    return 0;
}