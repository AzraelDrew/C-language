#include "stdio.h"
void forEach(int arr[], int size);
int search(int key, int a[], int length);
int main()
{
  int count[] = {1, 2, 3, 4, 45, 5, 6, 7};
  int a[12] = {[0] = 1, [2] = 5, 7, [5] = 10}; //[0]=1   [2]=5,[3]=7  其他为0
  // int b[] = a;    //不能这么做
  forEach(count, sizeof(count) / sizeof(count[0]));
  forEach(a, sizeof(a) / sizeof(a[0]));

  int x;
  int loc;
  printf("请输入一个数字：");
  scanf("%d", &x);
  loc = search(x, count, sizeof(count) / sizeof(count[0]));
  if (loc != -1)
  {
    printf("%d在第%d个位置上\n", x, loc);
  }
  else
  {
    printf("%d不存在!", x);
  }
  return 0;
}
void forEach(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d\n", arr[i]);
  }
}
int search(int key, int a[], int length)
{
  int ret = -1;
  int i;
  for (i = 0; i < length; i++)
  {
    if (a[i] == key)
    {
      ret = i;
      break;
    }
  }
  return ret;
}