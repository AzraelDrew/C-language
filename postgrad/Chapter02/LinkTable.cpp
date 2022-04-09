#include <stdio.h>
#include <stdlib.h>

//线性表的链式存储(链表)

//单链表
//头指针指向第一个节点的地址  头指针永远指向 头节点(没有数据,只存放地址)
typedef int ElemType;
typedef struct LNode
{  
    ElemType data;  //存放数据
    struct LNode *next;  //指向下一个结点 
} LNode, *LinkList;

LinkList ListHeadInsert(LinkList &L) //list_head_insert
{ 
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));   //带头结点的链表
    L->next = NULL;
    scanf("%d",&x);
    while (x!=9999)
    {
        s = (LNode *)malloc(sizeof(LNode));   //申请一个新空间用于存放数据
        s->data = x;   //把读取到的值赋值给新空间
        s->next = L->next;  //让新结点指向链表的第一个元素(存放数据的第一个元素)
        L->next = s;  //让s作为一个元素
        scanf("%d", &x);
    }
    return L;
}
void PrintList(LinkList L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%d\n",L->data);
        L = L->next;
    }
}
int main()
{
    LinkList L;  //链表头,结构体指针类型
    LinkList search;
    ListHeadInsert(L);
    PrintList(L);
    PrintList(L);
    return 0;
}  