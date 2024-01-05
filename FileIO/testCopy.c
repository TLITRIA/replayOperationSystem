#include <stdio.h>
#include <string.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 10

/* ./testOpen.c => ./testOpen_bk.c */

int main()
{
    int fd = open("./testOpen.c", O_RDWR);
    if (fd == -1)
    {
        perror("read error");
    }
    
    int fdCopy = open("./testOpenCopy.c", O_RDWR || O_CREAT, 0777);
    if (fdCopy == -1)
    {
        perror("create error");
    }
    
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int readLen = 0;

    while (1)
    {
        readLen = read(fd, buffer, BUFFER_SIZE - 1);
        write(fdCopy, buffer, readLen);
        if (readLen < BUFFER_SIZE - 1 || readLen == 0)
        {
            break;
        }
    }

    close(fd);
    close(fdCopy);
    




    return 0;
}