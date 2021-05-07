# Chapter16



## 16 产生不重复随机数的练习

随机产生一组由10个 1 到 10 之间的数字所组成的序列，序列里不能有重复的数字。



产生10个 1 - 10之间的随机数（重复）

```c
#include<stdio.h>
#include<stdlib.h>

int main() {
	int i,n[10];
	for(i = 1; i <= 10; i++) {
		n[i-1] = rand() % 10 + 1;
		printf("%d ", n[i-1]);
	}
	printf("\n");
	return 0;
}
```



清除重复值

```c
#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, j, isUsed, n[10];
	for(i = 1; i <= 10; i++) {
		do {
			n[i-1] = rand() % 10 + 1;
			isUsed = 0;
			for(j = 1; j < i; j++) {
				// 看看 n[i-1] 有没有出现过...
				if(n[i-1] == n[j-1]){
					// n[i-1] 已经出现过...
					isUsed = 1;	
					break;  
                    // 1 - (i-1)
				}
			}
			// 此时 j 是多少 ?   i
		} while(isUsed == 1);   // n[i-1] 已经出现过 
		printf("%d ", n[i-1]);
	}
	printf("\n");
	return 0;
}
```



```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 每一次出现的是什么数
int main() {
    arand(time(0));
	int i, j, n[10];
	for(i = 1; i <= 10; i++) {
		do {
			n[i-1] = rand() % 10 + 1;
			for(j = 1; j < i; j++) {
				if(n[i-1] == n[j-1]){
					break;  
				}
			}
		} while(j != i);   
		printf("%d ", n[i-1]);
	}
	printf("\n");
	return 0;
}
```





## 16-1 用建表法产生不重复随机数的练习

随机产生一组由10个 1 到 10 之间的数字所组成的序列，序列里不能有重复的数字。

```c
// 重复
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(0));
	int i, n;
	for(i = 1; i <= 10; i++) {
		n = rand() % 10 + 1;
		printf("%d ", n);
	}
	printf("\n");
	return 0;
}
```



使用建表法消除重复 

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 统计数字出现的次数
int main(){
	srand(time(0));
	int i, n,counter[10] = {0};
	for(i = 1; i <= 10; i++) {
		do{
            n = rand() % 10 + 1;
        }while(counter[n-1] != 0);
		printf("%d ", n);
        counter[n-1]++;
	}
	printf("\n");
	return 0;
}
```





## 16-2 用交换法产生不重复随机数的练习

随机产生一组由10个 1 到 10 之间的数字所组成的序列，序列里不能有重复的数字。



```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(0));
	int i, n;
	for(i = 1; i <= 10; i++) {
		n = rand() % 10 + 1;
		printf("%d ", n);
	}
	printf("\n");
	return 0;
}
```





使用交换法消除重复 

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
	int i, n[10];
	for(i = 1; i <= 10; i++) {
		n[i-1] = i;	
	}
    for(i = 1; i <= 10; i++) {     
        // int j = rand() % 10 + 1;
        int j = rand() % (11-i) + i;
        // 将第 i 个与第 j 个交换
        int t = n[i-1];
        n[i-1] = n[j-1];
        n[j-1] = t;
        printf("%d ",n[i-1]);
    }
    printf("\n");
	return 0;
}
```

