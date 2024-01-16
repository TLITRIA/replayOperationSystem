#ifndef __THREAD_POOL_H_
#define __THREAD_POOL_H_

#include <pthread.h>

/* 线程池结构体 */
typedef struct threadpool_t
{
    pthread_t *threadId;
    int minThreads;
    int maxthreads;
}threadpool_t;

/* 初始化 */
int threadPoolInit(threadpool_t **pool, int minThreads, int maxthreads);

/* 销毁 */
int threadPoolDestroy(threadpool_t *pool);










#endif // __THREAD_POOL_H_