# Chapter9

## 9 计次型的重复执行(for)

for（初始式 ; 条件式 ; 循环式）{ 程序片段 }

- 执行 初始式 。
- 当 条件式 成立时，执行 程序片段 。否则就结束循环。
- 执行 循环式 后再回到上一步。

基本使用

 打印 1-10

`while`

```c
int count = 1;
while(count <= 10){
	printf("%d\n",count);
	count += 1;
}
```

`for`

```c
int count;
for(count = 1; count <= 10; count = count + 1){
	printf("%d\n",count);
}
```



## 9-1 数数字练习

打印 1-100

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1; count <= 100; count++){
		printf("%d\n",count);  
	}
	return 0;
}
```



打印 1-N

```c
#include<stdio.h>

int main(){
    int N;
    printf("Please enter the number: ");
    scanf("%d",&N);
	int count;
	for(count = 1; count <= N; count++){		
        printf("%d\n",count);  
	}
	return 0;
}
```



10 - 20

```c
#include<stdio.h>

int main(){
	int M,N; 
	printf("Please enter the number M: ");
	scanf("%d",&M);
	printf("Please enter the number N: ");
	scanf("%d",&N);
	int count;
	for(count = M; count <= N; count++){
		printf("%d\n",count);  
	}
	return 0;
}
```





## 9-2 数等差数列的练习

打印10-1

`for`

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 10; count >= 1; count--){
		printf("%d\n",count);  // 10 9 8 7 6 5... 
	}
	return 0;
}
```



```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1; count <= 10; count++){
		int number = 11 - count;
		printf("%d\n",number); 
	}
	return 0;
}
```



打印1-10间的奇数

(1)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 10; count += 2){
        printf("%d\n",count); // 1,3,5,7,9
    }
	return 0;
}
```

(2)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 5; count++){
		int number = 2 * count - 1;
        printf("%d\n",number); // 1,3,5,7,9
    }
	return 0;
}
```

(3)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 10; count ++){
        if(count % 2 == 1){
        	printf("%d\n",count); // 1,3,5,7,9
        }
    }
	return 0;
}
```



打印1-10间的偶数

(1)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 2;count <= 10; count += 2){
        printf("%d\n",count); 
    }
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 5; count++){
		int number = 2 * count;
        printf("%d\n",number); 
    }
	return 0;
}
```



(3)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 10; count ++){
        if(count % 2 == 0){
        	printf("%d\n",count); // 2,4,6,8,10
        }
    }
	return 0;
}
```





## 9-3 数特定条件数列的练习

打印 1-10 间不是三的倍数的偶数

(1)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 10; count ++){
        if(count % 2 == 0 && count % 3 != 0){
        	printf("%d\n",count);
        }
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 10; count += 2){
        if(count % 3 != 0){
        	printf("%d\n",count);
        }
	return 0;
}
```



(3)

```c
#include<stdio.h>

int main(){
	int count;
	for(count = 1;count <= 10; count ++){
		int number = 2 * count;
        if(number % 3 != 0){
        	printf("%d\n",number);
        }
	return 0;
}
```





## 9.4 求连续整数和的练习

打印 1 加到 100 的整数和。

```c
#include<stdio.h>

int main(){
	// 1 + 2 + 3 + ... + 100
	int sum = 1;
	int i;
    sum = sum + i; // i = 2
    sum = sum + i; // i = 3
    sum = sum + i; // i = 4
    ...
    sum = sum + i; // i = 100
	printf("%d\n",sum);
	return 0;
}
```

`for`

```c
#include<stdio.h>

int main(){
	// 1 + 2 + 3 + ... + 100
	int sum = 1;
	int i;
    for(i = 2; i <= 100; i++){
    	sum = sum + i;
    }
	printf("%d\n",sum);
	return 0;
}
```





打印 1 加到 N 的整数和。

让使用者输入正整数N后，求1加到N的连续整数和。

```c
#include<stdio.h>

int main(){
	int N;
    printf("N = ");
    scanf("%d",&N);
	int sum = 1;
	int i;
    for(i = 2; i <= N; i++){
    	sum = sum + i;
    }
	printf("%d\n",sum);
	return 0;
}
```



等差数列

```c
#include<stdio.h>

int main(){
	int N;
    printf("N = ");
    scanf("%d",&N);
	int sum = (1 + N) * N / 2;
	printf("%d\n",sum);
	return 0;
}
```





## 9.5 用文字绘制横线的练习(for)

让使用者输入正整数N，绘制该长度的文字横线

```c
#include<stdio.h>

int main(){
	int N;
    printf("N = ");
    scanf("%d",&N);
	if(N == 1){
        printf("*\n");
    }
    if(N == 2){
        printf("**\n");
    }
    if(N == 3){
        printf("* * *\n");
    }
    ...
	return 0;
}
```



`for`

```c
#include<stdio.h>

int main(){
	int N;
    printf("N = ");
    scanf("%d",&N);
	int count;
	for(count = 1; count <= N; count++){
		printf("*");
	}
    printf("\n");
	return 0;
}
```



