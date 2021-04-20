/* 算术元算符 */
#include <stdio.h>
int main()
{
    int a = 21;
    int b = 10;
    int c;
    c = a + b;
    printf("a + c = %d\n", c);
    c = a - b;
    printf("a - b = %d\n", c);
    c = a * b;
    printf("a * b = %d\n", c);
    c = a / b;
    printf("a / b = %d\n", c);
    c = a % b;
    printf("a % b = %d\n", c);
    c = a++; //先赋值后加一
    printf("a++ 后 c=%d   a=%d\n", c, a);
    c = ++a; //先加一再赋值
    printf("++a 后 c=%d   a=%d\n", c, a);
    c = a--; //先赋值再减
    printf("a-- 后 c=%d   a=%d\n", c, a);
    c = --a; //先减在赋值
    printf("--a 后 c=%d   a=%d\n", c, a);
}