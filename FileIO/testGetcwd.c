#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main()
{
   

    /*  */
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));


    char *ptr = getcwd(buf, sizeof(buf) - 1);
    if (ptr == NULL)
    {
        perror(" error");
    }

    printf("buf:%s\n", buf);
    printf("ptr:%s\n", ptr);
    
    

    return 0;
}