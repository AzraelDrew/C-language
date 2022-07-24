#  代码及作业



>  顺序表

```c++
#include <stdio.h>
#include <stdlib.h>
//线性表的顺序存储(线性表)

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




//作业

#include "stdio.h"
#include "stdlib.h"
#define  MaxSize 50
typedef int ElemType;
typedef struct{
  ElemType data[MaxSize];
  int len;
}SqList;
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1||i>L.len+1){
        return false;
    }
    if(L.len==MaxSize){
        return false;
    }
    for (int j = L.len; j >=i;j--){
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.len++;
    return true;
}
bool ListDelete(SqList &L,int i){

    if(L.len==0){
        return false;
    }
    if(i<1 || i>L.len+1){
        return false;
    }
    for (int j = i; j < L.len;j++){
        L.data[j - 1] = L.data[j];
    }

    L.len--;
    return true;
}

void PrintList(SqList &L){
    for(int i=0;i<L.len;i++){
        printf("%3d", L.data[i]);
    }
    printf("\n");
}
int main(){
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.len = 3;
    int n ,m;
    scanf("%d%d", &n,&m);
    ListInsert(L, 2, n);
    PrintList(L);
    if(!ListDelete(L, m)){
        printf("false\n");
    }
    else{
   		PrintList(L);
    }

    return 0;
}
```

> 单链表

```c++
#include <stdio.h>
#include <stdlib.h>
//线性表的链式存储(链表)

//单链表
//头指针指向第一个节点的地址  头指针永远指向 头节点(没有数据,只存放地址)
typedef int ElemType;
typedef struct LNode
{  
    ElemType data;  //存放数据
    struct LNode *next;  //指向下一个结点    此处不能使用LinkList声明变量next  因为前面还没有定义LinkList
} LNode, *LinkList;

LinkList ListHeadInsert(LinkList &L) //头插法
{ 
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

bool ListIndexInsert(LinkList L,int i,ElemType e)   //按位置插入      没有改变头结点可以不使用引用
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
bool ListIndexDelete(LinkList L,int i)   //按位置删除   删除时没有改变头结点可以不使用引用
{
    LinkList p = ListIndexSearchItem(L, i - 1);
    if(p == NULL)
    {
        return false;  
    }
    LinkList q = p->next;  //存放需要删除的结点
    if(q==NULL){
        return false;
    }
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
void ListValueChange(LinkList L, int i, ElemType e)
{
    LinkList p = L->next;
    int j = 1;
    while (p != NULL)
    {
        if(j==i){
            p->data = e;
        }
        j++;
        p= p->next;
    }
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
    ListValueChange(L,3,44);
    PrintList(L);

    return 0;
}  

//作业


#include "stdio.h"
#include "stdlib.h"
typedef int Elemtype;
typedef struct LNode
{
  Elemtype data;
  struct LNode *next;
}Lnode,*LinkList;

LinkList ListHeadInsert(LinkList &L)
{
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  LinkList s;
  int x;
  scanf("%d",&x);
  while(x!=9999)
  {
    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next= s;
    scanf("%d",&x);
  }
  return L;
}
LinkList ListEndInsert(LinkList &L)
{
  L=(LinkList)malloc(sizeof(LNode));
  L->next=NULL;
  LinkList s, r = L;
  int x;
  scanf("%d",&x);
  while(x!=9999)
  {
  	s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r=s;
    scanf("%d",&x);
  }
  r->next = NULL;
  return L;
}
void PrintList(LinkList L) {
 L = L->next;
 while (L != NULL) {
  printf("%d", L->data);
  L = L->next;
  if (L != NULL) {
   printf(" ");
  }
 }
 printf("\n");
}
int main()
{
LinkList L,F;
ListHeadInsert(L);
ListEndInsert(F);
PrintList(L);
PrintList(F);
return 0;
}
```

> 双链表

```c++
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
```

> 栈

```c++
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
```

> 队列

```c++
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
```

