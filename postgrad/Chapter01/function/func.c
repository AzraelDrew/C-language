#include "func.h"
#include <stdio.h>
//函数定义
int printstar(int i){
    printf("***************\n");
    printf("printfstar %d\n", i);
    return i + 3;
}
void print_message(){
    printf("how do you do\n");
    printstar(3);
}