# Chapter7

## 7-二选一的交叉路口

(1)使用`if`

```c
#include<stdio.h>
int main(){
	*int grade;
    printf("Please enter the grade:");
    scanf("%d",&grade);
    if(grade >= 60){
        printf("PASS");
    } 
    if(grade < 60){
        printf("FAIL");
    }
	return 0;
}
```

- 做两次判断
- 不一定会被执行

(2)使用`if-else`

```c
#include<stdio.h>
int main(){
	int grade;
    printf("Please enter the grade:");
    scanf("%d",&grade);
    if(grade >= 60){
        printf("PASS");
    } else {
        printf("FAIL");
    }
	return 0;
}
```

- 两个片段会有一个被执行
- 一定会有一个被执行



## 7-1 两个变量比大小的练习

使用`if`

```c
#include<stdio.h>
int main(){
	int a,b;
	printf("Please enter a and b: ");
	scanf("%d %d",&a,&b);
	if(a > b){
		printf("a > b\n");
	}
	if(a < b){
		printf("a < b\n");
	}
	if(a == b){
		printf("a = b\n");
	}
	return 0;
}
```



使用`if-else`

```c
#include<stdio.h>
int main(){
	int a,b;
	printf("Please enter a and b: ");
	scanf("%d %d",&a,&b);
	if(a > b){
		printf("a > b\n");
	} else {
        if(a < b){
			printf("a < b\n");
		} else {
			printf("a = b\n");
		}
    }
	
	return 0;
}
```



使用`else if`

```c
#include<stdio.h>
int main(){
	int a,b;
	printf("Please enter a and b: ");
	scanf("%d %d",&a,&b);
	if(a > b){
		printf("a > b\n");
	} else if(a < b) {
        printf("a < b\n");	
    } else {
		printf("a = b\n");
	}
	
	return 0;
}
```



## 7-2 猜数字练习

使用者透过输入一个整数，猜测程序所预设的答案

`if`

```c
#include<stdio.h>
int main(){
	int answer = 4;
    int guess;
    printf("Please enter your guess:");
    scanf("%d",&guess);
    if( guess < answer ){
        printf("Too small!\n");
    }
    if( guess > answer ){
        printf("Too large!\n");
    }
    if( guess == answer ) {
        printf("Correct!\n");
    }
    return 0;
}
```



`if-else`

```c
#include<stdio.h>
int main(){
	int answer = 4;
    int guess;
    printf("Please enter your guess:");
    scanf("%d",&guess);
    if( guess < answer ){
        printf("Too small!\n");
    }
    else if( guess > answer ){
        printf("Too large!\n");
    }
    else {
        printf("Correct!\n");
    }
    return 0;
}
```



## 7-3 简易四则运算练习

使用者输入两个整数以及要做的运算后，输出运算的结果

`if`

```c
#include<stdio.h>

int main(){
    int num1,num2;
    char op;
    float answer;
    scanf("%d%c%d",&num1,&op,&num2);
    if(op == "+"){
        answer = num1 + num2;
    }
    if(op == "-"){
        answer = num1 + num2;
    }
    if(op == "*"){
        answer = num1 * num2;
    }
    if(op == "/"){
        answer = (float)num1 / num2;
    }
     
    printf("ANS: %f\n",answer);
    return 0;
}
```





`else if`与`if-else`

```c
#include<stdio.h>

int main(){
    int num1,num2;
    char op;
    float answer;
    scanf("%d%c%d",&num1,&op,&num2);
    if(op == "+"){
        answer = num1 + num2;
    }
    else if(op == "-"){
        answer = num1 + num2;
    }
    else if(op == "*"){
        answer = num1 * num2;
    }
    else{
        answer = (float)num1 / num2;
    }
     
    printf("ANS: %f\n",answer);
    return 0;
}
```





## 7-4 对多个变量求最值

对两个变量求最大值

`if`(1)

