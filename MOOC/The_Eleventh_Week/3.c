#include <stdio.h>
int *f(void);
void g(void);
int main()
{
  int *p = f();
  printf("*p=%d\n", *p);
  g();
  printf("*p=%d\n", *p);
  return 0;
}
int *f(void)
{
  static int i = 12;
  // return &i; //返回局部变量的地址是危险的,当离开局部作用域后本地变量的地址会分配给其他变量
  // 不要使用全局变量和静态局部变量来在函数间传递参数和结果
  // 最好的做法是返回传入的指针
  return &i;
}
void g(void)
{
  int k = 24;
  printf("k=%d\n", k);
}