/* 关系运算符 */
#include <stdio.h>
int main()
{
    int a = 21;
    int b = 10;
    int c;
    if (a == b)
    {
        printf("a = b\n");
    }
    else
    {
        printf("a!=b\n");
    }
    if (a < b)
    {
        printf("a < b\n");
    }
    else
    {
        printf("a > b\n");
    }
    if (a > b)
    {
        printf("a > b\n");
    }
    else
    {
        printf("a < b\n");
    }

    a = 5;
    b = 20;
    if (a <= b)
    {
        printf("a <= b\n");
    }
    if (b >= a)
    {
        printf("b >= a\n");
    }
}