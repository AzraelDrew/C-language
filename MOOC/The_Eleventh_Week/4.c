/* 
#开头的是编译预处理指令
#define用来定义宏
 */
// const double PI = 3.14159;   //C99的做法
#include <stdio.h>
#define PI 3.14159 //#define <name>  <value>  (没有分号)
#define PI2 2 * PI
#define FORMAT "%f\n"
#define PRT           \
  printf("%f\n", PI); \
  printf("%f\n", PI2)

/* 

定义像函数的宏  ()宏可以带参数 
宏的值必须有括号   每个参数必须要有括号
*/
#define cube(x) (x * x * x)
int main()
{
  // printf(FORMAT, PI);
  // printf(FORMAT, PI2);
  PRT;
  printf("%d\n", cube(5));
  return 0;
}