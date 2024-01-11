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

int main()
{
    int pipefd[PIPE_SIZE];
    memset(pipefd, 0, sizeof(pipefd));

    pipe(pipefd);

    /* 查看缓冲区函数 */
    long bufferSize = fpathconf(pipefd[0], _PC_PIPE_BUF);
    PRINT_LINT(bufferSize);
    
    bufferSize = fpathconf(pipefd[1], _PC_PIPE_BUF);
    PRINT_LINT(bufferSize);



    return 0;
}