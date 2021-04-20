#include <stdio.h>

/* 定义全局变量 */
int x = 1;
int y = 2;
int addtwonum();
int main(void)
{
    int result;
    result = addtwonum();
    printf("result为：%d\n", result);
    return 0;
}