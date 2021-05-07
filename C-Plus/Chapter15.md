# Chapter 15

## 15-1 数字查询

让使用者输入5个整数后，可以依照输入的顺序号码查询所输入的整数。(查询顺序号码为0时则结束)

```c
for(i=0; i<5; i++){ //数组索引编号
		printf("%d: ",i+1);
		scanf("%d",&n[i]);
	}
```



```c
#include<stdio.h>

int main(){
	int i,n[5];
 	for(i=1; i<=5; i++) { // 输入顺序编号
     printf("%d: ",i);
	 scanf("%d",&n[i-1]);
 	}
	while(1){
        printf("Q: ");
    	scanf("%d",&i);
        if(i==0){
            break;
        }
    	printf("%d\n",n[i-1]);
    }
	
	return 0;
}
```



## 15-2 查询范围内数字的练习

- 让使用者输入10个整数后，输入要查询的上下界后，显示输入整数中有被包含在上下线内的
  - 输入 0 0 则结束

效果

```c
13 23 78 77 37 30 40 50 83 99
L R: 10 20
Ans:13
L R: 0 0
```



范例

```c
#include<stdio.h>

int main(){
	int i,n[10];
	for(i=1; i<=10; i++){
		scanf("%d",&n[i-1]);
	}
	while(1){
		int l,r;
		printf("L R:");
		scanf("%d %d",&l,&r);
		if(l == 0 && r == 0){
		 	break;
		}
		printf("Ans：");
		for(i=0; i<10; i++){
			if(n[i]>=l && n[i]<=r){
				printf("%d ",n[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
```



## 15-3 查询上限内最大的数字

- 让使用者输入10个整数后，输入要查询的数字后，显示输入的整数中最接近的一个
  - 输入0则结束

效果

```c
13 23 78 77 30 40 50 83 99
Q: 25
23
Q: 33
30
Q: 9
Q: 0
```





范例：

```c
#include<stdio.h>
// 取值本身
int main(){
	int i, n[10], q;
	for (i=1; i<=10; i++){
		scanf("%d",&n[i-1]);
	}
    while(1){
        int max = -1;
		printf("Q: ");
		scanf("%d",&q);
    	if(q==0){
        	break;
    	}
		for(i=0; i<10; i++){
			if(n[i]<=q && n[i]>max){
				max = n[i];
			}
		}
		if(max != -1){
		printf("%d\n",max);
		}
    }
	return 0;
}
```



调整后

```c
#include<stdio.h>
// 存储索引号
int main(){
	int i, n[10], q;
	for (i=1; i<=10; i++){
		scanf("%d",&n[i-1]);
	}
    while(1){
        int max_i = -1;
		printf("Q: ");
		scanf("%d",&q);
    	if(q==0){
        	break;
    	}
		for(i=0; i<10; i++){
			if(n[i] <= q && (max_i == -1 || n[i] > n[max_i])){
				max_i = i;
			}
		}
		if(max_i != -1){
			printf("%d\n",n[max_i]); 
		}
    }
	return 0;
}
```



## 15-4 查询的最接近数字

- 让使用者输入10个整数后，输入要查询的数字后，显示输入的整数中最接近的一个
  - 有两个以上结果时显示比较小的那个
  - 输入0则结束

效果

```c
13 23 78 77 30 40 50 83 99
Q:25
23
Q:34
37
Q:9
13
Q:0
```



范例：

```c
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,n[10];
	// 读入十个整数
	for(i=1; i<=10; i++){
		scanf("%d",&n[i-1]);
	}
	// 进入查询模式
	printf("Q：");
	scanf("%d",&q);
	int nearest_n = n[0];
	// 寻找最接近的数字
	for(i=1; i<10; i++){
		// abs() 取绝对值
		if(abs(q-n[i]) < abs(q-nearest_n) || 
          (abs(q-n[i]) == abs(q-nearest_n) && 
          n[i] < nearest_n)){
			nearest_n = n[i];
		}
	}
	printf("%d\n",nearest_n);
	return 0;
}
```



调整

