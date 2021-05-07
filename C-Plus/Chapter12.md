# Chapter12

## 12.1 函数简介

- 数学的函数
  - 一元多项式函数
    - f(x) = x + 3
    - f(4) = 4 + 3 = 7
- 函数的主要概念来自于数学的函数。可以把每个函数想成是一个独立的程序模组（副程序），里面包含了一块程序片段，具有某种设计好特定功能
  - 可想成是另外一段写好的程序码



```c
回传值的数据类型 函数名 (参数的数据类型 参数名,...){
	/*程序码片段*/
	return 回传值;
}
```



使用自定义的函数

```c
#include<stdio.h>

// 函数定义
int f(int x){
	return x + 3;
}

int main() {
    // 函数呼叫
    printf("%d\n",f(4));
	return 0;
}
```























## 12-1 更多关于函数使用的细节

- 在程序码的顺序中，呼叫函数前要宣告或定义函数

```c
#include<stdio.h>
// 呼叫函数在函数定义之前 编译时会有警告或错误
int main() {
    // 函数呼叫
    printf("%d\n",f(4));
	return 0;
}

// 函数定义
int f(int x){
	return x + 3;
}

```

如果要将主函数放在函数之前，可以使用函数宣告

```c
#include<stdio.h>
// 函数宣告
int f(int x);

int main() {
    // 函数呼叫
    printf("%d\n",f(4));
	return 0;
}

// 函数定义
int f(int x){
	return x + 3;
}
```

注意这边强调的是指程序码中的顺序而不是执行的顺序



范例：除以二的函数

```c
#include<stdio.h>
double div2(double x){
    return x / 2;
}


int main() {
	int N;
	scanf("%d",&N);
	printf("%f\n",div2(N));
	return 0;
}

```

主函数在函数之前

```c
#include<stdio.h>
double div2(double);

int main() {
	int N;
	scanf("%d",&N);
	printf("%f\n",div2(N));
	return 0;
}

double div2(double x){
    return x / 2;
}
```



- 函数呼叫执行流程：
  - 计算引数值
    - 将引数值转型到与参数形态相同
  - 执行函数，得到函数回传值 

```c
int foo = 2;
double bar = div2(foo*2); // div2(2*2) -> div2(4)

double div2(double);
double bar = div2(4.0);
```



## 12-2 使用C标准函数库





## 12-3 对两个变量求最大值的练习



```c
#include<stdio.h>
int max2(int,int)

int main(){
	int a,b;
    printf("Please enter the first integer：");
    scanf("%d",&a);
    printf("Please enter the second integer：");
    scanf("%d",&b);
    printf("The maxinum is %d.\n",max2(a,b));
	return 0; 
}

int max2(int a,int b){
    int max;
    if(a > b){
        max = a;
    } else {
        max = b;
    }
    return max;
}
```





```c
#include<stdio.h>
int max2(int,int)

int main(){
	int a,b;
    printf("Please enter the first integer：");
    scanf("%d",&a);
    printf("Please enter the second integer：");
    scanf("%d",&b);
    printf("The maxinum is %d.\n",max2(a,b));
	return 0; 
}

int max2(int a,int b){
    int max;
    if(a > b){
        return a;
    } else {
        return b;
    }
}
```



```c
#include<stdio.h>
int max2(int,int)

int main(){
	int a,b;
    printf("Please enter the first integer：");
    scanf("%d",&a);
    printf("Please enter the second integer：");
    scanf("%d",&b);
    printf("The maxinum is %d.\n",max2(a,b));
	return 0; 
}

// 参数与在主函数内定义的变量没有直接关系 指的不是同一个变量
int max2(int x,int y){
    int max;
    if(x > y){
        return x;
    } else {
        return y;
    }
}
```





## 12-4 关于变量名称可视范围(scope)



变量名称的宣告

- 变量名可以依照宣告的位置分为三种：

  - 全域变量(Global varible)

    - 宣告在函数定义外
    - 因为容易造成名称污染，请避免使用全域变量

  - 区域变量(Local varible)

    - 宣告在函数定义内

  - 函数参数(Formal parameter)

    ```c
    int f(int i){
    	return 0;
    }
    ```

    

