#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 128

int main()
{
    /**opendir
     * closedir
     * readdir
    */

    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    getcwd(buf, sizeof(buf) - 1);

    DIR * pDir = opendir(buf);
    if (pDir == NULL)
    {
        perror("opendir error");
        return 0;
    }

    struct dirent * pDirent = readdir(pDir);
    while ((pDirent = readdir(pDir)) != NULL)
    {
        if (pDirent->d_type == DT_REG)
        {
            printf("d_name:%s\t", pDirent->d_name);
            printf("d_reclen:%d\t", pDirent->d_reclen);
            printf("d_type:%d\n", pDirent->d_type);
            
        }

        
        
        
        
        
    }
    
    
    




    closedir(pDir);
    return 0;
}