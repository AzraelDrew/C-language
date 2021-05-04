#include <stdio.h>
#include <string.h>
int mycmp(const char *s1, const char *s2)
{
  while (*s1 == *s2 && *s1 != '\0')
  {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}
int main()
{
  // strcmp(s1,s2)比较字符串  s1==s3:)   s1>s2:1  s1<s2:-1

  char s1[] = "abc";
  char s2[] = "Abc";

  printf("%d\n", strcmp(s1, s2));
  printf("%d\n", mycmp(s1, s2));
  printf("%d\n", 'a' - 'A');
  return 0;
}