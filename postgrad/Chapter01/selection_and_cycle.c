#include <stdio.h>
int main()
{

    // //if(关系表达式或者逻辑表达式){}
    // if(5>3 && 8<4-!0){
    //     printf("True\n");
    // }
    // else{
    //     printf("False\n");
    // }


    //if与else 可以不断地else if  最后才是else 也可以没有else   有且只有一个语句会执行 
    //if内部还可以嵌套if
    //else 不能单独出现
    //每个if else 最好都加上花括号(避免if else 配对混乱 )
/* 
    int i = 0;
    while (scanf("%d",&i)!=EOF)
    {
        if(i>0)   //若在if后加分号后 if后面花括号中的代码不会经过if判断,即无论真假都会执行花括号中的语句        (C语言以分号结束代码)
        {
        printf("i is bigger than 0\n");
        }
        else
        {
            printf("i is smaller than 0\n");
        }
    } */


/* 
 // while
 // 从1加到100

// terminal卡住只有两种情况  1.卡在scanf(这种情况可以输入内容)  2.死循环(不能输入)
    int i = 1;
    int total = 0;
    while(i<=100)   //while后不能加分号(会进入死循环)
    {
        total = total + i;
        i++;
    }
    printf("total=%d\n",total); */

/*     // for
    // for(表达式1;表达式2;表达式3){}
    //会先执行表达式1(初始化值) 然后执行表达式2(判断是否为真,为真执行循环体中的代码) 然后在执行表达式3  然后会再判断表达式2    循环往复
    int i, total;
    for (i = 1, total = 0; i <= 100;i++)  //在for循环后直接加分号不会导致死循环
    {
        // total = total + i;
        //从1到100奇数的和
        if(i%2==0){
            continue;   //会跳过偶数这轮循环
        }
            total = total + i;
    }
    printf("total=%d\n",total); */

/* //for
    int i, total;
    for (i = 1, total = 0; i <= 100;i++)  //在for循环后直接加分号不会导致死循环
    {
            if(total >2000){
                break;   //会直接跳出整个for循环
            }
            total = total + i;
    }
    printf("total=%d,i=%d\n",total,i); */



/* //翻转整型数

    int a,b,temp;
    while (scanf("%d", &a)!=EOF)
    {
        b = 0;
        temp = a;
        while (a)
        {
            b = b * 10 + a % 10;
            a =a / 10;
        }
            printf("a=%d,b=%d\n",a,b);
            if (temp == b)
            {
            printf("yes\n");
            }
            else
            {
            printf("no\n");
        }
    } */

    int a,b;
    scanf("%d",&a);
    for (b=1;a!=0;a--)
    {
        b = a * b;
    }
    printf("%d\n",b);
    return 0;
}