/* 定义常量 */
/* 
在 C 中，有两种简单的定义常量的方式：
使用 #define 预处理器。
使用 const 关键字 
*/

/* 
下面是使用 #define 预处理器定义常量的形式：

#define identifier value 

您可以使用 const 前缀声明指定类型的常量，如下所示：

const type variable = value;
*/
#include <stdio.h>
#define LENGTH 10;
#define WIDTH 5;
#define NEWLINE '\n';

const int X = 10;
const int Y = 5;
const char Z = '\n';
int main()
{
    int area1;
    int area2;
    area1 = LENGTH + WIDTH;
    area2 = X * Y;
    printf("value of area:%d\n", area1);
    printf("value of area:%d\n%C", area2, Z);
    return 0;
}