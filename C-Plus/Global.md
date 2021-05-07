# Chapter12(global)

## 12-9 全域(global)变量的特殊性

未定义行为

```c
#include<stdio.h>

int main(){
    // 读取未初始化的区域变量为"未定义行为"
	int i;
	printf("%d\n",i);
	return 0;
}
```



全域(global)变量

```c
#include<stdio.h>

int i;

int main(){
    // 全域变量会自动初始化为0
	printf("%d\n",i); // 0
	return 0;
}
```



函数与全域变量

```c
#include<stdio.h>

int i = 0;

void f(){
    // 全域变量会让函数间的关系变得比较不明确
    i++;
}

int main(){
    f();
	printf("%d\n",i); // 0
	return 0;
}
```



i 是什么时候被初始化的？

- 初始化全域变量（其实在编译时就初始化好了）
- i 在呼叫 main()之前就初始化好了
- 程序从呼叫 main() 开始执行



```c
#include<stdio.h>

int f(){
    return 0;
}

int i = f(); // 编译失败

int main(){
	printf("%d\n",i); // 0
	return 0;
}
```





```c
#include<stdio.h>

// 编译失败
int j = 0;
int i = j;

int main(){
	printf("%d\n",i); // 0
	return 0;
}
```



## 12-10 全域变量与静态(static)区域变量



```c
#include<stdio.h>

// void 表示没有参数
// 每次呼叫都是独立的一份
int count(void) {
	int k = 0;
	k++;
	return k;
}

int main(){
	for(int i = 1; i <= 5; i++){
		printf("%d\n",count());
	}
	return 0;
}
// 1 1 1 1 1
```



在函数定义外宣告定义变量

```c
#include<stdio.h>
int k = 0;
// 每次呼叫都存取同一个全域变量
// 通常会尽量避免使用全域变量
int count(void) {	
	k++;
	return k;
}

int main(){
	for(int i = 1; i <= 5; i++){
		printf("%d\n",count());
	}
	return 0;
}
// 1 2 3 4 5
```



`static` 静态变量

```c
#include<stdio.h>

int count(void) {	
	static int k = 0;
	k++;
	return k;
}

int main(){
	for(int i = 1; i <= 5; i++){
		printf("%d\n",count());
	}
	return 0;
}
// 1 2 3 4 5
```



- 静态(static)的区域变量只会有一份
- 只会初始化一次



## 12-11 整数的溢位

### 溢位的发生

```c
#include<stdio.h>

int main() {
	int a = 1000;
	int b = a * a * a;
	int c = a * a * a * a;
	printf("%d\n",b); // 1000000000
	printf("%d\n",c); // -727379968
	return 0;
}
```

有号整数的溢位是未定义行为（不报错，但结果出乎意料）。



### 如何判断整数溢位？

使用<limits.h>库

```c
#include<stdio.h>
#include<limits.h>

int main(){
	printf("%d\n",INT_MAX);
	printf("%d\n",INT_MIN);
	return 0;
}
// 2147483647
// -2147483648
```

整数形态可表示的范围由《实作定义》



### 无号整数的溢位

```c
#include<stdio.h>
#include<limits.h>

int main(){
	unsigned int a = 1000;
	unsigned int b = a * a * a;
	unsigned int c = a * a * a * a;
	printf("%d\n",b);
	printf("%d\n",c);  // 1000000000000 % (UINT_MAX+1)
    // 余数:0 ~ UINT_MAX
	printf("%d\n",UINT_MAX);
	return 0;
}
// 1000000000
// 3567587328
// 4294967295
```





## 12-12 自行生成伪乱数

### 产生混乱的数列

- 每次将上一个数字乘以5
  - 1,5,25,125,725,3625,..
- 每次将上一个数字乘以5再加3
  - 1,8,43,218,1093,5468...
- 每次将上一个数字乘以5再加3再除以16求余数
  - 1,8,11,10,5,12,15,14,9,0,3,2,13,4,7,6,   1,8.,..

- 循环产生
- 都出现一次



怎么产生（伪）乱数？

- 线性同余法
  - Linear congruential generator
    - x(n+1) = (xn * a + c) % m

x 0 = 1

x n+1 = (x n * 5 + 3) % 16

x n+1 = (x n * 1103515245 + 12345) % 4294967296  乱数种



## 12-13 实作伪乱数生成

线性同余法

```c
#include<stdio.h>

int main(){
	unsigned int next = 1;
	
	for(int i = 1; i <= 5; i++){
		next = next * 1103515245 +12345;
		printf("%u\n",next);
	}
	return 0;
}

// x n+1 = (x n * 1103515245 + 12345) % 4294967296

// 1103527590
// 2524885223
// 662824084
// 3295386429
// 4182499122
```



unsigned int 溢位后等同除以 UINT_MAX + 1 的余数