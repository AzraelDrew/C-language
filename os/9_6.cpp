#include "stdio.h"
#include "stdlib.h" 
#include "iostream"
#define null 0 
#define len sizeof(struct page)  

struct page
{
	int num;
	int tag;
	struct page *next;
};

struct page *create(int n)
{
	int count = 1;
	struct page *p1, *p2, *head;
	head = p2 = p1 = (struct page *)malloc(len);
	p1->tag = -1; p1->num = -1;
	while (count<n)
	{
		count++;
		p1 = (struct page *)malloc(len);
		p1->tag = -1; p1->num = -1;
		p2->next = p1;
		p2 = p1;
	}
	p2->next = null;
	return(head);
}

void LRU(int* array,int n)
{
	int count = 0, *p = array;
	struct page *head, *cp, *dp, *rp, *New, *endp;
	head = create(n);
	while (*p != -1)
	{
		cp = dp = rp = endp = head;
		for (; endp->next != null;) endp = endp->next;
		for (; cp->num != *p&&cp->next != null;)
		{
			rp = cp; cp = cp->next;
		}
		if (cp->num == *p)
		{
			printf(" ! ");
			if (cp->next != null)
			{
				if (cp != head)
					rp->next = cp->next;
				else head = head->next;
			}
			endp->next = cp;
			cp->next = null;
		}
		else
		{
			count++;
			cp = rp = head;
			for (; cp->tag != -1 && cp->next != null;) cp = cp->next;
			if (cp->tag == -1)
			{
				printf(" * ");
				cp->num = *p;
				cp->tag = 0;
			}
			else
			{
				New = (struct page *)malloc(len);
				New->num = *p;
				New->tag = 0;
				New->next = null;
				cp->next = New;
				dp = head;
				head = head->next;
				printf(" %d ", dp->num);
				free(dp);
			}
		}
		p++;
	}
	printf("\nQueye Zongshu : %d \n", count);
}

int main()
{
	FILE *fp;
	char pt;
	char str[10];
	int i, j = 0;
	int page[50], space = 0;
	for (i = 0; i<50; i++)
		page[i] = -1;
	fp = fopen("page.txt", "r+");
	if (fp == NULL)
	{
		printf("Cann't open the file\n");
		exit(0);
	}
	i = 0;
	while ((pt = fgetc(fp)) != EOF)
	{
		if (pt >= '0'&&pt <= '9')
		{
			str[i] = pt; i++;
			space = 0;
		}
		else
		{
			if (pt == ' ' || pt == '\n')
			{
				if (space == 1) break;
				else
				{
					str[i] = '\0';
					page[j] = atoi(str);
					if (pt == '\n') break;
					else
					{
						space = 1;
						j++;
						i = 0;
					}
				}
			}
		}
	}
	if (pt == EOF) { str[i] = '\0'; page[j] = atoi(str); }
	i = 0;
	while (page[i] != -1) { printf(" %d ", page[i]); i++; }
	fclose(fp);
	printf("\n");
	printf(" ! : mean no moved \n * : mean have free space \n\n");
	printf("\nLRU ");
	LRU(page, 3);
	return 0;
}