```c
#include<stdio.h>

int main(){
	int a,b,max;
	printf("Please enter two integer: ");
	scanf("%d %d",&a,&b);
	if(a >= b){
		max = a;
	}
	if(a < b){
		max = b;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
	int a,b,max;
	printf("Please enter two integer: ");
	scanf("%d %d",&a,&b);
	max = a;
	if(a < b){
		max = b;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



`if-else`(1)

```c
#include<stdio.h>

int main(){
	int a,b,max;
	printf("Please enter two integer: ");
	scanf("%d %d",&a,&b);
	if(a >= b){
		max = a;
	} else if(a < b) {
		max = b;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
	int a,b,max;
	printf("Please enter two integer: ");
	scanf("%d %d",&a,&b);
	if(a >= b){
		max = a;
	} else {
		max = b;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```





三个变量求最大值 `if`



(1)

```c
#include<stdio.h>

int main(){
	int a,b,c,max;
	printf("Please enter three integers: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a >= b && a >= c){
		max = a;
	} 
    if(b >= a && b >= c){
		max = b;
	}
	if(c >= a && c >= b){
		max = c;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
	int a,b,c,max;
	printf("Please enter three integers: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a >= b && a >= c){
		max = a;
	} 
    if(b > a && b >= c){
		max = b;
	}
	if(c > a && c > b){
		max = c;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



(3)

```c
#include<stdio.h>

int main(){
	int a,b,c,max;
	printf("Please enter three integers: ");
	scanf("%d %d %d",&a,&b,&c);
	max = a;
	if(b > max){
		max = b;
	}
	if(c > max){
		max = c;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



`if-else`

(1)

```c
#include<stdio.h>

int main(){
	int a,b,c,max;
	printf("Please enter three integers: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a >= b && a >= c){
		max = a;
	} else if(b >= a && b >= c) {
		max = b;
	} else if(c >= a && c >= b) {
		max = c;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
	int a,b,c,max;
	printf("Please enter three integers: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a >= b && a >= c){
		max = a;
	} else if(b >= a && b >= c) {
		max = b;
	} else {
		max = c;
	}
	printf("The maxinum is %d.",max);
	return 0;
}
```



## 7-5 多选一的路口(switch)

四则运算`if-else`

```c
#include<stdio.h>

int main(){
    int num1,num2;
    char op;
    float answer;
    scanf("%d%c%d",&num1,&op,&num2);
    if(op == "+"){
        answer = num1 + num2;
    }
    else if(op == "-"){
        answer = num1 + num2;
    }
    else if(op == "*"){
        answer = num1 * num2;
    }
    else{
        answer = (float)num1 / num2;
    }
     
    printf("ANS: %f\n",answer);
    return 0;
}
```



`switch`

```c
#include<stdio.h>

int main(){
    int num1,num2;
    char op;
    float answer;
    scanf("%d%c%d",&num1,&op,&num2);
   	switch(op){
   		case '+':
   			answer = num1 + num2;
   			break;
   		case '-':
   			answer = num1 - num2;
   			break;
   		case '*':
   			answer = num1 * num2;
   			break;
   		case '/':
   			answer = (float)num1 / num2;
   			break;
   	}
     
    printf("ANS: %f\n",answer);
    return 0;
}
```



## 7-6 ID查询练习

`if-else`

```c
#include<stdio.h>

int main(){
    int id;
    printf("ID: ");
    scanf("%d",&id);
    if(id == 2){
    	printf("John\n");
    } else if(id == 13) {
    	printf("Mary\n");
    } else if(id ==16) {
    	printf("Amy\n");
    } else {
    	printf("Not found");
    }
    return 0;
}
```





`switch`

```c
#include<stdio.h>

int main(){
    int id;
    printf("ID: ");
    scanf("%d",&id);
   	switch(id){
   		case 2:
   			printf("John\n");
   			break;
   		case 13:
   			printf("Mary\n");
   			braek;
   		case 16a;
   			printf("Amy\n");
   			break;
   		default:
   			printf("Not found\n");
   	}
    return 0;
}
```



