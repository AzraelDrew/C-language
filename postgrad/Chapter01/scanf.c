#define  CRT_SECURE_NO_WARNINGS //解决sancf报错问题
#include "stdio.h"

int main()
{
    int a;
    scanf("%d", &a);  //在变量前加入&
    printf("a=%d\n",a);
    return 0;
}