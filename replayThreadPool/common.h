#ifndef __COMMON_H_
#define __COMMON_H_


#define JUDGE_IFNULL(ptr)\
if (NULL == ptr)\
    return NULL_PTR;\

#define JUDGE_MALLOC(ptr)\
if (NULL == ptr)\
    return MALLOC_ERROR;\

#define JUDGE_IFNULL_RETURN_NULL(ptr)\
if (NULL == ptr)\
    return NULL;\

#define FREE(ptr)\
if (NULL == ptr)\
{\
    free(ptr);\
    ptr = NULL;\
}\


#endif // __COMMON_H_