#include <stdio.h>

//typedef 的作用就是起别名

typedef struct student{
    int number;
    char name[100];
} stu, *pstu;   //可定义多个别名   stu为结构体类型别名  pstu为结构体指针类型别名
typedef int INTEGER;  //给int起别名
int main()
{
    stu s = {1001, "lili"}; // stu s 等价于struct student s;
    pstu p;                 // pstu p 等价于 struct student *p;  也可以写为stu *p
    p = &s;
    INTEGER i = 10;
    printf("i=%d,p->number=%d\n",i,p->number);
    return 0;
}