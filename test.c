#include <string.h>
#include <stdio.h>

int main()
{
char c[100],d[100];
gets(c);
int i,j;
for(i=strlen(c)-1,j=0;i>=0;i--,j++)
{
	d[j] = c[i];
}
d[j]  = '\0';
int result = strcmp(c, d);
if (result < 0)
{
printf("%d\n",-1);
}
else if (result > 0)
{
printf("%d\n", 1);
}
else {
printf("%d\n", 0);
}
}