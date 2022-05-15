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
#include <iostream>
#include <stdio.h>
#include "stdlib.h"
#define n 10
#define m 10
#define minisize 100

struct
{
	float address;
	float length;
	int flag;
}used_table[n];

struct
{
	float address;
	float length;
	int flag;
}free_table[m];

void allocate(char J,float xk)
{
	int i,k;
	float ad;
	k = -1;
	for(i = 0;i<m;i++)
		if(free_table[i].length>=xk&&free_table[i].flag == 1)
			if(k == -1 || free_table[i].length<free_table[k].length)
				k = i;
	if(k == -1)
	{
		printf("无可用空闲区\n");
		return;
	}
	if(free_table[k].length - xk <=minisize)
	{
		free_table[k].flag = 0;
		ad = free_table[k].address;
		xk = free_table[k].length;
	}
	else
	{
		free_table[k].length = free_table[k].length - xk;
		ad = free_table[k].address + free_table[k].length;
	}
	i = 0;
	while(used_table[i].flag!=0 && i<n)
		i++;
	if(i>=n)
	{
		printf("无表目填写已分分区\n");
		if(free_table[k].flag == 0)
			free_table[k].flag = 1;
		else
		{
			free_table[k].length = free_table[k].length + xk;
			return;
		}
	}
	else
		used_table[i].address = ad;
	used_table[i].length = xk;
	used_table[i].flag = J;
	return;
}
void reclaim(char J)
{
	int i,k,j,s,t;
	float S,L;
	s = 0;
	while((used_table[s].flag != J || used_table[s].flag == 0)&& s<n)
		s++;
	if(s>=n)
		{
			printf("找不到该作业\n");
			return;
		}
		used_table[s].flag = 0;
		S = used_table[s].address;
		L = used_table[s].length;
		j = -1;k = -1;i = 0;
		while(i<m && (j == -1 || k ==-1))
		{
			if(free_table[j].flag == 1)
			{
				if(free_table[i].address + free_table[i].length == S)k = i;if(free_table[i].address == S+L)j = i;

			}
			i++;
		}
		if(k!=-1)
			if(j!=-1)
			{
				free_table[k].length = free_table[j].length + free_table[k].length + L;
				free_table[j].flag = 0;
			}
			else
				free_table[k].length = free_table[k].length + L;
		else
			if(j!=-1)
			{
				free_table[i].address = S;
				free_table[j].length = free_table[j].length + L;
			}
			else
			{
				t  = 0;
				while(free_table[t].flag == 1 && t<m)
					t++;
				if(t >= m)
                {
                    printf("主存空闲表没有空间，回收空间失败\n");
                    used_table[s].flag = J;
                    return;
                }
                free_table[t].address = S;
                free_table[t].length = L;
                free_table[t].flag = 1;
			}
        return;
}
int main()
{
    int i,a;
    float xk;
    char J;
    free_table[0].address = 10240;
    free_table[0].length = 102400;
    free_table[0].flag = 1;
    for(i = 1;i<m;i++)
        free_table[i].flag = 0;
    for(i = 0;i<n;i++)
        used_table[i].flag = 0;
    while (1)
    {
        printf("选择功能项(0 - 退出,1 - 分配主存,2 - 回收存,3 - 显示主存)\n");
        printf("选择功项(0~3):");
        scanf("%d",&a);
        switch (a)
        {
        case 0: exit(0);
        case 1:
            printf("输入作业名J和作业所需长度 xk:");
            scanf("%*c%c%f",&J,&xk);
            allocate(J,xk);
            break;
        case 2:
        printf("输入要回收分区的作业名:");
        scanf("%*c%c",&J);
        reclaim(J);
        break;

        case 3:
            printf("输出空闲区表:\n起始地址 分区长度 标志\n");
            for(i = 0;i<m;i++)
                printf("%6.0f%9.0f%6d\n",free_table[i].address,free_table[i].length,free_table[i].flag);
                printf("按任意键,输出已分配区表\n");
                getchar();
                printf("输出已分配区表:\n起始地址 分区长度 标志\n");
                for(i = 0;i < n;i++)
                    if(used_table[i].flag != 0)
                        printf("%6.0f%9.0f%6c\n",used_table[i].address,used_table[i].length,used_table[i].flag);
                    else
                        printf("%6.0f%9.0f%6d\n",used_table[i].address,used_table[i].length,used_table[i].flag);
            break;
        
        default:printf("没有该选项\n");
        }
    }
    return 0;
    
}