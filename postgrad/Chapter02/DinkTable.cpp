#include <stdio.h>
#include <stdlib.h>
//双向链表


typedef int ElemType;
typedef struct DNode
{  
    ElemType data;  //存放数据
    struct DNode *pre;  //前驱指针
    struct DNode *next;  //后继指针 
} DNode, *DLinkList;
DLinkList DListHeadrInsert(DLinkList &DL){   //头插法
    DLinkList s;
    int x;
    DL = (DLinkList)malloc(sizeof(DNode));   //带头结点的双向链表
    DL->pre = NULL;
    DL->next = NULL;
    scanf("%d",&x);
    while(x!=9999)
    {
        s = (DLinkList)malloc(sizeof(DNode));
        s->data = x;
        s->next = DL->next;  //让插入的结点的后继指向头结点指向的元素
        if(DL->next!=NULL){  //插入第一个结点是不需要这一步操作
            DL->next->pre = s;   //让头结点的后一个结点的前驱 指向要插入的元素
        }
        s->pre = DL;  //要插入的结点的前驱 指向头结点
        DL->next = s; //头结点的后继 指向要插入的结点
        scanf("%d", &x);
    }
    return DL;
}

DLinkList DListValueSearchItem(DLinkList DL, int i);

bool DListIndexInsert(DLinkList DL, int i,ElemType  e){  //删除时没有改变头结点可以不使用引用
    DLinkList p = DListValueSearchItem(DL, i-1);
    if(p== NULL){
        return false;
    }
    DLinkList s = (DLinkList)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    p->next->pre = s;
    s->pre = p;
    p->next = s;
    return true;
}
DLinkList DListEndInsert(DLinkList &DL){   //尾插法
    DL = (DLinkList)malloc(sizeof(DNode));
    int x;
    DLinkList s, r=DL;
    DL->next = NULL;
    DL->pre = NULL;
    scanf("%d", &x);
    while (x!=9999)
    {
        s = (DLinkList)malloc(sizeof(DNode));
        s->data = x;
        r->next =  s;
        s->pre = r;
        r = s;
        scanf("%d", &x);
    }
    r -> next = NULL;
    return DL;
}
bool DListIndexDelete(DLinkList DL, int i){   //删除时没有改变头结点可以不使用引用
    DLinkList p = DListValueSearchItem(DL, i - 1);
    if(p ==NULL){
        return false;
    }
    DLinkList q  = p->next;
    if(q==NULL){
        return false;
    }
    p->next = q->next;
    if(q->next != NULL){
        q->next->pre = p->next;
    }
    free(q);
    q = NULL;
    return true;
}
DLinkList DListValueSearchItem(DLinkList DL, int i)
{

    int j = 1;
    DLinkList p = DL->next;
    if(i==0){
        return DL;
    }
    if(i<1){
        return NULL;
    }
    while(p &&j<i){
        p = p->next;
        j++;
    }
    return p;
}
void PrintList(DLinkList DL)
{
    DL = DL->next;
    while(DL != NULL)
    {
        printf("%-3d",DL->data);
        DL = DL->next;

    }
    printf("\n");
}
int main()
{
    DLinkList DL,DL2;
    DLinkList search;
    DListHeadrInsert(DL);  //头插法
    PrintList(DL);
    // DListEndInsert(DL2);  //尾插法
    // PrintList(DL2);
    search = DListValueSearchItem(DL, 2);
    printf("%d\n", search->data);
    DListIndexInsert(DL, 2, 99);
    PrintList(DL);
    search = DListValueSearchItem(DL, 2);
    printf("%d\n", search->data);
    DListIndexDelete(DL, 2);
    PrintList(DL);
    return 0;
}  