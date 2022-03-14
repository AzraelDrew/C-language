//混合运算
#include <stdio.h>
int main()
{
    int a = 5;
    float b =a/2;  //b=2.0
    float c = (float)a / 2;  //强制类型转换
    float d = a / 2.0; // c=2.50

    printf("a=%d\n", a); // 5
    printf("b=%f\n", b); // 2.000000
    printf("c=%f\n", c); // 2.500000
    printf("d=%f\n",d);  //2.500000
    return 0;
}