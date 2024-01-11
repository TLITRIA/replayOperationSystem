#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include <time.h>

#define BUFFER_SIZE 64


void get_file_time(__time_t st_time)
{
    struct tm* info;
    info=localtime(&(st_time));
    printf("%02d %02d %02d:%02d\n",info->tm_mon+1,\
            info->tm_mday,info->tm_hour,info->tm_min);
}


int main()
{
    struct stat bufStat;
    stat("./testCopy.c", &bufStat);

    bufStat.st_size;
    printf("st_mode:%d\n", bufStat.st_mode);
    printf("st_size:%ld\n", bufStat.st_size);
    // /* access */
    // printf("st_atime:%ld\n", bufStat.st_atime);
    // /* modify */
    // printf("st_mtime:%ld\n", bufStat.st_mtime);
    // /* change(属性) */
    // printf("st_ctime:%ld\n", bufStat.st_ctime);
    // printf("S_ISREG:%d\n", S_ISREG(st_mode));/* todo */

    /* 最后一次访问 */
    get_file_time(bufStat.st_atime);
    /* 最后一次修改 */
    get_file_time(bufStat.st_mtime);
    /* 最后一次修改（属性） */
    get_file_time(bufStat.st_ctime);
    
/*配置文件是否被修改？*/
/* md5 */
    system("ls");

    FILE *pfd = popen("md5sum testStat.c", "r");
    if (pfd == NULL)
    {
        perror("popen error");
        return 0;
    }

    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    fread(buf, sizeof(buf) - 1, 1 ,pfd);

    /* 使用正则过滤 */
    printf("%s\n", buf);
    pclose(pfd);

    return 0;
}