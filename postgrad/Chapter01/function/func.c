#include "func.h"
// 函数的定义
// 返回值类型 函数名(形参1,形参2,...)  形参可以有多个也可以没有   
// 形参在函数没有调用的时候不会分配内存空间  只有在函数调用时才会分配内存空间 函数调用结束后内存会被释放
// 函数定义 也是函数的实现(即函数内部实现的代码) 函数定义前必须声明
int printstar(int i){
    printf("***************\n");
    printf("printfstar %d\n", i);
    return i + 3;
}
void print_message(){
    printf("how do you do\n");
    printstar(3);   //函数的嵌套调用  在函数中调用另一个函数
}