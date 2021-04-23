/* 
 从函数返回指针

 C 允许函数返回指针到局部变量、静态变量和动态内存分配。

 我们已经了解了 C 语言中如何从函数返回数组，类似地，C 允许您从函数返回指针。为了做到这点，您必须声明一个返回指针的函数，如下所示：

int * myFunction()
{
.
.
.
}
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *getRandom()
{
    static int r[10];
    int i;
    /* 设置种子 */
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        r[i] = rand();
        printf("%d\n", r[i]);
    }
    return r;
}

int main()
{
    /* 一个指向整数的指针 */
    int *p;
    int i;
    p = getRandom();
    for (i = 0; i < 10; i++)
    {
        printf("*(p+[%d]):%d\n", i, *(p + i));
    }
    printf("%p\n", p);
    return 0;
}