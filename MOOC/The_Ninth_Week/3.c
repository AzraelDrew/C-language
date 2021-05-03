#include <stdio.h>
int main()
{
  int a = 1;
  int *const p = &a;

  // p = &b;
  *p = 10;
  // printf("%p\n", p);
  // printf("%d\n", *p);
  // printf("%p\n", p);
  return 0;
}