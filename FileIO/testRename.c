
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main()
{

   /* 改名字 */
    int ret = rename("./xixixi.c", "./haihaihai.c");
    if (ret == -1)
    {
        perror("rename error");
    }
    ret = rename("./haihaihai.c", "./xixixi.c");
    if (ret == -1)
    {
        perror("rename error");
    }
    

    return 0;
}