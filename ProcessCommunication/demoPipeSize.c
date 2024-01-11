#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


#define BUFFER_SIZE 32
int main()
{
    int ret = access("./testfifo", F_OK);
    if (ret == -1)
    {
        perror("access error");
        _exit(-1);
    }

    int fd = open("./testfifo", O_RDWR);
    if (fd == -1)
    {
        
        perror("open error");
        _exit(-1);
    }

    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    int bytes = read(fd, buf, sizeof(buf) - 1);
    if (bytes < 0)
    {
        perror("read error");
        close(fd);
        _exit(-1);
    }
    

    close(fd); 
}