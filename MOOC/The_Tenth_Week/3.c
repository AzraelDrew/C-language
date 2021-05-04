/* 结构作为函数的参数 */
#include <stdio.h>
struct point
{
  int x;
  int y;
};
struct date
{
  int month;
  int day;
  int year;
};

struct point getStruct1(void);
void getStruct(struct point p);
void outPut(struct point p);
struct point *inputPoint(struct point *p);
void print(const struct point *P);
int main()
{
  // struct point y = {0, 0};
  // getStruct(y);
  // outPut(y);
  // y = getStruct1();
  // outPut(y);
  // struct date myday;
  // struct date *p = &myday;
  // p->day = 12; //结构为指针时  使用->访问变量
  // printf("%d\n", p->day);

  struct point x = {0, 0};
  // inputPoint(&x);
  // outPut(x);
  // outPut(*inputPoint(&x));
  // print(inputPoint(&x));
  *inputPoint(&x) = (struct point){1, 2};
  printf("%d %d\n", x.x, x.y);
  return 0;
}

struct point getStruct1(void)
{
  struct point p;
  scanf("%d", &p.x);
  scanf("%d", &p.y);
  printf("%d %d\n", p.x, p.y);
  return p;
}
void getStruct(struct point p) //结构的传递是传值
{
  scanf("%d", &p.x);
  scanf("%d", &p.y);
  printf("%d %d\n", p.x, p.y);
}
void outPut(struct point p)
{
  printf("%d %d\n", p.x, p.y);
}
struct point *inputPoint(struct point *p)
{
  scanf("%d", &p->x);
  scanf("%d", &p->y);
  return p;
}
void print(const struct point *p)
{
  printf("%d %d\n", p->x, p->y);
}