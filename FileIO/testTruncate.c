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
   
   /* 修改文件容量 */
    int ret = truncate("./xixixi.c", 20);
    if (ret == -1)
    {
        perror("truncate error");
        return 0;
    }
    

    return 0;
}