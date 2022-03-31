#include <stdio.h>

//全局变量(在函数外定义的变量)
// int i = 10;
// void print(int a){
//     printf("print %d\n", i);
// }
//定义的变量在离自己最近的花括号有效
int f(int n)  // 形参也是局部变量
{

    if(n==1){
        return 1;  //一定写结束条件  且必须在公式之前
    }
    return n*f(n-1);   //公式
}
int step(int n){

    if(n==1|| n==2){
        return n;
    }
    return step(n - 1) + step(n - 2);
}
int main()
{
/*  printf("main %d\n", i);
    // i = 5;
    int i = 5;  //加了int后就是在main中声明一个局部变量
    print(i);
     */
/* 递归  函数自己调用自己 
    第一步写公式  第二步一定要写结束条件
*/

// int n = 5;
// int result = f(5);
// printf("result=%d\n",result);
int n;
scanf("%d",&n);
printf("%d\n", step(n));
return 0;
}