#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

/* 日志调试其一 */
int g_debug = 1;
FILE * g_logfp = NULL;

#define LOGPR(fmt, args...)         \
do{                                 \
    if (g_debug){                   \
        time_t now;                 \
        struct tm* ptm;             \
        now = time(NULL);           \
        ptm = localtime(&now);      \
        fprintf(g_logfp, "[file:(%s), func(), line(%d), time(%s)]:"fmt, \
        __FILE__, __FUNCTION__, __LINE__, asctime(ptm), ##args);        \
    }                                                                   \
}while(0)           \

/* 日志调试其二 开启日志 */
void log_init()
{
    time_t now;
    struct tm* ptm;
#define DEBUG_FILE "./my_debug.log"
    if ((g_logfp = fopen(DEBUG_FILE, "a")) == NULL)
    {
        fprintf(stderr, "mydebug log init failed!\n");
        return;
    }
    now = time(NULL);
    ptm = localtime(&now);

    LOGPR("===============log init done!================\n");
    LOGPR("===============%s", asctime(ptm));
    return ;
}

/* 日志调试 */
void log_close()
{
    if (g_logfp)
    {
        fclose(g_logfp);
    }
    return ;
}



/* 日志：文件 */
/* 打开日志文件 */
int log_init()
{
    time_t now;

    /* 避免野指针 */
    struct tm* ptm = NULL;
#define DEBUG_FLAG "./my_debug.flag"

    /* access函数成功返回0 */
    if(access(DEBUG_FLAG, F_OK) == 0)
    {
        g_debug = 1;
    }


    if (!g_debug)
    {
        return 0;
    }
#define DEBUG_FILE "./my_debug.log"





    return 0;
}


int log_close()
{
    return 0;
}




int main()
{
    struct tm* info  = localtime(NULL);

    printf("%02d %02d %02d:%02d\n", info->tm_mon+1,\
            info->tm_mday, info->tm_hour, info->tm_min);

    return 0;
}