变量名称的宣告与区块

(1)

```c
int main(){
	// 在同一区块{}里同名称变量只能有一个
	int i;
	{
		int i;
	}
	return 0;
}
```



(2)

```c
int i;

int main() {
    return 0;
}

int i() {
    return 0;
}

// 同名的全域变量和函数只能有一个
```



(3)

```c
int i;

int main(){
	int i;
	{
		int i;
	}
	return 0;
}

int f(int i) { // 函数参数
	return 0;
}
```



要在程序里使用某个已经宣告的变量名称需要同时满足下列两个条件：

- 在程序中位于该变量名称宣告以后
- 该变量是全域变量 或者 被包含在该变量名称宣告的区块`{}`内



猜值练习

(1)

```c
#include<stdio.h>
int i = 1;

int main(){
	printf("%d",i); // 1
	int i = 2;
	printf("%d",i); // 2
	{
		printf("%d",i); // 2
		int i = 3;
		printf("%d",i); // 3
	}
	printf("%d",i); // 2
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main() {
	int i = 3;
	printf("%d\n",i); // 3
	if(i == 3){
		i = i + 1; // 4
		int i = 6;
		printf("%d\n",i); // 6
		i = i + 1;
	}
	
	if(i == 3){
		printf("%d\n",i); // 3
	}
	return 0;
}
```



(3)

```c
#include<stdio.h>
int i = 5;

int f(){
    i = i + 1;
    printf("%d\n",i); // 6
    return 0;
}

int main() {
    printf("%d\n",i); // 5
	int i = 6;
    i = i + 1;
    f();  // 6
    printf("%d\n",i); // 7
	return 0;
}
```





## 12-5 对三个变量求最大值的练习(使用函数)



(1)

```c
#include<stdio.h>
int max3(int, int, int);

int main(){
	int a,b,c;
    printf("Please enter three integers：");
    scanf("%d %d %d",&a,&b,&c);
    printf("The maxinum is %d.\n",max3(a,b,c));
    return 0;
}

int max3(int a, int b, int c){
	int max = a;
	if(b > max) {
		max = b;
	}
	if(c > max) {
		max = c;
	}
	
}
```





(2)

思路

```c
#include<stdio.h>
int max2(int, int)
int max3(int, int, int);

int main(){
	int a,b,c;
    printf("Please enter three integers：");
    scanf("%d %d %d",&a,&b,&c);
    printf("The maxinum is %d.\n",max3(a,b,c));
    return 0;
}

int max3(int a,int b,int c) {
    return /* 怎么用 max2 得到 max3 的结果 */
}

int max2(int a, int b){
	if(a >= b){
		return a;
	} else {
		return b;
	}	
}
```



范例

```c
#include<stdio.h>
int max2(int, int)
int max3(int, int, int);

int main(){
	int a,b,c;
    printf("Please enter three integers：");
    scanf("%d %d %d",&a,&b,&c);
    printf("The maxinum is %d.\n",max3(a,b,c));
    return 0;
}

int max3(int a,int b,int c) {
    return max2(max2(a,b),c)
}

int max2(int a, int b){
	if(a >= b){
		return a;
	} else {
		return b;
	}	
}
```



解析

```c
#include<stdio.h>
int max2(int, int)
int max3(int, int, int);

int main(){
	int a,b,c;
    printf("Please enter three integers：");
    scanf("%d %d %d",&a,&b,&c);
    printf("The maxinum is %d.\n",max3(3,5,4));
    return 0;
}

int max3(int a = 3,int b = 5,int c = 4) {
    return max2(max2(3,5),c);
           max2(5,c); => (5,4);
    return 5;
    	   
}

int max2(int a, int b){
	if(a >= b){
		return a;
	} else {
		return b;
	}	
}
```





## 12-6 用文字绘制实心三角形(function)

`for`双重循环

```c
#include<stdio.h>
int main(){
	int N;
	printf("F: ");
	scanf("%d",&N);
	
	int i,j;
	for(i = 1;i <= n;++i){
		// print_stars(i)
		for(j = 1;j <= i;++j){
			printf("*");
		}
        printf("\n");
	}
	return 0;
}
```



