#include <stdio.h>
int main()
{
    int x;
    int n = 1;
    printf("请输入一个整数:");
    scanf("%d", &x);
    // if (x > 999)
    // {
    //     n = 4;
    // }
    // else if (x > 99)
    // {
    //     n = 3;
    // }
    // else if (x > 9)
    // {
    //     n = 2;
    // }
    // else
    // {
    //     n = 1;
    // }
    printf("你输入的数为%d位数\n", n);
    return 0;
}