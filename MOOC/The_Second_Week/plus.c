#include <stdio.h>
int main()
{
    int a;
    int b;
    printf("请输入两个整数(中间用空格隔开):");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
}