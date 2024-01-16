#include "threadPool.h"
#include "common.h"

#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_MAX_THREADS 5
#define DEFAULT_MIN_THREADS 10


enum ERROR_CODE
{
    INVALID_ACCESS = -4,
    UNKOWN_ERROR,
    MALLOC_ERROR,
    NULL_PTR,
    ON_SUCCESS,
};

void *threadHandler()
{
    pthread_exit(NULL);
}


/* 初始化 */
int threadPoolInit(threadpool_t **pool, int minThreads, int maxthreads)
{
    /* 判空 */
    threadpool_t *newPool = (threadpool_t *)malloc(sizeof(threadpool_t) * 1);
    JUDGE_MALLOC(newPool);
    memset(newPool, 0, sizeof(threadpool_t) * 1);
    
    do
    {
        /* 判断合法性 */
        if (minThreads < 0 || maxthreads < 0 || minThreads > maxthreads)
        {
            minThreads = DEFAULT_MIN_THREADS;
            maxthreads = DEFAULT_MAX_THREADS;
        }
        /* 更新线程池的属性 */

        


        newPool->maxthreads = maxthreads;
        newPool->minThreads = minThreads;

        newPool->threadId = (pthread_t *)malloc(sizeof(pthread_t) * newPool->maxthreads);
        if (newPool->threadId == NULL)
        {
            perror("malloc error");
            _exit(-1);
        }
        int ret = 0;
        /* 创建线程 */
        for(int idx = 0; idx < newPool->maxthreads; idx++)    
        {
            ret = pthread_create(&(newPool->threadId[idx]), NULL, threadHandler, NULL);
            if (ret != 0)
            {
                perror("thread create error");
                break;
            }
            
        }

        *pool = newPool;
        return ON_SUCCESS;
    } while(0);

/* 到这里意味着有失败 */

/* 回收线程资源 */


}

/* 销毁 */
int threadPoolDestroy(threadpool_t *pool);