#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  //   	strchr(s1, s2);
  // 返回一个指针，指向字符串 s1 中字符 s2 的第一次出现的位置。(从左往右)
  //   	strrchr(s1, s2);
  // 返回一个指针，指向字符串 s1 中字符 s2 的第一次出现的位置。(从右往左)
  char s[] = "Hello";

  char *p = strchr(s, 'l');
  // p = strchr(p + 1, 'l');
  char *q = strrchr(s, 'l');
  char *t = (char *)malloc(strlen(p) + 1);
  strcpy(t, p);
  printf("%s\n", t);
  printf("%s\n", p);
  printf("%s\n", q);
  char c = *p;
  *p = '\0';
  t = (char *)malloc(strlen(s) + 1);
  strcpy(t, s);
  printf("%s\n", t);
  printf("%s\n", s);
  *p = c;
  printf("%s\n", s);

  return 0;
}