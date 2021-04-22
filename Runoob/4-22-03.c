/* 指针 */
#include <stdio.h>
int main()
{
    int var = 20;                         /* 实际变量的声明 */
    int *ip;                              /* 指针变量声明 */
    ip = &var;                            /* 在指针变量中储存var的地址 */
    printf("var 变量的地址:%p\n", &var);  //var的内存地址
    printf("ip 变量储存的地址:%p\n", ip); //var的内存地址
    printf("ip 变量的内存地址地址:%p\n", &ip);
    printf("*ip变量的值:%d\n", *ip);
    int *ptr = NULL;
    if (ptr)
        printf("1\n");
    if (!(ptr))
        printf("2\n");
    printf("ptr 的地址是:%p\n", ptr);
    return 0;
}