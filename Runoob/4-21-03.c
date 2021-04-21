// 作用域规则
// 在函数或块内部的局部变量
// 在所有函数外部的全局变量
#include <stdio.h>
//声明全局变量
int g = 400;
int a = 80;
int sum(int a, int b)
{
    printf("value of a in sum() = %d\n", a);
    printf("value of b in sum() = %d\n", b);
    return a + b;
}
int main()
{

    // 局部变量声明
    int a, b, c, d, g;
    // 初始化
    a = 10;
    b = 20;
    c = a + b;
    g = a * b;
    printf("value of a in main() = %d\n", a);
    d = sum(a, b);
    printf("value of d in main() = %d\n", d);
    printf("value of a = %d,b =%d and c = %d g = %d\n", a, b, c, g);
}