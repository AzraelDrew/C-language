#include <stdio.h>
int main()
{
//sizeof() 强制类型转换 [0]   ()函数运算符   都是运算符 

/* //算术运算(先 乘除  取余(取模) 后 加 减)
int a = 4 + 5 * 2 - 6 / 3 + 11 % 4;
printf("%d\n", a);
scanf("%d",&a);
// printf("%d\n",a);
while (a)
{
    printf("%d",a%10);
    a = a / 10;
}
printf("\n"); */


/* //关系运算符   > < == >= <= !=  0代表假 非0为真

printf("%d\n",5>3);
printf("%d\n",5<3);
int b = 8;
if (3 < b <10){    //会会先判断b 是否大于3  如果大于为1 否则为0   无论什么情况都是小于10的  都会输出  a is right
    printf("a is right\n");
}
else {
    printf("a is wrong\n");
} */


/* 
int b;
scanf("%d",&b);
if (3 < b && b < 10)
{ //会会先判断b 是否大于3  如果大于为1 否则为0   无论什么情况都是小于10的  都会输出  a is right
    printf("a is right\n");
}
else {
    printf("a is wrong\n");
} */


//判断两个浮点数是否相等
// float f = 234.56;     //在内存中近似存储 真实值并不等于234.56 如234.5589
// if(f==234.56){
//     printf("f is equal to 234.56\n");
// }
// else
// {
//     printf("f is not equal to 234.56\n"); 
// }




/* float f = 234.56;     
// if(f==234.56)
//判断两个浮点数是否相等 必须使用以下方法
if(f-234.56> -0.0001&&f-234.56<0.0001)
{
    printf("f is equal to 234.56\n");
}
else
{
    printf("f is not equal to 234.56\n"); 
} */



/* 
//逻辑运算符 !(非) &&(与) ||(或)   逻辑表达式只有真和假
int i, j = 5;
i = !j;
printf("%d\n", i);   //0
i = !!j;
printf("%d\n",i);  //1  此时不会输出5而是1 */



/* int i = 5;
i = 10 + 3;
//i+3=10   //赋值运算符的左边必须是一个变量 */


// 自增,自减运算符
int j,i = -1;
// i++;  //等价于i=i+1
// j = i++ > -1;      //i=0,j=0  会先判断 i是否大于-1  再执行i=i+1
j = ++i > -1;      //i=0,j=1  会先执行i=i+1 再判断是否大于-1  

printf("i=%d,j=%d\n", i,j);
printf("i的字节数=%lu\n", sizeof(i));   //sizeof(i)  变量的字节数
return 0;
} 