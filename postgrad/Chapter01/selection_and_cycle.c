#include <stdio.h>
int main()
{

    // //if(关系表达式或者逻辑表达式){}
    // if(5>3 && 8<4-!0){
    //     printf("True\n");
    // }
    // else{
    //     printf("False\n");
    // }

    int i = 0;
    while (scanf("%d",&i)!=EOF)
    {
        if(i>0)   //若在if后加分号后 if后面花括号中的代码不会经过if判断,即无论真假都会执行花括号中的语句        (C语言以分号结束代码)
        {
        printf("i is bigger than 0\n");
        }
        else
        {
            printf("i is smaller than 0\n");
        }
    }

    return 0;
}