#define  CRT_SECURE_NO_WARNINGS //解决sancf报错问题
#include "stdio.h"

int main()
{
    int a,b;
    scanf("%d%d", &a,&b);  //在变量前加入&
    printf("a=%d,b=%d\n",a,b);
    return 0;
}