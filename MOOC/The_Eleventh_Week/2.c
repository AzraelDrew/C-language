/* static 静态变量 */
#include <stdio.h>

int f();
int gAll; //全局变量没有初始化时为0;
int main()
{
  // printf("in %s gAll=%d\n", __func__, gAll); //__func__  当前的函数名
  f();
  // f();
  // printf("agn in %s gAll=%d\n", __func__, gAll);
  return 0;
}
int f()
{
  int k = 0;
  static int all = 1; //只会初始化一次,当没有初始值时为0   且每次调用函数时变量的值为上次离开函数的值
  // 静态变量实际是全局变量(当只能在作用域中访问)
  printf("&gAll=%p\n", &gAll);
  printf("&all =%p\n", &all);
  printf("&k   =%p\n", &k);
  printf("in %s all=%d\n", __func__, all);
  all += 2;
  printf("agn in %s all=%d\n", __func__, all);
}