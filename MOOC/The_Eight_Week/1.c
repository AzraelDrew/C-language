#include <stdio.h>
void f(int *p);
void g(int k);
int main()
{
  int a = 656;
  printf("sizeof(double)=%ld\n", sizeof(double)); //sizeof()给出莫个类型或变量在内存中所中所占据的字节数
  printf("sizeof(int)=%ld\n", sizeof(int));
  printf("sizeof(a)=%ld\n", sizeof(a));

  // 运算符&    获得变量的地址，  操作的必须是变量
  int i = 0;
  int p;

  printf("%p\n", &i);
  printf("%p\n", &p);

  p = (int)&i;

  printf("0x%x\n", p);
  printf("%p\n", &i);

  printf("%lu\n", sizeof(int));
  printf("%lu\n", sizeof(&i));

  int b[10];

  // 数组的地址为数组的第一个元素的地址
  printf("%p\n", &b);
  printf("%p\n", b);
  printf("%p\n", &b[0]);
  printf("%p\n", &b[1]);

  // 指针   保存地址的变量

  int j;
  int *q = &j;
  int k = 6;
  printf("&i=%p\n", &k);
  f(&k);
  g(k);
  return 0;
}
void f(int *p)
{
  printf(" p=%p\n", p);
  printf("*p=%d\n", *p);
  *p = 26;
}
void g(int k)
{
  printf("k=%d\n", k);
}