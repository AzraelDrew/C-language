#include <stdio.h>
int main()
{
  char ac[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
  char *p = ac;
  if (p == &ac[0]) //指针可以比较
  {
    printf("指针相同\n");
  }
  else
  {
    printf("指针不相同\n");
  }
  char *p1 = &ac[5];
  printf("p  =%p\n", p);
  printf("p+1=%p\n", p + 1);
  printf("*(p+1)=%d\n", *(p + 1));
  printf("p1-p=%ld\n", p1 - p);
  // *(p+n) <=> ac[n]
  int ai[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *q = ai;
  int *q1 = &ai[8];
  printf("q  =%p\n", q);
  printf("q+1=%p\n", q + 1);
  printf("*(q+1)=%d\n", *(q + 1));
  //指针+1的时候不是地址子+1而是加一个sizeof(type)   指针+1是指向下一个元素
  printf("q1-q=%ld\n", q1 - q);
  for (p = ac; *p != -1; p++)
  {
    printf("%d\n", *p);
  }
  return 0;
}