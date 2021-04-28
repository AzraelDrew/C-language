#include <stdio.h>
int main()
{

  /*   int a, b;
  int min;
  scanf("%d %d", &a, &b);
  if (a < b)
  {
    min = a;
  }
  else
  {
    min = b;
  }
  int ret = 0;
  int i;
  for (i = 1; i < min; i++)
  {
    if (a % i == 0)
    {
      if (b % i == 0)
      {
        ret = i;
      }
    }
  }
  printf("%d和%d的最大公约数是%d.\n", a, b, ret); */

  int a, b;
  int t;
  scanf("%d %d", &a, &b);
  while (b != 0)
  {
    t = a % b;
    a = b;
    b = t;
  }
  printf("gcd=%d\n", a);
  return 0;
}
