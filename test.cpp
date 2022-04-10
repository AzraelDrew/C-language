// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// // int main()
// // {
// // char c[100],d[100];
// // gets(c);
// // int i,j;
// // for(i=strlen(c)-1,j=0;i>=0;i--,j++)
// // {
// // 	d[j] = c[i];
// // }
// // d[j]  = '\0';
// // int result = strcmp(c, d);
// // if (result < 0)
// // {
// // printf("%d\n",-1);
// // }
// // else if (result > 0)
// // {
// // printf("%d\n", 1);
// // }
// // else {
// // printf("%d\n", 0);
// // }
// // }

// int main()
// {
// 	char *p;
//   	int n;
//   	scanf("%d",&n);
// 	p = (char*)malloc(n);
//   	char c;
//   	scanf("%c",&c);   // 为了去除缓冲区中的'\n'
//   	gets(p);
//     puts(p);
// 	free(p);
// 	return 0;
// }

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
void PrintList(LinkList L)
{
	L= L->next;
  	while(L!=NULL)
    {
    printf("%-2d",L->data);
    L=L->next;
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