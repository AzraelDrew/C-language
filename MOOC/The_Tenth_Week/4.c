#include <stdio.h>
struct time
{
  int hour;
  int minutes;
  int seconds;
};
struct date
{
  int month;
  int day;
  int year;
};
struct dateAndTime
{
  struct date sdate;
  struct time stime;
};

struct time timeUpdate(struct time now);
int main()
{
  struct time testTime[5] = {
      {11, 59, 59}, {12, 0, 0}, {1, 29, 59}, {23, 59, 59}, {19, 12, 27}};
  int i;
  for (i = 0; i < 5; i++)
  {
    printf("Time is %.2i:%.2i:%.2i  ", testTime[i].hour, testTime[i].minutes, testTime[i].seconds);
    testTime[i] = timeUpdate(testTime[i]);
    printf("...one second later it's %.2i:%.2i:%.2i\n", testTime[i].hour, testTime[i].minutes, testTime[i].seconds);
  }

  struct dateAndTime dt;
  dt.sdate.month = 10;
  printf("%d\n", dt.sdate.month);
  struct dateAndTime d1, *d2;
  d2 = &d1;
  d1.sdate.month = 10;
  printf("%d\n", d1.sdate.month);
  d2->sdate.month = 11;
  printf("%d\n", d1.sdate.month);
  return 0;
}

struct time timeUpdate(struct time now)
{
  ++now.seconds;
  // printf("%2.i  ", now.seconds);
  if (now.seconds == 60)
  {
    now.seconds = 0;
    ++now.minutes;
    if (now.minutes == 60)
    {
      // printf("%2.i  ", now.minutes);
      now.minutes = 0;
      ++now.hour;
      // printf("%2.i  ", now.hour);
      if (now.hour == 24)
      {
        now.hour = 0;
      }
    }
  }
  return now;
}