使用单个函数

```c
#include<stdio.h>
void print_stars(int)

int main(){
	int N;
	printf("F: ");
	scanf("%d",&N);
	
	int i,j;
	for(i = 1;i <= n;++i){
		print_stars(i)		
        printf("\n");
	}
	return 0;
}

void print_stars(int i){
	int j;
	for(j = 1;j <= i;++j){
		printf("*");
	}
}
// void 作为回传值形态时,表示该函数不回传任何值
// 当回传值形态是 void 时， return 可以省略。
```



使用多个函数

```c
#include<stdio.h>
void print_stars(int i);
void print_triangle(int N);

int main(){
	int N;
	printf("F: ");
	scanf("%d",&N);
	print_triangle(N);
	return 0;
}

void print_triangle(int N){
	int i;
	for(i = 1;i <= n;++i){
		print_stars(i)		
        printf("\n");
	}
}


void print_stars(int i){
	int j;
	for(j = 1;j <= i;++j){
		printf("*");
	}
}
```



## 12-7 乱数生成

随机产生整数

- C标准函数库中有一个能随机产生整数的rand函数
  - int rand(void)

范例：随机产生五个乱数

```c
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i;
	for(i = 1; i <= 5; i++){
		printf("%d\n",rand());
	}
	return 0;
}
// 每次呼叫rand函数就会回传一个随机产生的乱数
// 第二次执行结果是固定的
```



- 可以使用`srand`函数指定`rand`函数的乱数种
  - 一个程序只需要呼叫一次
- C标准函数库中有一个能取得系统时间的`time`函数
  - time_t time(time_t* timer);

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(0));
	int i;
	for(i = 1; i <= 5; i++){
		printf("%d\n",rand());
	}
	return 0;
}
```



## 12-8 掷骰子

请模拟投掷五次公正骰子的结果

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 此时会随机产生数字 但数字的范围不是1-6
int main(){
	srand(time(0));
	int i;
	for(i = 1; i <= 5; i++){
		int dice = rand()
		printf("%d\n",dice);
	}
	return 0;
}
```



修改方案

(1)`do-while`

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 此时会随机产生数字 但数字的范围不是1-6
int main(){
	srand(time(0));
	int i;
	for(i = 1; i <= 5; i++){
		int dice;
		do{
			dice = rand()
		}while(dice < 1 || dice > 6);
		printf("%d\n",dice);
	}
	return 0;
}
// 耗时较长
```



(2)

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 此时会随机产生数字 但数字的范围不是1-6
int main(){
	srand(time(0));
	int i;
	for(i = 1; i <= 5; i++){
		// int dice = rand % 7; // 会产生0-6 
        // int dice = rand % 6; // 此时是0-5 
        int dice = rand % 6 + 1;
		printf("%d\n",dice);
	}
	return 0;
}
```



原理：（rand()%6+1）

| rand() | dice |
| ------ | ---- |
| 0      | 1    |
| 1      | 2    |
| 2      | 3    |
| 3      | 4    |
| 4      | 5    |
| 5      | 6    |
| 6      | 1    |
| 7      | 2    |
| 8      | 3    |
| 9      | 4    |
| 10     | 5    |
| 11     | 6    |



猜数字练习

```c
#include<stdio.h>
int main(){
    int answer = 4;
	int guess;
	printf("Please enter your guess： ");
	scanf("%d",&guess);
	while(guess != answer){
		if(guess > answer){
			printf("Too large!\n");
		} else if (guess < answer) {
			printf("Too small!\n");
		}
		printf("Please enter your guess：");
		scanf("%d",&guess);
	}
	printf("Correct!\n");
    return 0;
}
```





```c
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    arand(time(0));
    int answer = rand() % 100;
	int guess;
	printf("Please enter your guess： ");
	scanf("%d",&guess);
	while(guess != answer){
		if(guess > answer){
			printf("Too large!\n");
		} else if (guess < answer) {
			printf("Too small!\n");
		}
		printf("Please enter your guess：");
		scanf("%d",&guess);
	}
	printf("Correct!\n");
    return 0;
}
```



