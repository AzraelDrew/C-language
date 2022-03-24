#include <stdio.h>
int main()
{
    //指针用于保存地址
    //&(引用) 是取地址
    //*(解引用) 取值
    //指针初始化为某个变量的地址
    int i = 5;
    int *i_pointer = &i;   //整型指针变量 必须指向一个整形变量的地址 (什么类型的指针必须指向一个同类型变量的地址)  变量名为i_pointer 而不是*i_pointer
    printf("i=%d\n", i);  //直接访问
    printf("*i_pointer=%d\n", *i_pointer); //间接访问 *i_pointer 拿到i的地址 再去内存中找这个地址对应的值

    // &*i_pointer  = &i   *&i = i
    return 0;
} 