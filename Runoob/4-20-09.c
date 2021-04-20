/* 逻辑运算符 */
#include <stdio.h>
int main()
{
    int a = 5;
    int b = 20;
    int c;
    if (a && b)
    {
        printf("true\n");
    }
    if (a || b)
    {
        printf("true\n");
    }

    a = 0;
    b = 10;
    if (a && b)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    if (!(a && b))
    {
        printf("true\n");
    }
}