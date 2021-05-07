# Chapter10

## 10-1 找出所有正因数的练习(for)

- 让使用者输入正整数N，找出N的所有正因数（由小到大打印）

  - N的因数：可以整除N的整数（整除：余数为零）
  - N的正因数：可以整除N的正整数
  - 例如：
    - 8的正因数：1,2,4,8
    - 9的正因数：1,3,9
    - 10的正因数：1,2,5,10
    - 11的正因数：1,11(质数)

- N的正因数

  - 可能的候选者：一定是正整数且不大于N

  - 合格条件：要能整除N

    ```c
    for (number = 1; number <= N; number++) {  // 列出可能的候选者
        if(N % number == 0){  // 检查合格条件
            printf("%d ",number);
        }
    }
    ```

    



```c
#include<stdio.h>

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
	int number;
	for(number = 1; number <= N; number++){
		if(N % number == 0){
			printf("%d ",number);
		}
	}
	printf("\n");
	return 0;
}
```





## 10-2 韩信点兵

今有物，不知其数，三三数之余二，五五数之余三，七七数之余二。问物几何？《孙子算经》

- 合格条件：

  ```c
  number%3 == 2 && number%5 == 3 && number%7 == 2
  ```

  

- 可能的候选者：正整数（无穷个）

`while`

```c
#include<stdio.h>
int main(){
    int number;
    // number%3 != 2 || number%5 != 3 || number%7 != 2
    while(!(number%3 == 2 && number%5 == 3 && number%7 == 2)){
        ++number;
    }
    printf("%d\n",number);
    return 0;
}
```



`for`

```c
#include<stdio.h>
int main(){
    int number;
    for(number = 1;
    !(number%3 == 2 && number%5 == 3 && number%7 == 2);
    ++number){
    
    }
    printf("%d\n",number);
    return 0;
}
```



## 10-3  有范围的韩信点兵

有上限的韩信点兵练习

- 让使用者输入搜寻上限，找出上限内所有韩信点兵问题的答案

```c
#include<stdio.h>

int main(){
    int max;
    printf("MAX = ");
    scanf("%d",&max);
    int number;
    for(number = 1;number <= max; ++number){
      	if(number%3 == 2 && number%5 == 3 && number%7 == 2){
             printf("%d\n",number);
        }  
    }
    printf("\n");
    return 0;
}
```





有范围的韩信点兵练习

- 让使用者输入搜寻上下限，找出上下限内所有韩信点兵问题的答案

```c
#include<stdio.h>

int main(){
    int max,min;
    printf("MIN = ");
    scanf("%d",&min);
    printf("MAX = ");
    scanf("%d",&max);
    
    int number;
    for(number = min;number <= max; ++number){
      	if(number%3 == 2 && number%5 == 3 && number%7 == 2){
             printf("%d\n",number);
        }  
    }
    printf("\n");
    return 0;
}
```



韩信点兵由大印到小

- 让使用者输入搜寻上下限，找出上下限内所有韩信点兵问题的答案(由大至小印出)

```c
#include<stdio.h>

int main(){
    int max,min;
    printf("MIN = ");
    scanf("%d",&min);
    printf("MAX = ");
    scanf("%d",&max);
    
    int number;
    for(number = max;number >= min; --number){
      	if(number%3 == 2 && number%5 == 3 && number%7 == 2){
             printf("%d\n",number);
        }  
    }
    printf("\n");
    return 0;
}
```



## 10-4 韩信点兵中的最值问题

- 让使用者输入搜寻上限，找出上限内所有韩信点兵问题答案中最大的

`while`

```c
#include<stdio.h>

int main(){
    int max;
    printf("MAX = ");
    scanf("%d",&max);
    
    int number = max;
    while(!(number%3 == 2 && number%5 == 3 && number%7 == 2)){
    	--number;
    }
    // 未定义行为
    printf("%d\n",number);
    return 0;
}
```



修改

```c
#include<stdio.h>

int main(){
    int max;
    printf("MAX = ");
    scanf("%d",&max);
    
    int number = max;
    while(number > 0 && !(number%3 == 2 && number%5 == 3 && number%7 == 2)){
    	--number;
    }
    if(number > 0){
    	printf("%d\n",number);
    }
    return 0;
}
// 500 - 43
```



`for`

```c
#include<stdio.h>

int main(){
    int max;
    printf("MAX = ");
    scanf("%d",&max);
    
    int answer = 0;
    int number;
    for(number = 1; number <= max; ++number){
    	if(number%3 == 2 && number%5 == 3 && number%7 == 2) {
    		answer = number;
    	}
    }
    if(answer != 0){
    	printf("%d\n",answer);
    }
    return 0;
}
// answer存放目前最新找到的
// 1-500
```



