#include <stdio.h>
int main()
{
    int a;
    int b;
    printf("请输入两个整数(中间用空格隔开):");
    scanf("%d %d", &a, &b);
    double c = (a + b) / 2.0;
    printf("%d和%d的平均值为=%f\n", a, b, c);
    printf("%d\n", a * -b);
}