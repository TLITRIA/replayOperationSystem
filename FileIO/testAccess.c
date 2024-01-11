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
    /**
     * R_OK
     * F_OK
     * 
     * 
    */

   /* 判断文件是否存在 */
    int ret = access("./hahaha.c", F_OK);
    if (ret != 0)
    {
        perror("access error");
    }
    

    return 0;
}