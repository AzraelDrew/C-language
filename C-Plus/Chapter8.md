# Chapter8

## 8- 有条件的重复执行(while)

- while(表示式){程序片段}
  - 当表示式成立时,就执行程序片段

```c
#include<stdio.h>
// 死循环
int main(){
	int count = 0;
	while(count < 3){
		printf("%d\n",count);
	}
	return 0;
}
// 循环打印 0
```

终止循环

```c
#include<stdio.h>

int main(){
	int count = 0;
	while(count < 3){
		printf("%d\n",count);
		count = count + 1;
	}
	return 0;
}
// 0 1 2 
```





## 8-1  猜数字练习

回顾：`if`

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

- 使用`if`，无论猜的结果如何，程序仅会执行一次



`while`

```c
#include<stdio.h>
int main(){
	int answer = 4;
    int guess;  // 未定义行为
    // 重复执行的条件
    while(guess != answer){
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
    }
    return 0;
}
// 无法读取guess的值 程序结果与预期效果不一样
```



- 需要先执行一次，读取一次`guess`的值以继续进行循环

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
    // 重复执行的条件
    while(guess != answer){
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
    }
    return 0;
}
```

- 重复的程序码不是好事



- 从头来过

```c
#include<stdio.h>
int main(){
	int guess;
	// 1 次
	printf("Please enter your guess： ");
	scanf("%d",&guess);
	// N - 1 次 （假设使用者总共猜了N次）
	printf("Too large!\n");
	printf("Too small!\n");
	printf("Please enter your guess：");
	scanf("%d",&guess);
	// 1次
	printf("Correct!\n");
    return 0;
}
```



猜数字`while`

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







## 8-2 数数猜了几次的练习(while)

- 使用者透过输入一个整数，猜测程序所预设的答案。当使用者猜对时显示总共猜了几次

```c
#include<stdio.h>
// 添加变量count 用于记录输入者的猜数次数
int main(){
    int answer = 4;
	int guess;
    int count = 0;
	printf("Please enter your guess： ");
	scanf("%d",&guess);
    count = count + 1;
	while(guess != answer){     
		if(guess > answer){
			printf("Too large!\n");
		} else if (guess < answer) {
			printf("Too small!\n");
		}
		printf("Please enter your guess：");
		scanf("%d",&guess);
        count = count + 1;
	}
	printf("Correct!(%d)\n",count);
    return 0;
}
```



`count`变量的应用

```c
#include<stdio.h>
// 错误写法 一次都不会猜
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
		} else {
			printf("Correct!\n");
		}
	}
	return 0;
}
```

正确写法(使用count变量)

```c
#include<stdio.h>

int main(){
    int answer = 4;
	int guess;
    int count = 0;
	printf("Please enter your guess： ");
	scanf("%d",&guess);
	while(count == 0 || guess != answer){
		if(guess > answer){
			printf("Too large!\n");
		} else if (guess < answer) {
			printf("Too small!\n");
		} 
	}
	printf("Correct!\n");
	return 0;
}
```







## 8-3 求不定个数正整数和的练习(while)

- 使用者连续输入正整数直到输入0时为止，计算出所有输入的正整数和。

```c
#include<stdio.h>

int main(){
    int number,sum=0;
	printf("Please enter the numbers(quit:0): ");
    scanf("%d",&number);
    while(number!=0){
        sum = sum + number;
        scanf("%d",&number);
    }
    printf("The sum is %d\n",sum);
    return 0;
}
```







## 8-4 求不定个数正整数平均的练习(while)

- 使用者连续输入正整数直到输入0为止，计算出所有输入正整数平均(不包括0)。
- 注意不能让零除以任何数

```c
#include<stdio.h>

int main(){
    int number,sum = 0,count = 0;
    float average;
	printf("Please enter the numbers(quit:0):\n");
    scanf("%d",&number);
    if(number == 0){
        printf("The average is N/A\n");
    }
    while(number != 0) {
        sum = sum + number;
        count = count + 1;
    	scanf("%d",&number);      
    }
    average = (float)sum / count;
    printf("The average is %f\n",average);
    return 0;
}
```





## 8-5 数数字练习(while)

打印1到10的连续整数

（1）

```c
#include<stdio.h>

int main(){
	printf("1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n");
	return 0;
}
```

（2）

```c
#include<stdio.h>

int main(){
    printf("%d\n",count); // count = 1
    printf("%d\n",count); // count = 2
    printf("%d\n",count); // count = 3
    printf("%d\n",count); // count = 4
    printf("%d\n",count); // count = 5
    printf("%d\n",count); // count = 6
    printf("%d\n",count); // count = 7
    printf("%d\n",count); // count = 8
    printf("%d\n",count); // count = 9
    printf("%d\n",count); // count = 10
	return 0;
}
```

(3)

```c
#include<stdio.h>

int main(){
	printf("%d\n",count); // count = 1,2,3,4,5,6,7,8,9,10
	...
	return 0;
}
```

使用`while`

```c
#include<stdio.h>

int main(){
	int count = 1;
	while(count <= 10){
		printf("%d\n",count); // count = 1,2,3,4,5,6,7,8,9,10
        count = count + 1;
	}
	return 0;
}
```





1-100

```c
#include<stdio.h>

