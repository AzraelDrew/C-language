// 素数求和
#include <stdio.h>
int isPrime(int i)
{
  int ret = 1;
  int k;
  for (k = 2; k < i - 1; k++)
  {
    if (i % k == 0)
    {
      ret = 0;
      break;
    }
  }
  return ret;
}
void sum2(int start, int end)
{
  int i;
  int sum = 0;
  for (i = start; i <= end; i++)
  {
    sum += i;
  }
  printf("%d到%d的和是%d\n", start, end, sum);
}
int main()
{
  int m, n;
  int sum = 0;
  int cnt = 0;
  int i;
  scanf("%d %d", &m, &n);
  if (m == 1)
    m = 2;
  for (i = m; i <= n; i++)
  {

    if (isPrime(i))
    {
      sum += i;
      cnt++;
    }
  }
  printf("%d %d\n", cnt, sum);

  sum2(1, 10);
  sum2(20, 30);
  sum2(35, 45);
  return 0;
}