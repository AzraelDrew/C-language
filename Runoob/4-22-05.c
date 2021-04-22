/* 
指针数组

可能有一种情况，我们想要让数组存储指向 int 或 char 或其他数据类型的指针。下面是一个指向整数的指针数组的声明：

int *ptr[MAX];
 */

#include <stdio.h>
const int MAX = 3;
int main()
{
    int var[] = {10, 100, 200};
    int i, *ptr[MAX];
    for (i = 0; i < MAX; i++)
    {
        ptr[i] = &var[i];
    }
    for (i = 0; i < MAX; i++)
    {
        printf("value of var[%d] = %d\n", i, *ptr[i]);
    }

    const char *names[] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali"};
    int j = 0;
    for (j = 0; j < MAX; j++)
    {
        printf("value of names[%d] = %s\n", j, names[j]);
    }
    char *name = "azrael";
    printf("%s\n", name);
    return 0;
}
