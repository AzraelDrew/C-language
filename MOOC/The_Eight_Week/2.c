#include <stdio.h>
void arr(int a[]) //函数参数表中的数组实际上是指针

// int sum(int *ar);  ==  int sum(int *);  ==int sum (int ar[]);  ==int sum (int []);
{
  printf("%p\n", a);
  a[0] = 1000;
}
int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7}; //数组变量本身就是地址
  printf("%p\n", a);               //数组的地址不需要使用&
  printf("%p\n", &a[0]);           //a ==&a[0]    数组的单元表达的是变量，需要使用&去地址
  printf("%d\n", *a);
  printf("%d\n", a[0]);
  arr(a);
  printf("%d\n", a[0]);

  int *p;
  int q = 10;
  p = &q;
  printf("%d\n", p[0]); //p为指针，把p看作一个数组

  printf("%d\n", *a);

  // int b[] = a;   //数组变量是一个const的指针，不能被赋值

  return 0;
}