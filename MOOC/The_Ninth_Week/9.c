#include <stdio.h>
#include <string.h>
int mylen(const char *s);
int main()
{
  // strlen(s)  返回字符串的长度(不包括结尾的0)
  char line[] = "Hello";
  printf("strlen=%lu\n", strlen(line));
  printf("strlen=%u\n", mylen(line));
  printf("strlen=%lu\n", sizeof(line));
  return 0;
}
int mylen(const char *s)
{
  int index = 0;
  while (s[index] != 0)
  {
    index++;
  }
  return index;
}