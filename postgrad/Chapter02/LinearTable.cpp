#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int len;
} SqList;
bool ListInsert(SqList &L,int i,ElemType e){  //插入元素
    if(i<1|| i>L.len+1){   //判断插入位置是否合法
        return false;
    }
    if(L.len >=MaxSize){   //已经存满了
        return false;
    }
    for (int j = L.len; j >= i;j--){  //向后移动表中的元素
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;  //插入
    L.len++;
    return true; //走到这里插入,成功返回true
}
bool ListDelete(SqList &L,int i,ElemType &e){  //删除元素
    if(i<1|| i>L.len+1){   //判断插入位置是否合法
        return false;
    }
    if(L.len==0){   //表为空
    return false;
    }
    e = L.data[i - 1];
    for (int j =i; j < L.len; j++){ //向前移动表中的元素
        L.data[j-1] = L.data[j];
    }
    L.len--; //删除后表的长度减一
    return true; //走到这里删除,成功返回true
}
void ListChange(SqList &L,int i,ElemType e){
    L.data[i - 1] = e;
}
int ListSerach(SqList &L, ElemType e){  //查找 成功返回位置从1开始,失败返回0
    for(int i =0; i < L.len; i++){   //遍历表
        if(L.data[i] ==e){
            return i+1;
        }
    }
    return 0;
}
void PrintList(SqList &L)
{ //打印顺序表
    for (int i=0;i<L.len;i++){
        printf("%-3d",L.data[i]);
    }
    printf("\n");
}

int main()
{
    SqList L; //顺序表的名称
    bool ret;  //返回值
    ElemType del;  //存储删除的元素
    int Element;  //返回元素的位置
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;
    ret=ListInsert(L, 2, 60);
    if(ret){
        printf("插入成功\n");
        PrintList(L);
    }
    else{
        printf("插入失败\n");
    }
    ret = ListDelete(L,2,del);
    if(ret){
        printf("删除成功\n");
        printf("删除元素的值为:%d\n", del);
        PrintList(L);
    }
    else
    {
        printf("删除失败\n");
    }
    Element = ListSerach(L, 60);
    if(Element){
        printf("查找成功\n");
        printf("查找成功位置为:%d\n",Element);
        PrintList(L);
    }
    else{
        printf("查找失败\n");
    }
    ListChange(L, 1, 60);
    PrintList(L);

    Element = ListSerach(L, 60);
    if(Element){
        printf("查找成功\n");
        printf("查找成功位置为:%d\n",Element);
        PrintList(L);
    }
    else{
        printf("查找失败\n");
    }
    return 0;
}