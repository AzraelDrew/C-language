#include <stdio.h>

int f();
int gAll; //全局变量没有初始化时为0;
int main()
{
  int gAll = 10;                             //如果存在与全局变量局部变量同名的情况  全局变量会被隐藏
  printf("in %s gAll=%d\n", __func__, gAll); //__func__  当前的函数名
  f();
  printf("agn in %s gAll=%d\n", __func__, gAll);
  return 0;
}
int f()
{
  printf("in %s gAll=%d\n", __func__, gAll);
  gAll += 2;
  printf("agn in %s gAll=%d\n", __func__, gAll);
}