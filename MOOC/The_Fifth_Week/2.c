#include "stdio.h"
int main()
{
  int i;
  int j;
  int count = 0;
  for (i = 2; count < 50; i++)
  // i = 2;
  // while (count < 50)
  {
    int isPrime = 1; //每次执行for循环都会执行这条语句
    for (j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        isPrime = 0;
        break;
      }
    }
    if (isPrime == 1)
    {
      printf("%d\n", i);
      count++;
    }
  }
}