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

// #include "stdio.h"
// #include "stdlib.h"
// typedef int Elemtype;
// typedef struct LNode
// {
//   Elemtype data;
//   struct LNode *next;
// }Lnode,*LinkList;

// LinkList ListHeadInsert(LinkList &L)
// {
//   L = (LinkList)malloc(sizeof(LNode));
//   L->next = NULL;
//   LinkList s;
//   int x;
//   scanf("%d",&x);
//   while(x!=9999)
//   {
//     s = (LinkList)malloc(sizeof(LNode));
//     s->data = x;
//     s->next = L->next;
//     L->next= s;
//     scanf("%d",&x);
//   }
//   return L;
// }
// LinkList ListEndInsert(LinkList &L)
// {
//   L=(LinkList)malloc(sizeof(LNode));
//   L->next=NULL;
//   LinkList s, r = L;
//   int x;
//   scanf("%d",&x);
//   while(x!=9999)
//   {
//   	s = (LinkList)malloc(sizeof(LNode));
//     s->data = x;
//     r->next = s;
//     r=s;
//     scanf("%d",&x);
//   }
//   r->next = NULL;
//   return L;
// }
// void PrintList(LinkList L)
// {
// 	L= L->next;
//   	while(L!=NULL)
//     {
//     printf("%-2d",L->data);
//     L=L->next;
//     }
//   printf("\n");
// }
// int main()
// {
// LinkList L,F;
// ListHeadInsert(L);
// ListEndInsert(F);
// PrintList(L);
// PrintList(F);
// return 0;
// }
// #include "malloc.h"
// #include "malloc.h"
// #include "stdio.h"
// #include<stdio.h>
// int main()
// {
// 	int b[4][5]={1,2,4,8,10,-1,-2,-4,-8,-10,3,5,7,9,11};
// 	int i,j,n=9;
// 	i=n/5;
// 	j=n-i*5-1;
// 	printf("%d\n",b[i][j]);
//  } 


// #include <stdio.h>
// #define MaxSize 50
// typedef int ElemType;
// typedef struct
// {	
// 	ElemType data[MaxSize];
// 	int len;
// } SqList;
// void  InitList(SqList &L){
// 	L.len = 0;
// }
// bool ListInsert(SqList &L,int i,ElemType e){
// 		if(i<1 || i>L.len+1){
// 			return false;
// 		}
// 		if(L.len>= MaxSize){

// 			return false;
// 		}
// 		for (int j = L.len; j >= i;j--){
// 			L.data[j] = L.data[j - 1];

// 		}
// 		L.data[i - 1] = e;
// 		L.len++;
// 		return true;
// }

// int ListDelete(SqList &L,int i){
// 		if(i<1 || i>L.len+1){
// 			return false;
// 		}
// 		if(L.len==0){
// 			return false;
// 		}
// 		int e = L.data[i - 1];
// 		for (int j = i; j < L.len; j++)
// 		{
// 			L.data[j-1] = L.data[j];
// 		}
// 		L.len--;
// 		return e;
// }

// int ListSerach(SqList L,ElemType e){
// 	for (int i = 0; i < L.len;i++){
// 		if(L.data[i] == e){
// 			return i + 1;
// 		}
// 	}
// 	return 0;
// }
// void PrintList(SqList L){
// 	for (int i = 0; i < L.len;i++){
// 		printf("%-4d",L.data[i]);
// 	}
// 	printf("\n");
// }
// int main(){
// 	SqList L;
// 	InitList(L);
// 	L.data[0]=1;
// 	L.data[1]=2;
// 	L.data[2]=3;
// 	ElemType X;
// 	L.len = 3;
// 	int n;
// 	scanf("%d",&n);
// 	for (int i = L.len+1,len = L.len; i < (n+len+1);i++)
// 	{
// 		printf("input:\n");
// 		scanf("%d", &X);
// 		ListInsert(L, i, X);
// 	}
// 	PrintList(L);
// 	// printf("%-4d",L.len);
// 	// printf("%-4d",L.data[0]);
// 	// printf("%-4d",L.data[1]);
// 	// printf("%-4d",L.data[2]);

// 	// ListInsert(L, 4, 4);
// 	// PrintList(L);

// 	return 0;
// }



#include <stdio.h>
int a = 200;
void f()
{
	static int  a = 20;
	a++;
	printf("%d\n", a);
}

int main()
{
	for (int i = 1; i <= 3;i++){
		a++;
		printf("%d\n",a);
		f();
	}
		return 0;
}