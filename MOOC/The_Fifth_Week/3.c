#include "stdio.h"

int main()
{
  int x;
  int one, two, five;
  int exit = 0;
  // scanf("%d", &x);
  x = 2;
  for (one = 1; one < 10 * x; one++)
  {
    for (two = 1; two < x * 10 / 2; two++)
    {
      for (five = 1; five < x * 10 / 5; five++)
      {
        if (one + two * 2 + five * 5 == x * 10)
        {
          printf("可以用%d个一角加%d个两角加%d个五角得%d元\n", one, two, five, x);
          // exit = 1;
          // break;
          goto out; //去到out这个地方
        }
      }
      // if (exit)
      //   break;
    }
    // if (exit)
    //   break;
  }
out:
  return 0;
}