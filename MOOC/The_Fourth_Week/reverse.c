#include <stdio.h>
int main()
{
  int x;
  printf("请输入一个整数:");
  scanf("%d", &x);
  int digit;
  int ret = 0;
  while (x > 0)
  {
    digit = x % 10;
    // printf("%d",digit);  //700 输出 007
    ret = ret * 10 + digit; //700 输出7
    // printf("x=%d,digit=%d,ret=%d\n",x,digit,ret);
    x /= 10;
  }
  printf("\n");
  printf("%d\n", ret); //700 输出7
                       // printf("%d\n",x);
}