## 10-5 中止重复执行(break&continue)

韩信点兵最大值问题(从大到小执行)

```c
#include<stdio.h>

int main(){
    int max;
    printf("MAX = ");
    scanf("%d",&max);
    
    int answer = 0;
    int number;
    for(number = max; number >= 1; --number){
    	if(number%3 == 2 && number%5 == 3 && number%7 == 2) {
    		answer = number;
    	}
    }
    if(answer != 0){
    	printf("%d\n",answer);
    }
    return 0;
}
```





`break`

- 中断目前所属的重复执行述句

  ```c
  int num;
  for(num = 1; num <= 10; ++num){
  	if(num == 5){
  	   // 当num为5时，程序停止循环，执行return述句
  		break; // 1 2 3 4
  	}
  	printf("%d\n",number);
  }
  return 0;
  ```

  



```c
#include<stdio.h>

int main(){
    int max;
    printf("MAX = ");
    scanf("%d",&max);
    
    int answer = 0;
    int number;
    for(number = max; number >= 1; --number){
    	if(number%3 == 2 && number%5 == 3 && number%7 == 2) {
    		break;  // 符合条件 循环被终止
    	}
    }
    if(answer != 0){
    	printf("%d\n",answer);
    }
    return 0;
}
```





`continue`

- 在重复执行述句中跳过后面的程序区块

```c
int num;
for(num = 1; num <= 10; ++num){
	if(num == 5){
	   break;  // 1 2 3 4 6 7 8 9 10 
	}
	printf("%d\n",number);
}
return 0;
```



## 10-6 有次数的韩信点兵(for)

打印前三小的数（1-1000）

```c
#include<stdio.h>

int main(){
    int count = 0;
    int number;
    // 限制count次数 找到前3个就停止循环
    for (number = 1;number <= 1000 && count < 3; ++number){
    	if(number%3==2 && number%5==3 && number%7==2){
            ++count;
    		if(count <= 3){
                printf("%d ",number);
            }
    	}
    }
    printf("\n");
    return 0;
}
```



打印前三大的数（1-1000）

```c
#include<stdio.h>

int main(){
    int count = 0;
    int number;
    // 限制count次数 找到前3个就停止循环
    for (number = 1000;number >= 1 && count < 3; --number){
    	if(number%3==2 && number%5==3 && number%7==2){
            ++count;
    		if(count <= 3){
                printf("%d ",number);
            }
    	}
    }
    printf("\n");
    return 0;
}
```



打印第三小的数（1-1000）

```c
#include<stdio.h>

int main(){
    int count = 0;
    int number;
    // 限制count次数 找到前3个就停止循环
    for (number = 1;number <= 1000 && count < 3; ++number){
    	if(number%3==2 && number%5==3 && number%7==2){
            ++count;
    		if(count == 3){
                printf("%d ",number);
            }
    	}
    }
    printf("\n");
    return 0;
}
```





## 10-7 质数判断

- 除了1与本身以外没有其他正因数的正整数
  - 不包括1
  - 例如:
    - 2,3,5,7,11,13,17,19,23,...
- 质数有无穷个
- 现代几个密码系统的基础之一
  - 无法非常有效率地进行因数分解

质数判断练习

(1)

```c
#include<stdio.h>

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
    
    int numberOfDivisors = 0;
    int number;
    for(number = 2; number < N; ++number){
    	if(N % number == 0){
    		// 找到其他因数
            ++numberOfDivisors;
    	}
    }
    // 是质数
    if(numberOfDivisors == 0) {
    	printf("Yes\n");
    } else {
    	printf("No\n");
    }
	return 0;
}
```





(2)

```c
#include<stdio.h>

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
    
    int isPrime = 1;
    int number;
    // isPrime 提前结束循环
    for(number = 2; number < N || isPrime; ++number){
    	if(N % number == 0){
    		// 找到其他因数
            isPrime = 0;
    	}
    }
    // 是质数
    if(isPrime) {
    	printf("Yes\n");
    } else {
    	printf("No\n");
    }
	return 0;
}
```



(3)

```c
#include<stdio.h>

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
    
    int number;
    for(number = 2; number < N && N % number != 0; ++number);
    	
    if(number == N) {
    	printf("Yes\n");
    } else {
    	printf("No\n");
    }
	return 0;
}
```





打印1-N范围的质数

```c
    int N;
    printf("N = ");
    scanf("%d",&N);

    int i,j;
    for(i=2;i<N;i++){
        int isPrime = 1;
       	for(j=2;j<i;j++){
            if(i%j==0){
               isPrime = 0;
               break;
            }
     }
      if(isPrime == 1){
            printf("%d ",i);
      }
```



