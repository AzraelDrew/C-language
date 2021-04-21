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
    printf("b的准确值是%d\n", b);
    printf("c的值准确是%d\n", c);
    printf("--------------------------------------------------------------------------\n");

    // switch 语句

    /*
         switch(expression){
    case constant-expression  :
       statement(s);
       break; //可选的
    case constant-expression  :
       statement(s);
       break; //可选的
  
    您可以有任意数量的 case 语句
    default : //可选的
       statement(s);
    } 
    */

    char grade = 'B';
    switch (grade)
    {
    case 'A':
        printf("很棒\n");
        break;
    case 'B':
    case 'C':
        printf("做得好\n");
        break;
    case 'D':
        printf("您通过了\n");
        break;
    case 'F':
        printf("最好再试一下\n");
        break;
    default:
        printf("无效的成绩\n");
    }
    printf("您的成绩是%c\n", grade);

    printf("--------------------------------------------------------------------------\n");

    // 嵌套 switch 语句

    /* 
        switch (ch1)
    {
    case 'A':
        printf("这个 A 是外部 switch 的一部分");
        switch (ch2)
        {
        case 'A':
            printf("这个 A 是内部 switch 的一部分");
            break;
        case 'B': //内部 B case 代码
        }
        break;
    case 'B': //外部 B case 代码
    }
    */

    switch (b)
    {
    case 100:
        printf("这是外部switch的一部分\n");
        switch (c)
        {
        case 200:
            printf("这是内部switch的一部分\n");
        }
    }

    printf("b的准确值是%d\n", b);
    printf("c的准确值是%d\n", c);

    printf("--------------------------------------------------------------------------\n");

    // 三元运算符

    int num;
    printf("请输入一个数字：");
    scanf("%d", &num);
    (num % 2 == 0) ? printf("偶数\n") : printf("奇数\n");
    return 0;
}