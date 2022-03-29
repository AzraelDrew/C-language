#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// int main()
// {
// char c[100],d[100];
// gets(c);
// int i,j;
// for(i=strlen(c)-1,j=0;i>=0;i--,j++)
// {
// 	d[j] = c[i];
// }
// d[j]  = '\0';
// int result = strcmp(c, d);
// if (result < 0)
// {
// printf("%d\n",-1);
// }
// else if (result > 0)
// {
// printf("%d\n", 1);
// }
// else {
// printf("%d\n", 0);
// }
// }

int main()
{
	char *p;
  	int n;
  	scanf("%d",&n);
	p = (char*)malloc(n);
  	char c;
  	scanf("%c",&c);   // 为了去除缓冲区中的'\n'
  	gets(p);
    puts(p);
	free(p);
	return 0;
}