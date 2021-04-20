/* 杂项运算符 ↦ sizeof & 三元 */
#include <stdio.h>
int main()
{
    int a = 4;
    short b;
    double c;
    int *ptr;
    printf("变量a的大小=%lu\n", sizeof(a));
    printf("变量b的大小=%lu\n", sizeof(a));
    printf("变量c的大小=%lu\n", sizeof(a));
    ptr = &a; //&a返回变量的地址
    printf("a的值是%d\n", a);
    printf("ptr的值是%d\n", ptr);
    a = 10;
    b = (a == 1) ? 20 : 30;
    printf("b的值是%d\n", b);
    b = (a == 10) ? 20 : 30;
    printf("b的值是%d\n", b);
}