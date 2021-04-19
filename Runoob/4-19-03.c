/* 浮点类型 */

/* float	4 字节	1.2E-38 到 3.4E+38	6 位小数
double	8 字节	2.3E-308 到 1.7E+308	15 位小数
long double	16 字节	3.4E-4932 到 1.1E+4932	19 位小数 */

#include <stdio.h>
#include <float.h>
int main()
{
    printf("float 储存最大字节数：%lu \n", sizeof(float));
    printf("float 最小值：%E \n", FLT_MIN);
    printf("float 最大值：%E \n", FLT_MAX);
    printf("精度值：%d\n", FLT_DIG);
    // %E 为以指数形式输出单、双精度实数
    return 0;
}