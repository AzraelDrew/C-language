#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
ElemType data;
struct LNode *next;
}LNode,*LinkList;

LinkList ListHeadInsert(LinkList &L){
	LinkList s;
  	int x;
  	L = (LinkList)malloc(sizeof(LNode));
  	L->next = NULL;
  	scanf("%d",&x);
  	while(x!=9999){
      s = (LinkList)malloc(sizeof(LNode));
      s->data = x;
      s->next = L->next;
      L->next = s;
      scanf("%d",&x);
    }
  return L;
}

LinkList ListIndexSearchItem(LinkList L,int i){
  int j=1;
  LinkList p = L->next;
  if(i==0){
  	return L;
  }
  if(i<0){
  	return NULL;
  }
  while(p && j<i){
  	p = p->next;
    j++;
  }
  return p;
}

bool ListIndexInsert(LinkList L,int i,ElemType e){
  LinkList p = ListIndexSearchItem(L,i-1);
  if(p==NULL){
  	return false;
  }
  LinkList s = (LinkList)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListIndexDelete(LinkList L,int i){
  LinkList p = ListIndexSearchItem(L,i-1);
  if(p==NULL){
  	return false;
  }
  LinkList q = p->next;
  if(q==NULL){
      return false;
  }
  p->next = q->next;
  free(q);
  q = NULL;
  return true;
}

void PrintList(LinkList L){
L = L->next;
while (L != NULL){
printf("%-3d", L->data);//打印当前结点数据
L = L->next;//指向下一个结点
}
printf("\n");
} 
LinkList ListEndInsert(LinkList &L){
  
  int x;
  L = (LinkList)malloc(sizeof(LNode));
  LinkList s,r=L;
  L->next = NULL;
  scanf("%d",&x);
  while(x!=9999){
  	s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r=s;
    scanf("%d",&x);
  }
  r->next = NULL;
  return L;
}

int main(){
    LinkList L, search;
    ListEndInsert(L);
    search = ListIndexSearchItem(L, 2);
    printf("%d\n", search->data);
    ListIndexInsert(L, 2, 99);
    PrintList(L);
    ListIndexDelete(L, 4);
    PrintList(L);
    return 0;
}