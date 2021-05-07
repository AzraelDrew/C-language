# Chapter4

## 4 流程控制

- 无条件的执行一次(一般述句)
- 有条件的执行一次(if)
- 无条件的重复执行(无穷循环)
- 有条件的重复执行(while)
- 记录次数型重复执行(for)
- 选择性的执行一次(switch)
- 至少执行一次下有条件的重复执行(do-while)

使用频率: if > for > while > switch > do-while



## 4-1 有条件的执行

基本使用

```c
#include<stdio.h>
int main(){
    int a = 5;
    if( a > 4){
        printf("a is larger than 4.\n ");
    }
    return 0;
}
```



自定义数字

```c
#include<stdio.h>
int main(){
    int a;
    printf("a = ");
    scanf("%d",&a);
    if( a > 4){
        printf("a is larger than 4.\n ");
    }
    return 0;
}
```





## 4-2 猜数字

比较大小

```c
#include<stdio.h>
int main(){
    int a = 4;
    if( a > 4 ){
        printf("a is larger than 4.\n ");
    }
    if( a < 4 ){
        printf("a is smaller than 4.\n ");
    }
    if( a == 4 ){
    	printf("a is equal to 4.\n");
    }
    return 0;
    // 注意 '=' 做赋值 '=='做判断
}
```



猜数字

```c
#include<stdio.h>

int main(){
    int answer = 4;
    int guess;
    printf("Please enter your guess:  ");
    scanf("%d",&guess);
    if(guess > answer){
        printf("Too large!\n");
    }
    if(guess < answer){
        printf("Too small!\n");
    }
    if(guess == answer){
        printf("Correct!\n");
    }
    return 0;
}
```





## 4-3 满额折扣计算

题目：某吃到饱餐厅的套餐1人300元（无额外费用）。今日因周年庆特价方案，每桌消费满3000元就打八折。试写一程式让服务生输入一桌的消费人数后，输出该桌顾客应付的总额。

（1）

```c
#include<stdio.h>
int main(){
	int number,total;
    printf("Please enter the number of customers: ");
    scanf("%d",&number);
    if(300 * number < 3000){
    	total = 300 * number;
    }
    if(300 * number >= 3000){
    	total = 300 * number * 0.8;
    }
    
    printf("Total: %d\n", total);
    return 0;
}
```

（2）

```c
#include<stdio.h>
int main(){
	int number,total,original;
    printf("Please enter the number of customers: ");
    scanf("%d",&number);
    original = 300 * number;
    if(original < 3000){
    	total = 300 * number;
    }
    if(original >= 3000){
    	total = 300 * number * 0.8;
    }
    printf("Total: %d\n", total);
    return 0;
}
```



## 4-4 正三角形判断练习



```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    if(side1 == side2 && side1 == side3){
        if(side2 == side3){
            printf("Regular triangle.");
        }
    }
    return 0;
}
```





## 4-5 等腰三角形判断练习

(1)

```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    if(side1 == side2){
        printf("Isosceles triangle");
    }
    if(side1 == side3 && side1 != side2){
        printf("Isosceles triangle");
    }
    return 0;
}
```

(2)

```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    if(side1 == side2 || side1 == side3 || side2 == side3 ){
        printf("Isosceles triangle");
    }
    return 0;
}
```



## 4-6 直角三角形判断练习

（1）

```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    if(side1 * side1 + side2 * side2 == side3 * side3){
        printf("Rectangular triangle\n");
    }
    if(side1 * side1 + side3 * side3 == side2 * side2){
        printf("Rectangular triangle\n");
    }
    return 0;
}
```

（2）

```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    if(side1 * side1 + side2 * side2 == side3 * side3 || 
       side1 * side1 + side3 * side3 == side2 * side2 ||
       side2 * side2 + side3 * side3 == side1 * side1){
        printf("Rectangular triangle\n");
    }
    return 0;
}
```



## 4-7 三角形种类判断类型

输入某三角形的三边长(皆为整数),判断这个三角形是不是下列各种三角形

- 正三角形(Regular triangle)：三边都一样长
- 等腰三角形(Isosceles triangle)：有两边一样长
- 直角三角形(Rectangular triangle)：两边长的平方和等于第三边的平方

```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    // 三角形种类判断
    if(side1 == side2 && side2 == side3){
        printf("Regular triangle.\n");
    }
    if(side1 == side2 || side1 == side3 || side2 == side3){
        printf("Isosceles triangle.\n");
    }
    if(side1 * side1 + side2 * side2 == side3 * side3 || 
       side1 * side1 + side3 * side3 == side2 * side2 ||
       side2 * side2 + side3 * side3 == side1 * side1){
        printf("Rectangular triangle.\n");
    }
    return 0;
}
```

在此程序中，程序的结果与条件的先后顺序没有影响。



## 4-8 三角形种类判断类型的条件简化

> 如果：side1 <= side2 <= side3

```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    
    /* 虽然三个边长不一定按照大小输入，但我们可以透过数值交换的方式，将输入后的三个变长
    由小到大依序存放在 side1, side2, side3 里 */   排序
    
    // 三角形种类判断
    if(side1 == side3){
        printf("Regular triangle.\n");
    }
    if(side1 == side2 || side2 == side3){
        printf("Isosceles triangle.\n");
    }
    if(side1 * side1 + side2 * side2 == side3 * side3){
        printf("Rectangular triangle.\n");
    }
    return 0;
}
```

