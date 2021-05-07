/* 自定义类型typedef     typedef  oldname newname  */
#include <stdio.h>
int main()
{
  typedef long int64_t;
  typedef struct ADate
  {
    int month;
    int day;
    int year;
  } Date;

  int64_t i = 1000000;
  Date d = {5, 5, 2021};
  return 0;
}