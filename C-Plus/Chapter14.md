# Chapter14

## 14 数组简介

数组变量

- 数组是一群具有相同数据类型元素集合的数据类型

  - 在记忆体中，一个数组会使用一段连续的记忆体空间来存放

- 数组的变量定义：

  - 元素数据类型 数组变量名[元素个数];（int var[3];）

- 一般与数组变量的差别：

  int var;  =>   var(int) ??

  int var[3];  =>  var[0] (int) ??      var[1] (int) ??      var[2] (int) ??     (int[3])



数组的第一种用途 - 取代多个变量定义

- 数组元素的存取：数组变量名称[元素索引编号];

```c
// 不使用数组
int a = 3;
int b = 5;
int c = 0;
int max = a;
if(b > max){
	max = b;
}
if(c > max){
	max = c;
}
printf("Max: %d\n",max);


// 使用数组
int v[3];
v[0] = 3;
v[1] = 5;
v[2] = 0;
int max = v[0];
if(v[1] > max){
	max = v[1];
}
if(v[2] > max){
	max = v[2];
}
printf("Max: %d\n",max);
```



## 14-1 骰子点数出现次数统计的练习

- 模拟投掷六千次骰子，分别显示点数1到6出现的次数。

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
	int c1=0,c2=0;c3=0;
	int c4=0,c5=0,c6=0;
	int i;
	for(i=1; i<=6000; ++i){
		int dice = rand() % 6 + 1;
		switch(dice){
			case 1: c1++; break;
			case 2: c2++; break;
			case 3: c3++; break;
			case 4: c4++; break;
			case 5: c5++; break;
			case 6: c6++; break;
		}
	}
    printf("1: %d\n",c1);
    printf("2: %d\n",c2);
    printf("3: %d\n",c3);
    printf("4: %d\n",c4);
    printf("5: %d\n",c5);
    printf("6: %d\n",c6);
	return 0;
}
```



## 14-2 骰子点数出现次数统计的练习（数组）

模拟投掷六千次骰子，分别显示点数1到6出现的次数。



数组元素初始化

- 数组在变量定义时具有一个特殊的初始化语法：
  - 元素数据类型 数组变量名称[元素个数] = {第一个元素的值，第二个元素的值，第三个元素的值，...，最后一个元素的值};
    -  int counter[6] = {0,0,0,0,0,0};
  - 初始化时最少需要指定一个值，而未指定的元素会被自动指定为0
    - int counter[6] = {0};
  - 在有初始化时，数组元素个数值可以省略，会以初始化元素个数取代。
    - int counter[] = {0,0,0,0,0,0};



```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
	int counter[6] = {0};
	int i;
	for(i=1; i<=6000; ++i){
		int dice = rand() % 6 + 1;
		switch(dice){
			case 1: counter[0]++; break;
			case 2: counter[1]++; break;
			case 3: counter[2]++; break;
			case 4: counter[3]++; break;
			case 5: counter[4]++; break;
			case 6: counter[5]++; break;
		}
	}
    printf("1: %d\n",counter[0]);
    printf("2: %d\n",counter[1]);
    printf("3: %d\n",counter[2]);
    printf("4: %d\n",counter[3]);
    printf("5: %d\n",counter[4]);
    printf("6: %d\n",counter[5]);
	return 0;
}
```





## 14-3 循序存取数组元素(使用循环)

数组的初始化

数组元素的存取：数组变量名称[元素索引编号]

```c
// 减少变量声明
// 不使用数组
int a = 3;
int b = 5;
int c = 0;
int d = 7;
int max = a;
if(b > max){
	max = b;
}
if(c > max){
	max = c;
}
if(d > max){
	max = d;
}
printf("Max: %d\n",max);


// 使用数组
int v[4] = {3,5,0,7};

int max = v[0];
if(v[1] > max){
	max = v[1];
}
if(v[2] > max){
	max = v[2];
}
if(v[3] > max){
	max = v[3];
}
printf("Max: %d\n",max);
```





```c
// 循序存取
// 使用数组
int v[3] = {3,5,0};
int i;
int max = v[0];
if(v[i] > max){ // i = 1
	max = v[i];
}
if(v[i] > max){ // i = 2
	max = v[i];
}
printf("Max: %d\n",max);

int v[4] = {3,5,0,7};
int i;
int max = v[0];
for(i=1; i<=3; i++){
    if(v[i] > max){
		max = v[i];
	}
}
printf("Max: %d\n",max);
```



范例：掷骰子

模拟投掷六千次骰子，分别显示点数1到6出现的次数。

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
	int counter[6] = {0};
	int i,j;
	for(i=1; i<=6000; ++i){
		int dice = rand() % 6 + 1;
		for(j=1; j<=6; ++j){
            if(dice==j){
                counter[j-1]++;
            }
        }
	}
    for(j=1; j<=6;++j){
    	printf("%d:%d\n",j,counter[j-1]);
    }
	return 0;
}
```





## 14-4 随机存取阵列元素 

关于`dice` == `j`

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
	int counter[6] = {0};
	int i,j;
	for(i=1; i<=6000; ++i){
		int dice = rand() % 6 + 1;
		// dice == i 只有一次是符合此条件的，所以仅做一次即可
        counter[dice-1]++;
	}
    for(j=1; j<=6;++j){
    	printf("%d:%d\n",j,counter[j-1]);
    }
	return 0;
}
```





消费金额计算

试写一程序让使用者分别输入每个商品的编号。输入为0时依照右方的售价表进行结算后，显示贩卖总金额

```c
// 1
#include<stdio.h>
int main(){
    int prices[5] = {90,75,83,89,71};
    int total = 0,id,i;
	do{ 
       scanf("%d",&id);
       for(i=1; i<=5; i++){
       		if(id==i){
       			total += price[i-1];
       		}
       }
    } while (id != 0);
    printf("Total: %d\n",total);
	return 0;
}

// 2
#include<stdio.h>
int main(){
    int prices[5] = {90,75,83,89,71};
    int total = 0,id;
	do{ 
       scanf("%d",&id);
       if(id==0){
           break;
       }
       total += prices[id-1];
    } while (id != 0);
    printf("Total: %d\n",total);
	return 0;
}

// 3
#include<stdio.h>
int main(){
    int prices[] = {90,75,83,89,71,45};
    int total = 0,id;
	while (1) { 
       scanf("%d",&id);
       if(id==0){
           break;
       }
       total += prices[id-1];
    };
    printf("Total: %d\n",total);
	return 0;
}
```





## 14-5 两颗骰子点数和出现次数统计的练习(使用数组)

模拟掷 100000 次骰子，每次掷两颗，统计各种点数和出现的次数。

```c
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
	srand(time(0));
	int counter[11] = {0};
	int i;
	for(i=1;i<=100000;i++){
		int dice1 = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;
		int sum = dice1 + dice2;
		counter[sum-2]++;
	}
	for(i=2; i<=12; i++){
		printf("%d:%d\n",i,counter[i-2]);
	}
	return 0;
}

```

