#include <stdio.h>
#include <string.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 10

/* ./testOpen.c => ./testOpen_bk.c */

int main(int argc, const char *argv[])
{
    /*  */
    if (argc != 3)
    {
        printf("argc param must be 3!\n");
        return 0;
    }



    /* 源文件 */
    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("read error");
    }
    /* 目标文件 */
    int fdCopy = creat(argv[2], O_RDWR || O_CREAT); // todo
    if (fdCopy == -1)
    {
        perror("create error");
    }
    
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int readLen = 0;
    /* 文件打开，文件指针就在开头 */
    while (1)
    {
        readLen = read(fd, buffer, BUFFER_SIZE - 1);
        if (readLen == 0)
        {/* 优化 */
            break;
        }
        
        write(fdCopy, buffer, readLen);
        if (readLen < BUFFER_SIZE - 1)
        {
            break;
        }
    }

    close(fd);
    close(fdCopy);

    return 0;
}