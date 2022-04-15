#include <stdio.h>
#include <stdlib.h>
//需要在子函数中更改主函数数据时使用引用 反之不需要使用引用
void modifynum(int &val){  //把&写到形参的位置是c++的语法  c++称为引用
    val++;
}
void modifynum2(int val){  
    val++;
}
int main()
{
    int a = 10;
    int b = 10;
    modifynum(a);
    printf("%d\n",a);
    modifynum2(b);
    printf("%d\n",b);
    return 0;
}