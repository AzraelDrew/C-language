#include <stdio.h>
struct date
{
  int month;
  int day;
  int year;
};
int main()
{
  struct date ToDay;
  struct date ThisMonth = {.year = 2021, .month = 5}; //没有初始化的变量为0
  ToDay.month = 05;
  ToDay.day = 04;
  ToDay.year = 2021;
  printf("ToDay's date is %i-%i-%i.\n", ToDay.year, ToDay.month, ToDay.day);
  printf("ThisMonth's date is %i-%i-%i.\n", ThisMonth.year, ThisMonth.month, ThisMonth.day);
  struct date day;
  day = ToDay;
  day.year = 2022;
  printf("day's date is %i-%i-%i.\n", day.year, day.month, day.day);

  return 0;
}