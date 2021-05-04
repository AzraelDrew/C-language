#include <stdio.h>
#include <string.h>

int main()
{

  // strcpy(src,dst)   把dst拷贝到src

  char src[] = "zsdf";
  char dst[] = "abc";
  strcpy(src, dst);
  printf("%s\n", src);
  return 0;
}