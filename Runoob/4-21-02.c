/* 函数 */
#include <stdio.h>

/* 
    return_type function_name( parameter list )
    {
    body of the function
    }

    return_type:返回值类型  一个函数可以返回一个值。return_type 是函数返回的值的数据类型。
    有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 void。
    parameter list:参数列表
*/

int max(int num1, int num2)
{
    int result;
    if (num1 > num2)
    {
        result = num1;
    }
    else
    {
        result = num2;
    }
    return result;
}

// 传值调用
//该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。
void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("x=%d,y=%d\n", x, y);
    return;
}
// 引用调用
// 通过指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。
void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}
int main()
{
    int ret = max(1, 6);
    printf("最大值为:%d\n", ret);
    int a = 100;
    int b = 200;
    printf("交换前a=%d,b=%d\n", a, b);
    swap(a, b);
    printf("交换后a=%d,b=%d\n", a, b);

    swap2(&a, &b);
    /* 调用函数来交换值
    * &a 表示指向 a 的指针，即变量 a 的地址
    * &b 表示指向 b 的指针，即变量 b 的地址
   */
    printf("交换后a=%d,b=%d\n", a, b);

    // 上面的实例表明了，虽然在函数内改变了 a 和 b 的值，但是实际上 a 和 b 的值没有发生变化。 return 0;
}
