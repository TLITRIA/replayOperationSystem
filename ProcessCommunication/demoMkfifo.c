#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <errno.h>





int main()
{
    int ret = mkfifo("./testfifo", 6644);
    if (ret == -1)
    {
        perror("mkfifo error");
        _exit(-1);
    }
    
    return 0;
}