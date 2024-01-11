#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    pid_t currentPid = getpid();
    pid_t parentPid = getppid();
    pid_t pgid = getpgid(currentPid);
    printf("currentPid:%d\nparentPid:%d\npgid:%d\n", currentPid, parentPid, pgid);


    while (1)
    {
        printf("hello\n");
        sleep(3);
    }
    

    return 0;
}
 