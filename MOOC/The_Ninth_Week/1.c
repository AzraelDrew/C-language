#include <stdio.h>
void minmax(int a[], int len, int *max, int *min);
int divide(int a, int b, int *result);
int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 98, 9, 34, 34, 23, 4, 567, 46, 3, 45};
  int min, max;
  minmax(a, sizeof(a) / sizeof(a[0]), &max, &min);
  printf("min=%d,max=%d\n", min, max);

  int b = 5;
  int c = 2;
  int d;
  if (divide(b, c, &d))
  {
    printf("%d/%d=%d\n", b, c, d);
  }
  return 0;
}
void minmax(int a[], int len, int *max, int *min)
{
  int i;
  *min = *max = a[0];
  for (i = 1; i < len; i++)
  {
    if (a[i] < *min)
    {
      *min = a[i];
    }
    if (a[i] > *max)
    {
      *max = a[i];
    }
  }
}
int divide(int a, int b, int *result) //如果除法成功，返回1，否则返回0
{
  int ret = 1;
  if (b == 0)
  {
    ret = 0;
  }
  else
  {
    *result = a / b;
  }
  return ret;
}