```c
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,n[10];
	// 读入十个整数
	for(i=1; i<=10; i++){
		scanf("%d",&n[i-1]);
	}
	while(1){
        // 进入查询模式
		printf("Q：");
		scanf("%d",&q);
		int nearest_n = n[0];
		int nearest_d = abs(q-n[0]);
		// 寻找最接近的数字
		for(i=1; i<10; i++){
			int d = abs(q-n[i]);
			// abs() 取绝对值
			if(
            	d < nearest_d || 
          		(d == nearest_d && n[i] < nearest_n)){
					nearest_d = d;
					nearest_n = n[i];
				}
			}
        	printf("%d\n",nearest_n);
    	}
		return 0;
 }
```





## 15-5 画数字统计长条图的练习

让使用者输入10个1-100间的整数后，画出以10分为区间的长条图。

```
13 23 78 77 30 40 50 83 99
10:
20:*
30:*
40:* * *
50:*
60:
70:
80:**
90:*
```





```c
#include<stdio.h>

int main(){
    int i,j,n;
    int b[10] = {0};
    for(i=1; i<=10; i++){
        scanf("%d",&n);
        b[(n-1)/10]++;
    }
    for(i=1; i<=10; i++){
        printf("%d: ",i*10);
        for(j=1; j<=b[i-1]; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
```



## 15-6 求小范围的众数

- 让使用者输入10个 0~9 之间的整数后，输出众数。
  - 当有一样多的有两个以上时，输出最大的。

效果

```
9 7 7 3 3 9 1 2 3 4
Ans:3
```



范例

```c
#include<stdio.h>

int main(){
	int i, n, b[10] = {0};
	for(i=1; i<=10; i++){
		scanf("%d",&n);
		b[n]++;
	}
	int ans = 0;
	for(n=1; n<10; n++){
		if(b[n] >= b[ans]){
			ans = n;
		}
	}
	printf("Ans: %d\n",ans);
	return 0;
}
```



## 15-7 数字统计

- 让使用者输入 10 个后，输出最大与平均值。



(1)

```c
#include<stdio.h>

int main(){
	int i, n, max = 0, avg, sum = 0;
	for(i = 1; i <= 10; i++) {
		scanf("%d",&n);	
		if(n > max){
			max = n;
		}
		sum += n;
	}
	avg = sum / 10;
	printf("Max：%d\n", max);
	printf("Avg：%d\n", avg);
	return 0;
}
```





(2)

```c
#include<stdio.h>

int main(){
	int i, n, max, avg, sum;
	scanf("%d",&n);	
	max = sum = n;
	for(i = 1; i <= 10; i++) {		
		if(n > max){
			max = n;
		}
		sum += n;
	}
	avg = sum / 10;
	printf("Max：%d\n", max);
	printf("Avg：%d\n", avg);
	return 0;
}
```

 



(3)

```
#include<stdio.h>

int main(){
	int i, n, max, avg, sum = 0;
	for(i = 1; i <= 10; i++) {	
    	scanf("%d",&n);	
		if(i == 1 || n > max){
			max = n;
		}
		sum += n;
	}
	avg = sum / 10;
	printf("Max：%d\n", max);
	printf("Avg：%d\n", avg);
	return 0;
}
```



(4) 

```c
#include<stdio.h>

int main(){
	int i, n[10], max, avg;
	for(i = 1; i <= 10; i++) {
		scanf("%d",&n[i-1]);	
	}
    // 最大值
    int max = n[0];
    for(i = 0; i < 10; i++){
        if(n[i] > max) {
			max = n[i];
        }
    }
    // 求和 平均值
    int sum = n[0];
    for(i = 0; i < 10; i++) {
        sum += n[i];
    }
    avg = sum / 10;
	printf("Max：%d\n", max);
	printf("Avg：%d\n", avg);
	return 0;
}
```



(5)用函数将程序进行分解

```c
#include<stdio.h>
int max10(int n[10]);
int avg10(int n[10]);

int main(){
	int i, n[10], max, avg;
	for(i = 1; i <= 10; i++) {
		scanf("%d",&n[i-1]);	
	}
       
	printf("Max：%d\n", max10(n));
	printf("Avg：%d\n", avg10(n));
	return 0;
}

int max10(int n[10]){
	// 最大值
    int max = n[0];
    for(i = 0; i < 10; i++){
        if(n[i] > max) {
			max = n[i];
        }
    }
}

int avg10(int n[10]) {
	// 求平均值
    int sum = n[0];
    for(i = 0; i < 10; i++) {
        sum += n[i];
    }
    avg = sum / 10;
}
```



