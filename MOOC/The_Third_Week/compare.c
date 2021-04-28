#include <stdio.h>
int main()
{
    int a;
    int b;
    printf("请输入两个整数:");
    scanf("%d %d", &a, &b);
    // int max = 0;
    // if (a > b)
    // {
    //     max = a;
    // }
    // else
    // {
    //     max = b;
    // }

    //不便于阅读
    int max = b;
    if (a > b)
    {
        max = a;
    }
    printf("最大值为:%d\n", max);
    return 0;
}