int main(){
	int count = 1;
	while(count <= 100){
		printf("%d\n",count); // count = 1,2,3,4,5,6,7,8,9,10...,100
        count = count + 1;
	}
	return 0;
}
```



打印 1 - N

```C
#include<stdio.h>

int main(){
	int N;
	printf("Please enter the number: ");
	scanf("%d",&N);
	int count = 1;
	while(count <= N){
		printf("%d\n",count); // count = 1,2,3,4,5,6,7,8,9,10...,N
        count = count + 1;
	}
	return 0;
}
```



打印 10-20

```c
#include<stdio.h>

int main(){
	int count = 10;
	while(count <= 20){
		printf("%d\n",count); 
        count = count + 1;
	}
	return 0;
}
```



打印 M-N

```c
#include<stdio.h>

int main(){
	int M,N;
	printf("Please enter the number M: ");
	scanf("%d",&M);
	printf("Please enter the number N: ");
	scanf("%d",&N);
	int count = M;
	while(count <= N){
		printf("%d\n",count); 
        count = count + 1;
	}
	return 0;
}
```



猜猜会打印出什么？

```c
#include<stdio.h>

int main(){
	int count = 1; // 0
	while(count <= 10){ // < 10
        count = count + 1;
        printf("%d\n",count);  // 2 - 11  // 1-10
	}
	return 0;
}
```





## 8-6 至少做一次的重复执行(do-while)

基本使用

```c
#include<stdio.h>

int main(){
	int count = 3;
	do{
		printf("%d\n",count);
		count++;
	} while (count < 3);
	return 0;
}
```



举例：猜数字

使用者透过输入一个整数，猜测程序所预设的答案。

`if` 无论对错，只能猜一次

```c
#include<stdio.h>

int main(){
    int answer = 4;
    int guess;
    printf("Please enter your guess: ");
    scanf("%d",&guess);
    if(guess > answer){
        printf("Too large!\n");
    } else if(guess < answer){
        printf("Too small!\n");
    } else {
        printf("Correct!\n");
    }
    return 0;
}
```



`while`

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



`do-while`

```c
#include<stdio.h>
int main(){
    int answer = 4;
	int guess;
	printf("Please enter your guess： ");
	scanf("%d",&guess);
	do{
		printf("Please enter your guess： ");
		scanf("%d",&guess);
		if(guess > answer){
			printf("Too large!\n");
		} else if (guess < answer) {
			printf("Too small!\n");
		} else {
            printf("Correct!\n");
        }
	}while(guess != answer);
    return 0;
}
```





## 8-7 复合赋值运算

| 运算符 |   意义   |  范例  |  相等于   |
| :----: | :------: | :----: | :-------: |
|   +=   |  加等于  | a += 2 | a = a + 2 |
|   -=   |  减等于  | a -= 2 | a = a - 2 |
|   *=   |  乘等于  | a *= 2 | a = a * 2 |
|   /=   |  除等于  | a /= 2 | a = a / 2 |
|   %=   | 求余等于 | a %= 2 | a = a % 2 |

示例

```c
// 此二者等价
count = count + 1;
count += 1;
```



递增递减运算

| 运算符 | 意义 | 范例 |  相当于   |
| :----: | :--: | :--: | :-------: |
|   ++   | 递增 | a++  | a = a + 1 |
|   --   | 递减 | a--  | a = a - 1 |

```c
// 此三者等价
count = count + 1;
count += 1;
count++;
count + 1; // count的值不会被改变(赋值)
```

count + 1 与 count++ 有何区别？

- `count + 1` 是由原来的`count`的数值上加1，原来的`count`值是不变的 
- `count++`相当于`count = count + 1`，在对`count`加1的同时，把结果赋值给了`count`
- 假设`count`初始值为0，前者`count`值为0，后者`count`值为1





| 运算符 | 意义 | 范例 |  相当于   |  运算结果  |
| :----: | :--: | :--: | :-------: | :--------: |
|   ++   | 递增 | a++  | a = a + 1 | a原本的值  |
|   ++   | 递增 | ++a  | a = a + 1 | a加1后的值 |
|   --   | 递减 | a--  | a = a - 1 | a原本的值  |
|   --   | 递减 | --a  | a = a - 1 | a减1后的值 |

```c
int a = 0;
int b;
b = ++a;  // a = 1, b = 1
b = a++;  // a = 2, b = 1
a = a++;  // 未定义行为 a = 2 && 3
```



## 8-8 消费金额计算（switch）

试写一程序让使用者分别输入每个商品的编号。输入为0时依照右方的售价表进行结算后，显示卖出的总金额

```c
#include<stdio.h>

int main(){
    int id;
	int total;
    printf("Enter commodity id:");
	do{
       
       scanf("%d",&id);
       switch(id)
    	{
        	case 1:
            	total += 90;
            	break;
        	case 2:
            	total += 75;
            	break;
        	case 3:
            	total += 83;
            	break;
        	case 4:
            	total += 89;
            	break;
        	case 5:
            	total += 71;
            	break;
    	} 
    }while(id != 0);
    printf("Total: %d",total);
	return 0;
}
```



