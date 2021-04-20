/* 判断 */
#include <stdio.h>
int main()
{

    /* 
    if(布尔值){
        布尔值为true会执行的语句
    }
    */

    /* 局部变量定义 */
    int a = 10;
    /* 使用if条件语句检查布尔条件 */
    if (a < 20)
    {
        /* 如果条件为true则执行下面的语句 */
        printf("a小于20\n");
    }
    printf("a的值是%d\n", a);
    printf("--------------------------------------------------------------------------\n");
    /* 
    if(布尔值)
    {
        布尔值为true会执行的语句
    }
    else
    {
        布尔值为false会执行的语句
    }
     */

    int b = 100;
    if (b < 20)
    {
        printf("b小于20\n");
    }
    else
    {
        printf("b大于20\n");
    }
    printf("--------------------------------------------------------------------------\n");

    /*     
    if(boolean_expression 1)
    {
    当布尔表达式 1 为真时执行 
    }
    else if( boolean_expression 2)
    {
    当布尔表达式 2 为真时执行
    }
    else if( boolean_expression 3)
    {
    当布尔表达式 3 为真时执行
    }
    else 
    {
    当上面条件都不为真时执行
    } 
    */

    if (b == 100)
    {
        printf("b的值是10\n");
    }
    else if (a == 20)
    {
        printf("b的值是20\n");
    }
    else if (a == 30)
    {
        printf("b的值是30\n");
    }
    else
    {
        printf("没有匹配的值\n");
    }
    printf("b的准确值是%d\n", b);
    printf("--------------------------------------------------------------------------\n");
    /*     
    if (boolean_expression 1)
    {
        当布尔表达式 1 为真时执行
        if (boolean_expression 2)
        {
            当布尔表达式 2 为真时执行
        }
    } 
    */

    int c = 200;
    if (b == 100)
    {
        if (c = 200)
        {
            printf("b的值是100，且c的值是200\n");
        }
    }
    return 0;
}