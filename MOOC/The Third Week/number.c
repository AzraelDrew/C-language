#include <stdio.h>
int main()
{
	int x;
	int n = 0;
	printf("请输入一个整数:");
	scanf("%d", &x);
	n++;
	if (x < 0)
	{
		x = -x;
	}
	x /= 10;
	while (x > 0)
	{
		n++;
		x /= 10;
		printf("x=%d,n=%d\n", x, n);
	}

	printf("你输入的数为%d位数\n", n);
	return 0;
}
