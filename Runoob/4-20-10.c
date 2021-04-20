/* 位运算符 */
#include <stdio.h>
int main()
{
    unsigned int a = 60;
    unsigned int b = 13;
    int c = 0;
    c = a & b;
    printf("c = %d\n", c);
    c = a | b;
    printf("c = %d\n", c);
    c = a ^ b;
    printf("c = %d\n", c);
    c = ~a;
    printf("c = %d\n", c);
    c = a << 2;
    printf("c = %d\n", c);
    c = a >> 2;
    printf("c = %d\n", c);
}