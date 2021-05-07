# Chapter13

## 13 函数递归

```c
void f(void);

int main() {
	f();
	return 0;
}

void f(void) {
	f();
}
```



原理

```c
void f(void){         void f(void){
	f();         =>		 	f();         ...
}					   }
```



执行顺序：

- 主函数`main`的 `f()`
- `f()`函数内的自己调用自己 （此时第一个`f()`仍未结束）
- 下一个`f()`函数
- 即主函数的结束需等待第一个被引用的函数结束，第一个被引用的函数需等待第二个函数结束，以此类推





```c
int f(int);

int main() {
	printf("%d\n",f(0));
	return 0;
}

int f(int i){
	return f(i+1);
}
```



```c
int f(int);

int main() {
	printf("%d\n",f(0));
	return 0;
}

int f(int i){  // 0 1 2...
	if(i == 2){
		return i;
	}
	return f(i+1); 1 2 3...
}
// 2
```





## 13-1 数数字(函数)

印出 1 - 3

```c
#include<stdio.h>

int main(){
	int i;
	for(i=1;i<=3;i++){
		printf("%d\n",i);
	}
	return 0;
}
```



递归

```c
#include<stdio.h>
void countTo3(int);


int main(){
	countTo3(1);	
	return 0;
}

void countTo3(int i){
	if(i <= 3){
		printf("%d\n",i);
		countTo3(i+1);
	}
}
```

- 当 i = 4 时，不满足if的判断条件，此时if语句不再执行，将结果return
- 函数值将从后往前推，由于函数内没有回传值(void类函数)，0将作为回传值从`i=4`回传至`i=1`
- 此时结果为 1 2 3



印出 3 - 1

`for`

```c
#include<stdio.h>

int main(){
	int i;
	for(i=3;i>=1;i--){
		printf("%d\n",i);
	}
	return 0;
}
```



递归

```c
#include<stdio.h>
void countTo1(int);


int main(){
	countTo1(3);	
	return 0;
}

void countTo3(int i){
	if(i >= 1){
		printf("%d\n",i);
		countTo3(i-1);
	}
}
```





```c
#include<stdio.h>
void countTo1(int);


int main(){
	countTo1(1);	
	return 0;
}

void countTo3(int i){
	if(i <= 3){
		countTo3(i+1);
		printf("%d\n",i);
	}
}
```





## 13-2 求连续整数和的练习

使用函数

```c
#include<stdio.h>
int sum(int)

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
	printf("%d\n",sum(N));
	return 0;
}

int sum(int N){
	int sum = 0;
	int i;
	for(i = 1; i <= N; i++){
		sum += i;
	}
	return sum;
}

```





递归

```c
#include<stdio.h>
int sum(int)

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
	printf("%d\n",sum(N));
	return 0;
}

int sum(int N){
	if(N==1){
		return 1;
	}
	return sum(N-1) + N;
}
```





## 13-3 求上楼梯的方法数



```c
#include<stdio.h>
    
int S(int);

void main(){
     int N;
     printf(" N = ");
     scanf("%d",&N);
     printf("%d\n",S(N));
 }

int S(int N){
     if(N <= 2){
        return N; // (1<=N<=2)
     }
        return S(N-1) + S(N-2);  // N > 2
}
```





``` c
S(1) = 1
S(2) = 2
S(3) = S(2) + S(1)
S(4) = S(3) + S(2)
S(5) = S(4) + S(3)
```

