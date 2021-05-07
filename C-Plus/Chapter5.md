# Chapter5

## 5.1 对两个变量求最大值(使用if述句)

(1)

```c
#include<stdio.h>
int main(){
    int a,b,max;
    printf("Please enter the first integer:");
    scanf("%d",&a);
    printf("Please enter the second integer:");
    scanf("%d",&b);
    if(a > b){
        max = a;
    }
    if(a < b){
        max = b;
    }
    printf("The maxinum is %d.\n",max);
    return 0;
}
```

(2)

```c
#include<stdio.h>
int main(){
    int a,b,max;
    printf("Please enter the first integer:");
    scanf("%d",&a);
    printf("Please enter the second integer:");
    scanf("%d",&b);
    if(a >= b){
        max = a;
    }
    if(a < b){
        max = b;
    }
    printf("The maxinum is %d.\n",max);
    return 0;
}
```



(3)

```c
#include<stdio.h>
int main(){
    int a,b,max;
    printf("Please enter the first integer:");
    scanf("%d",&a);
    printf("Please enter the second integer:");
    scanf("%d",&b);
    max = a;
    if(a < b){
        max = b;
    }
    printf("The maxinum is %d.\n",max);
    return 0;
}
```





(4)

```c
#include<stdio.h>
int main(){
    int a,b,max;
    printf("Please enter the first integer:");
    scanf("%d",&a);
    printf("Please enter the second integer:");
    scanf("%d",&b);
    if(max < a){
        max = a;
    }
    printf("The maxinum is %d.\n",max);
    return 0;
}
```



## 5-2 对三个变量求最大值的练习

(1)

```c
#include<stdio.h>
int main(){
    int a,b,c,max;
    printf("Please enter the three integers:");
    scanf("%d %d %d",&a,&b,&c);
    if( a >= b && a >= c){
    	max = a;
    }
    if(b > a && b >= c){
    	max = b;
    }
    if(c > a && c > b){
    	max = c;
    }
    printf("The maxinum is %d.\n",max);
    return 0;
}
```



(2)

```c
#include<stdio.h>
int main(){
    int a,b,c,max;
    printf("Please enter the three integers:");
    scanf("%d %d %d",&a,&b,&c);
    max = a;
    if(b > max){
        max = b;
    }
    if(c > max){
        max = c;
    }
    printf("The maxinum is %d.\n",max);
    return 0;
}
```





## 5-3 对四个变量求最大值的练习

(1)

```c
#include<stdio.h>
int main(){
	int a,b,c,d,max;
    printf("Please enter four integers: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a >= b && a >= c && a >= d){
        max = a;
    }
    if(b >= a && b >= c && b >= d){
        max = b;
    }
    if(c >= a && c >= b && c >= d){
        max = c;
    }
    if(d >= a && d >= d && d >= c){
        max = d;
    }
    printf("The maxinum is %d.\n",max);
	return 0;
}
```



(2)

```c
#include<stdio.h>
int main(){
	int a,b,c,d,max;
    printf("Please enter four integers: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a >= b && a >= c && a >= d){
        max = a;
    }
    if(b > a && b >= c && b >= d){
        max = b;
    }
    if(c > a && c > b && c >= d){
        max = c;
    }
    if(d > a && d > d && d > c){
        max = d;
    }
    printf("The maxinum is %d.\n",max);
	return 0;
}
```



(3)

```c
#include<stdio.h>
int main(){
	int a,b,c,d,max;
    printf("Please enter four integers: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    max = a;
    if(b > a && b >= c && b >= d){
        max = b;
    }
    if(c > a && c > b && c >= d){
        max = c;
    }
    if(d > a && d > b && d > c){
        max = d;
    }
    printf("The maxinum is %d.\n",max);
	return 0;
}
```





## 5-4 对多个变量求最小值

对两个变量求最小值

(1)

```c
#include<stdio.h>
int main(){
	int a,b,min;
    printf("Please enter two integers: ");
    scanf("%d %d",&a,&b);
    if(a <= b){
    	min = a;
    }
    if(b < a){
    	min = b;
    }
    printf("The mininum is %d.\n",min);
	return 0;
}
```



(2)

```c
#include<stdio.h>
int main(){
	int a,b,min;
    printf("Please enter two integers: ");
    scanf("%d %d",&a,&b);
    min = a;
    if(b < a){
    	min = b; 
    }
    printf("The mininum is %d.\n",min);
	return 0;
}
```



对三个变量求最小值

（1）

```c
#include<stdio.h>
int main(){
	int a,b,c,min;
    printf("Please enter three integers: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a <= b && a <= c){
    	min = a;
    }
    if(b < a && b <= c){
    	min = b;
    }
    if(c < a && c < b){
    	min = c;
    }
    printf("The mininum is %d.\n",min);
	return 0;
}
```



(2)

```c
#include<stdio.h>
int main(){
	int a,b,c,min;
    printf("Please enter three integers: ");
    scanf("%d %d %d",&a,&b,&c);
    min = a;
    if(b < a && b <= c){
    	min = b;
    }
    if(c < a && c < b){
    	min = c;
    }
    printf("The mininum is %d.\n",min);
	return 0;
}
```



(3)

```c
#include<stdio.h>
int main(){
	int a,b,c,min;
    printf("Please enter three integers: ");
    scanf("%d %d %d",&a,&b,&c);
    min = a;
    if(b < min){
    	min = b;
    }
    if(c < min){
    	min = c;
    }
    printf("The mininum is %d.\n",min);
	return 0;
}
```



## 5-5 对三个变量求中位数

求中位数跟最大最小值有什么不一样

- 求三个整数的中位数
  - 求三个整数中第二大的
  - 求三个整数中第二小的
- 到底有多难？
  - 一个问题到底有多难？
  - 哪个问题是比较难的？
  - "复杂度"(complexity)的概念
- 为什么最大最小值好像有比较简单的解法？
  - ​	求三个整数的最大值"相当于"先求两个整数的最大值后再拿来跟第三个整数比大

(1)

```c
#include<stdio.h>
int main(){
	int a,b,c,med;
    printf("Please enter three integers: ");
    scanf("%d %d %d",&a,&b,&c);
    if( b <= a && a <= c || c <= a && a <= b){
    	med = a;
    }
    if( a <= b && b <= c || c <= b && b <= a){
    	med = b;
    }
    if( a <= c && c <=b || b <= c && c <= a){
    	med = c;
    }
    printf("The median is %d.\n",med);
	return 0;
}
```



(2)

```c
#include<stdio.h>
int main(){
	int a,b,c,med;
    printf("Please enter three integers: ");
    scanf("%d %d %d",&a,&b,&c);
    med = a;
    if(a <= b && b <= c || c <= b || b <= a){
    	med = b;
    }
    if(a <= c && c <=b || b <= c || c <= a){
    	med = c;
    }
    printf("The median is %d.\n",med);
	return 0;
}
```

