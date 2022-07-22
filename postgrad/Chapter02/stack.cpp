// 栈(也是线性表)

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;


void  InitStack(SqStack &S){
    S.top = -1;
}
bool StackEmpty(SqStack S){
    if(S.top == -1){
        return true;
    }
    return false;
}
bool PushStack(SqStack &S,ElemType e){
    if(S.top == MaxSize){
        return false;
    }
    S.data[++S.top] = e;
    return true;
}
bool GetTop(SqStack S,ElemType &e){
    if(StackEmpty(S)){
        return false;
    }
    e = S.data[S.top];
    return true;
}
bool PopStack(SqStack &S,ElemType &e){
    if(StackEmpty(S)){
        return false;
    }
    e = S.data[S.top--];
    return true;
}
int main()
{

    SqStack S;
    bool flag;
    ElemType m;
    InitStack(S);
    flag = StackEmpty(S);
    if(flag) {
        printf("StackEmpty\n");
    }

    PushStack(S, 3);
    PushStack(S, 4);
    PushStack(S, 5);

    flag = GetTop(S, m);
    printf("%d\n", m);

    flag = PopStack(S, m);
    printf("%d\n", m);

    flag = GetTop(S, m);
    printf("%d\n", m);
    return 0;
}