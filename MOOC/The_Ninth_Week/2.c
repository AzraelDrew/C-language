#include <stdio.h>
void minmax(int a[], int len, int *max, int *min);
int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 98, 9, 34, 34, 23, 4, 567, 46, 3, 45};
  int min, max;
  minmax(a, sizeof(a) / sizeof(a[0]), &max, &min);
  printf("min=%d,max=%d\n", min, max);
  printf("main=%p\n", a); //函数的数组参数的指针

  return 0;
}
void minmax(int a[], int len, int *max, int *min)
{
  int i;
  printf("minmax=%p\n", a); //函数的数组参数的指针
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
