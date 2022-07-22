#include <stdio.h>
#include <stdlib.h>
void modifynum(int &b){ 
    
    //  把&写到形参的位置是c++的语法  c++称为引用    
    // 若需要在子函数中改变主函数的值时 需要使用引用
    // 若没有使用引用 在子函数中改变主函数中的变量  主函数中的变量的值不会改变
    // 也可以都使用引用   只需要在子函数内声明一个中间变量
    b++;
}
void modify_pointer(int *&p)
{
    p = (int *)malloc(20);
    *p = 5; //*p = p[0]
    p[1] = 10;
    // free(p);
    // p= NULL;
}
int main()
{
    int a = 10;
    modifynum(a);
    printf("%d\n",a);
    int *p= NULL;
    modify_pointer(p);
    printf("%d,%d\n",*p,p[1]);
    return 0;
}     