// 循环队列

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];   //数组  存储MaxSize-1个元素    只能存储MaxSize-1的个元素主要是为了判断队列是否满了
    int front, rear;    //队列头  队列尾
}SqQueue;
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;       //初始化
}

bool isEmpty(SqQueue Q){
    if(Q.front == Q.rear)    //不需要为0
        return true;
    return false;
}
bool EnQueue(SqQueue &Q,ElemType e){
    if((Q.rear+1)%MaxSize == Q.front)
        return false;    //队列满了

    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true; 
}
bool DeQueue(SqQueue &Q,ElemType &e){
     if(Q.rear == Q.front)
         return false;   //队列为空

    e = Q.data[Q.front];
    Q.front= (Q.front + 1)%MaxSize;
    return true;
}
int main()
{

    SqQueue Q;
    bool flag;
    ElemType e;
    InitQueue(Q);
    flag = isEmpty(Q);

    if(flag){
        printf("Queue isEmpty\n");
    }

    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    flag = EnQueue(Q,7); 
    if(!flag){
        printf("队列已满不能入队了!\n");
    }

    flag =DeQueue(Q,e);
    if(flag){
        printf("出队成功!\n");
    }
    flag =DeQueue(Q,e);
    if(flag){
        printf("出队成功!\n");
    }

    return 0;
}