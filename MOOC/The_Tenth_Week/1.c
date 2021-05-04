#include <stdio.h>
int main()
{
  enum COLOR
  {
    RED = -1,
    YELLOW,
    GREEN
  };
  enum COLOR color = RED;
  printf("%d\n", color);
  return 0;
}