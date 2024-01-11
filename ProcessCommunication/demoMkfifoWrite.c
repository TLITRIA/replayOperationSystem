#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>



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
        ret = mkfifo("./testfifo", 0644);
        if (ret == -1)
        {
            perror("mkfifo error");
            _exit(-1);
        }
    }
    

    int fd = open("./testfifo", O_RDWR);
    if (fd == -1)
    {
        perror("opne error");
        _exit(-1);
    }

    char buf[BUFFER_SIZE];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        strncpy(buf, "helloworld", sizeof(buf));
        write(fd, buf, sizeof(buf));
        PRINT_STR(buf);
        sleep(1);
    }
    
    
    



    
    return 0;
}