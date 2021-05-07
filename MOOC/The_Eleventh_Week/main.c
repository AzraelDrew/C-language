/* 多文件   */
#include <stdio.h> //<>只会在系统中查找
#include "max.h"   //""还会在当前目录下查找
#include "min.h"
int main()
{
  int a = 5;
  int b = 6;
  printf("%d\n", max(a, gAll));
  return 0;
}