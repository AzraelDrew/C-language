#include <stdio.h>
int main()
{
	int n = 0;
	int x;
	printf("请输入一个整数:");
	scanf("%d", &x);
	do {
		x /= 10;
		n++;
	} while (x > 0);
	printf("你输入数为%d数\n", n);
}
