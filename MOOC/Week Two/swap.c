#include <stdio.h>
int main()
{
    int a;
    int b;
    printf("请输入a和b的值(中间用空格隔开):");
    scanf("%d %d", &a, &b);
    int t;
    t = a;
    a = b;
    b = t;
    printf("a=%d , b=%d\n", a, b);
}
