#include <stdio.h>
int main()
{
  char c;
  char d;
  c = 1;
  d = '1';
  if (c == d) //类型不同
  {
    printf("相等\n");
  }
  else
  {
    printf("不相等\n");
  }
  if (49 == d)
  {
    printf("相等\n");
  }
  else
  {
    printf("不相等\n");
  }
  printf("c=%d\n", c);
  printf("d=%d\n", d);
  printf("d='%c'\n", d);

  printf("123\t456\n"); //\t到下一个制表位
  printf("12\t456\n");
  return 0;
}