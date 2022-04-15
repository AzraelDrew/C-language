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

LinkList ListHeadInsert(LinkList &L) //头插法
{ 
    // LNode *s;
    LinkList s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));   //带头结点的链表
    L->next = NULL;
    scanf("%d",&x);
    while (x!=9999)
    {
        s = (LNode *) malloc(sizeof(LNode));   //申请一个新空间用于存放数据
        s->data = x;   //把读取到的值赋值给新空间
        s->next = L->next;  //让新结点指向链表的第一个元素(存放数据的第一个元素)
        L->next = s;  //让s作为一个元素
        scanf("%d", &x);
    }
    return L;
}
LinkList ListIndexSearchItem(LinkList L, int i);

bool ListIndexInsert(LinkList &L,int i,ElemType e)   //按位置插入
{
    LinkList p = ListIndexSearchItem(L, i-1);  //拿到要插入位置的其那一个位置的地址值
    if(p==NULL){
        return false;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;  //将要插入的值放入新结点
    s->next = p->next;  //将你要插入的位置的原结点的地址赋值给新结点
    p->next = s;   //将要插入的位置的前一个结点指向新节点
    return true; 
}
LinkList ListEndInsert(LinkList &L) //尾插法
{
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    // LNode *s,*r=L;
    LinkList s, r = L;   //r代表链表表尾结点,指向链表尾部
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;  //让尾部结点指向新结点
        r = s;   //让r指向新的尾部结点
        scanf("%d", &x);
    }
    r->next = NULL;  //尾结点next设置为NULL   若不设置为NULL 尾结点next会有一个不为NULL默认值   从而在打印的时候会找不到数据或找到错误的数据
    return L; 
}
bool ListIndexDelete(LinkList L,int i)   //按位置删除
{
    LinkList p = ListIndexSearchItem(L, i - 1);
    if(p == NULL)
    {
        return false; 
    }
    LinkList q = p->next;  //存放需要删除的结点
    p->next = q->next;    //将需要删除的节点的前一个结点指向需要删除的后一个结点
    free(q);   //释放删除的节点
    q = NULL;   //避免野指针
    return true;
}
LinkList ListIndexSearchItem(LinkList L,int i)   //按位置查询
{
    int j = 1;
    LinkList p= L->next;//让p指向第一个元素  (L指向的是头结点)
    if(i==0)   //i为0返回头结点
    {
        return L;   
    }  
    if(i<1)   //i为负值返回空
    {
        return NULL;
    }
    while(p && j<i)
    {
        p = p->next;   //让p指向下一个结点
        j++;
    }
    return p;
}
LinkList ListValueSearchItem(LinkList L,ElemType e,ElemType &index)
{
    LinkList p = L->next;
    int i = 1;
    while (p != NULL && p->data != e)  //写 p!=NULL 与 p 效果相同   
    {
        p = p->next;
        i++;
        index = i;
    }
    return p;
}
void PrintList(LinkList L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%-3d",L->data);  //打印当前结点数据
        L = L->next;  //指向下一个结点
    }
    printf("\n");
}
int main()
{
    LinkList L;  //链表头,结构体指针类型
    LinkList search;
    ElemType index;
    // ListHeadInsert(L);   //头插法
    // PrintList(L);
    ListEndInsert(L);
    PrintList(L);
    search= ListIndexSearchItem(L, 2);
    if(search!=NULL)
    {
    printf("按序号查找成功,数据为:%d\n",search->data);
    }
    search= ListValueSearchItem(L,2,index);
    if(search!=NULL)
    {
    printf("按值查找成功,位置为:%d\n",index);
    }
    ListIndexInsert(L,1,99);
    PrintList(L);
    printf("%d\n", L->next->data);
    ListIndexDelete(L, 4);
    PrintList(L);
    ListIndexInsert(L,3,88);
    PrintList(L);

    return 0;
}  