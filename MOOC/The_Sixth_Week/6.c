#include <stdio.h>

// 自定义的函数必须写在main之前
void sum(int start, int end); //声明
int swap(int a, int b);

int main()
{
  sum(10, 50);
  int a = 5;
  int b = 6;
  swap(a, b); //c语言在调用函数时，永远只能传值给函数
  printf("a=%d,b=%d\n", a, b);
  return 0;
}
//定义
void sum(int start, int end)
{
  int i;
  int sum = 0;
  for (i = start; i <= end; i++)
  {
    sum += i;
  }
  printf("%d到%d的和是%d\n", start, end, sum);
}
int swap(int a, int b)
{
  int t = a;
  a = b;
  b = t;
}
