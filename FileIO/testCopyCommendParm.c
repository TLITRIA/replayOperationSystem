#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    /*  */
    if (argc != 3)
    {
        printf("argc param must be 3!\n");
        return 0;
    }
    

    /*  */

    /* argc是参数的个数 */
    printf("argc:%d\n", argc);

    /* argv保留参数 */
    for (int idx = 0; idx < argc; idx++)
    {
        printf("argv[%d]:%s\n", idx, argv[idx]);
    }
    
    return 0;
}