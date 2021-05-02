#include <stdio.h>
int main()
{
  int a, b, t, c;
  int max(int x, int y, int t);
  scanf("%d%d%d", &a, &b, &t);
  c = max(a, b, t);
  int f = 2, g = 5, h = 7;
  int l = max(f, g, h);
  printf("max = %d\n", c);
  printf("max = %d\n", l);
  return 0;
}

int max(int x, int y, int t)
{
  int z;
  if (x > y)
  {
    if (x > t)
    {
      z = x;
    }
    else
    {
      z = t;
    }
  }
  else
  {
    if (y > t)
    {
      z = y;
    }
    else
    {
      z = t;
    }
  }

  //z = x>y ? x:y;
  int i = 8;
  printf("%d ", ++i);
  printf("%d ", --i);
  printf("%d ", i++);
  printf("%d ", i--);
  printf("%d \n", i);
  return (z);
}