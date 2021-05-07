# Chapter1

## 1 - Hello World

```c
#include<stdio.h>

void main(){
	printf("Hello World!");
}
```



## 1-1  字符跳脱

```c
#include<stdio.h>

void main(){
	printf("Hello World!"); // Hello World!
    printf("Hello\n"); 
    printf("world!"); 
    // Hello
    // world!
    
    printf("Hello \"C\" world!");  // Hello "C" world!
    
    printf("Hello\\nworld!");  // Hello\nworld!
}
```



## 1-2 简单的文字图形练习

打印HA(1)

```c
#include<stdio.h>

int main(){
	printf("H     H     A\n");
	printf("H     H    A A\n");
	printf("HHHHHHH   A    A\n");
	printf("H     H   AAAAAAA\n");
	printf("H     H   A     A\n");
    return 0;
}
```

(2)

```c
#include<stdio.h>

int main(){
	printf("H     H     A\nH     H    A A\nHHHHHHH   AA\nH     H   AAAAAAA\nH     H   A     A\n");
    return 0;
}
```

(3)

```c
#include<stdio.h>

int main(){
	printf("H     H       A\n"
	       "H     H      A A\n"
		   "HHHHHHH     A   A\n"
		   "H     H    AAAAAAA\n"
		   "H     H   A       A\n");
    return 0;
}
```





## 1-3 求两个数字和的练习



```c
#include<stdio.h>
// 两数之和
int main(){
    int integer1;
    int integer2;
    int sum;
    printf("Please enter the first integer: ");
    scanf("%d",&integer1);
    printf("Please enter the second integer: ");
    scanf("%d",&integer2);
    sum = integer1 + integer2;
    printf("Sum is %d.\n",sum);
    return 0;
}
```





## 1-4 求三个数字和练习

1 使用多个变量

```c
#include<stdio.h>
// 三数之和
int main(){
    int integer1,integer2,integer3,sum;
    printf("Please enter the first integer: ");
    scanf("%d",&integer1);
    printf("Please enter the second integer: ");
    scanf("%d",&integer2);
    printf("Please enter the third integer: ");
    scanf("%d",&integer3);
    sum = integer1 + integer2 + integer3;
    printf("Sum is %d.\n",sum);
    return 0;
}
```

2 单个变量

```c
#include<stdio.h>
int main(){
    int integer,sum;
    printf("Please enter the first integer: ");
    scanf("%d",&integer);
    sum = integer;
    printf("Please enter the second integer: ");
    scanf("%d",&integer);
    sum = sum + integer;
    printf("Please enter the third integer: ");
    scanf("%d",&integer);
    sum = sum + integer;
    printf("Sum is %d.\n",sum);
    return 0;
}
```



## 1-5 数值交换

使用中间变量

```c
#include<stdio.h>
int main(){
    int integer1,integer2,temp;
    printf("Please enter the first integer: ");
    scanf("%d",&integer1);
    printf("Please enter the second integer: ");
    scanf("%d",&integer2);
    temp = integer1; 
    integer1 = integer2; 
    integer2 = temp;
    printf("integer1:%d\n",integer1);
    printf("integer2:%d\n",integer2);
    return 0;
}
```

使用加减法

```c
#include<stdio.h>
int main(){
    int integer1,integer2;
    printf("Please enter the first integer: ");
    scanf("%d",&integer1);
    printf("Please enter the second integer: ");
    scanf("%d",&integer2);
    // 1: 5  2:8
    integer1 = integer1 + integer2;  // 13 8  ^
    integer2 = integer1 - integer2; // 5 13  ^
    integer1 = integer1 - integer2; // 8 5  ^

    printf("integer1:%d\n",integer1);
    printf("integer2:%d\n",integer2);
    return 0;
}
```

