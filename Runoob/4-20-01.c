/* 
char	通常是一个字节（八位）, 这是一个整数类型。
int	整型，4 个字节，取值范围 -2147483648 到 2147483647。
float	
单精度浮点值。单精度是这样的格式，1位符号，8位指数，23位小数。
double	
双精度浮点值。双精度是1位符号，11位指数，52位小数。
void	表示类型的缺失 
*/

/* //声明并定义变量
int i, j, k;
char c, ch;
float f, salary;
double d;

//定义并初始化

extern int d = 3, f = 5; // d 和 f 的声明与初始化
int d = 3, f = 5;        // 定义并初始化 d 和 f
char x = 'x';            // 变量 x 的值为 'x' */

#include <stdio.h>

//函数外定义变量
int x;
int y;
int z = 4;
int addtwonum()
{
    extern int x;
    extern int y;
    int z = 6;
    x = 1;
    y = 2;
    printf("addtwonum  Z:%d\n", z);
    return x + y;
}
int main()
{
    int result;
    //调用addtwounm
    result = addtwonum();
    printf("result为：%d\nZ:%d\n", result, z);
    return 0;
}