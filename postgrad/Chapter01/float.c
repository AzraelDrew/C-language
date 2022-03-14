// 浮点型常量

#include <stdio.h>
int main()
{
    float f = 1.234;
    float f2 = 3e3;  //e代表10的幂次(不建议使用) float类型占4字节
    float f3 = 3e-3;
    printf("out of float:%f,%f,%f\n ", f,f2,f3); //%f以浮点形式输出对应的数据   
    return 0;
}