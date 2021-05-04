#include <stdio.h>
#include <stdlib.h>
int main()
{
  int number;
  int *a;
  int i;
  printf("输入数量:");
  scanf("%d", &number);
  // int a[number];
  a = (int *)malloc(number * sizeof(int)); //malloc  申请内存空间  以字节为单位
  for (i = 0; i < number; i++)
  {
    scanf("%d", &a[i]);
  }
  for (i = number - 1; i >= 0; i--)
  {
    printf("%d\n", a[i]);
  }
  free(a); //返还空间
  return 0;
}