/* 

输入输出
printf:%[flags][width][.prec][hIL]type
flag     含义
  -      左对齐
  +      在前面黄+或-
  space  正数留空
  0      0填充


  width或prec   含义
  number        最小字符
  *             下一个参数是字符
  .number       小数点后的位数
  .*            下一个参数是小数点后的位数

  类型修饰        含义
    hh          单个字节
    h           short
    I           long
    II          long long
    L           long double  
  

scanf:%[flag]type
flag     含义
  *      跳过
 */

#include <stdio.h>
int main()
{
  printf("%09d\n", 123); //9表示整个输出占据9个字符的空间
  printf("%-9d\n", 123);
  printf("%+-9d\n", 123);
  printf("%-+9d\n", 123);
  printf("%9.2f\n", 123.0);
  printf("%*d\n", 6, 123); //6用来填充这个*
  printf("%.*f\n", 6, 123.0);
  printf("%hhd\n", 12345);
  int num;
  printf("%d%n\n", 12356, &num); //%n  已经输出的字符数
  printf("%d\n", num);
  scanf("%*d%d", &num);
  printf("%d\n", num);
  return 0;
}