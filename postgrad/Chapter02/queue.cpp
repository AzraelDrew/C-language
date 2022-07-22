// 循环队列

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50 
typedef int ElemType;

//  顺序队列用数组
// typedef  struct 
// {
//     ElemType data[MaxSize];
//     int Front;
//     int Rear;
// } Queue;

typedef struct{
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

int main()
{
return 0;
}