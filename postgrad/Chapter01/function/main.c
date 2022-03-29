#include "func.h"   //引入自定义的头文件用""
#include <stdio.h>

int main()
{
    int a = 10;
    a = printstar(a);  //函数调用
    print_message();
    printstar(a);
    return 0;
}