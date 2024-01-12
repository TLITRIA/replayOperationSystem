#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#define BUFFER_SIZE 32
#define PIPE_SIZE 2
/* 打印long类型 */
#define PRINT_LINT(p)    \
printf("%s:%ld\n", #p, p);\
/* 打印int类型 */
#define PRINT_INT(p)    \
printf("%s:%d\n", #p, p);\
/* 打印字符串 */
#define PRINT_STR(p)    \
printf("%s:%s\n", #p, p);\

int main()
{
    int ret = access("./testfifo", F_OK);
    if (ret == -1)
    {
        perror("access error");
        _exit(-1);
    }
    
    /* testfifo文件此时一定存在 */
    int fd = open("./testfifo", O_RDWR | O_NONBLOCK);
    if (fd == -1)
    {
        perror("open error");
        _exit(-1);
    }

    /* 可以设置非阻塞 */


    char buf[BUFFER_SIZE];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        int bytes = read(fd, buf, sizeof(buf) - 1);
        if (bytes < 0)
        {
            perror("read error");
            close(fd);      //注意
            _exit(-1);
        }
        // printf ("buf:%s\n", buf);
        PRINT_STR(buf);
        // PRINT_INT(bytes);
        sleep(2);
    }
    close(fd);
    return 0;
}