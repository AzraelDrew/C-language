#include <stdio.h>
int max(int a, int b)
{
  int ret;
  if (a > b)
  {
    ret = a;
  }
  else
  {
    ret = b;
  }
  return ret; //停止函数的执行   并返回一个值
}
int main()
{
  max(10, 40);
  printf("%d\n", max(20, 10));
  return 0;
}