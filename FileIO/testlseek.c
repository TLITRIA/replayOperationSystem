
#include <stdio.h>
#include <string.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main()
{
    #if 1
    /* 使用lseek来计算文件大小 */
    int fd = open("./testWrite.c", O_RDWR);
    if (fd == -1)
    {
        perror("read error");
    }

    off_t offset = lseek(fd, 0, SEEK_END);
    printf("offset:%ld\n", offset);
    #endif



    return 0;
}




