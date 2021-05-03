#include <stdio.h>
#include <string.h>
int main()
{
  char line[] = "Hello";
  printf("strlen=%lu\n", strlen(line));
  printf("strlen=%lu\n", sizeof(line));
  char s1[] = "abc";
  char s2[] = "abc ";
  printf("%d\n", strcmp(s1, s2));
  printf("%d\n", 'a' - 'A');
  return 0;
}
