#include "stdio.h"
int main()
{
  int x;
  printf("请输入一个数：");
  scanf("%d", &x);
  int i;
  int isPrime = 1;
  for (i = 2; i, i < x; i++)
  {
    if (x % i == 0)
    {
      isPrime = 0;
      break; //跳出当前循环
      // continue; //跳过当前循环
    }
    printf("%d\n", i);
  }
  if (isPrime == 1)
  {
    printf("是素数\n");
  }
  else
  {

    printf("不是素数\n");
  }
  return 0;
}