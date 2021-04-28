#include <stdio.h>
int main()
{
    printf("请输入您身高的英寸和英尺,'如输入5 7表示5英尺7英寸':");
    // int foot; //当两个整数相除时结果只能是整数  当结果有小数是会直接省略
    // int inch; //当整数与浮点数进行运算的时候会将整数转换为浮点数进行计算

    // float 单精度浮点数   double 双精度浮点数
    double foot;
    double inch; //方法二
    scanf("%le %le", &foot, &inch);
    // printf("您的身高为%f米.\n", ((foot + inch / 12.0) * 0.3048));   //方法一
    printf("您的身高为%f米.\n", ((foot + inch / 12) * 0.3048));
    return 0;
}