// 整型及进制转换

#include "stdio.h"
int main()
{
    // int类型是4个字节
    int i = 123;
    int b = 0x7b;   //16进制
    int c = 0173;   //八进制
    printf("%d,%d,%d\n", i, b, c); //%d以十进制输出一个整型数    123,123,123
}