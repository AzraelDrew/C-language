#include <stdio.h>
int main()
{
  int i = 0;
  char *s = "Hello,World"; //只读的   相同的字符串地址相同
  char *s2 = "Hello,World";
  char s3[] = "Hello,World";
  // s[0] = 'B';
  s3[0] = 'B';
  printf("&i=%p\n", &i);
  printf("s =%p\n", s);
  printf("s2=%p\n", s2);
  printf("s3=%p\n", s3);
  printf("Here!s[0]=%c\n", s3[0]);
  return 0;
}

//数组：这个字符串在这里  变量空间会被自动回收
//指针：这个字符串不知道在那   动态分配空间