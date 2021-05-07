# Chapter23

## 23-1 指针对整数的加减运算

### 指针对整数的加减运算

```c
int v[5];
			// 可以通过将数组元素的地址加减一个整数来求得其他元素内存地址
&v[0] + 1 == &v[1]; // 从v[0]位址往前移动一个数组元素后的位址 
&v[1] + 1 == &v[2]; // 从v[1]位址往前移动一个数组元素后的位址
&v[1] - 1 == &v[0]; // 从v[1]位址往回移动一个数组元素后的位址
```



### 指针对指针的加减运算

```c
int v[5];

&v[0] + &v[1] // 编译失败
&v[2] - &v[1] == 1 // 从v[2]位址到v[1]位址距离1个元素
&v[3] - &v[0] == 3 // 从v[3]位址到v[0]位址距离3个元素
```





## 23-2 指针与数组

### 指针与数组的不同

```c
// 宣告定义一个有5个元素的int数组，占据5个int大小的内存
int v[5];

// 宣告定义一个int指针，占据一个int *大小的内存
int *n;
```



### 数组类型可转型为指针

```c
// 宣告定义一个有5个元素的int数组，占据5个int大小的内存
int v[5];

// 宣告定义一个int指针，占据一个int *大小的内存
int *n;

n = &v[0];
		 // 数组类型可以隐性转型成该数组第一个元素内存地址的指标

n = v;   // 相等于 n = &v[0]
```



### 通过指针运算存取数组元素

```c
int v[5];
int *n = v;
n   == &v[0];    *n       == v[0];   // *n = 0 等价于 v[0] = 0
n+1 == &v[0]+1;  *(n+1)   == v[1];   // *(n+1) = 0 等价于 v[1] = 0
n+2 == &v[0]+2;  *(n+2)   == v[2];   // *(n+2) = 0 等价于 v[2] = 0
// v[1]
// v[2]
```





## 23-3 循序存取数组元素(指针)

### 使用数组

```c
#include<stdio.h>
int main() {
	int v[5] = {1, 2, 3, 4, 5};
	int i;
	for(i = 0; i < 5; i++) {
		printf("%d\n",v[i]);
	}
	return 0;
}
```



### 使用指针

```c
#include<stdio.h>
int main() {
	int v[5] = {1, 2, 3, 4, 5};
	int *n = v;
	int i;
	for(i = 0; i < 5; i++) {
		printf("%d\n",*(n+i));
	}
	return 0;
}
```



### 原理

```c
#include<stdio.h>
int main() {
	int v[5] = {1, 2, 3, 4, 5};
	int *n = v;         // n == &v[0]
	printf("%d\n", *n); 
	n = n + 1;		    // n == &v[1]
	printf("%d\n", *n);
	n = n + 1;			// n == &v[2]
	printf("%d\n", *n);
	n = n + 1; 			// n == &v[3]
	printf("%d\n", *n);
	n = n + 1;			// n == &v[4]
	printf("%d\n", *n);
	return 0;
}



#include<stdio.h>
int main() {
	int v[5] = {1, 2, 3, 4, 5};
	int *n = v;         // n == &v[0]
	printf("%d\n", *n++); 
	printf("%d\n", *n++);
	printf("%d\n", *n++);
	printf("%d\n", *n++);
	printf("%d\n", *n++);
	return 0;
}
```



### 实现

```c
#include<stdio.h>
int main() {
	int v[5] = {1, 2, 3, 4, 5};
	int *n;
	for(n = v; n != v+5; n++) {
		printf("%d\n",*n);
	}
	return 0;
}
```



## 23-4 指针与下标运算符([])

### original

```c
int v[5];
int *n = v;
n[0] = 0; // a[b] 就是 *(a+b) , n[0] 就是 *(n+0)
v[0] = 0; // a[b] 就是 *(a+b) , v[0] 就是 *(n+0)
```



### example

```c
int v[5];
int *n = v;
n[0] == *n;        n[0] == *v;
n[1] == *(n+1);	   n[1] == *(v+1);
n[2] == *(n+2);	   n[2] == *(v+2);
```





## 23-5 在函数间传递数组

### example

取数组内最大值的练习

(1) 

```c
#include<stdio.h>
// int[]
int maxv(int[3]);

int main(){
	int a[3] = {3, 9, 7};
	printf("Max：%d\n",maxv(a));
	return 0;
}

// (int *v)
int maxv(int v[3]){
	int max = v[0],i;
	for(i = 1; i < 3; i++){
		if(v[i] > max){
			max = v[i];
		}
	}
	return max;
}
```



(2)

```c
#include<stdio.h>
// int[]
int maxv(int[], int N);

int main(){
	int a[3] = {3, 9, 7};
	printf("Max：%d\n",maxv(a));
	int b[5] = {3, 9, 1, 2, 7};
	printf("Max：%d\n",maxv(b))
	return 0;
}

int maxv(int v[],int N){
	int max = v[0],i;
	for(i = 1; i < N; i++){
		if(v[i] > max){
			max = v[i];
		}
	}
	return max;
}
```



## 23-6 指针与数组的关系

### 总结

- 指针储存某数组元素内存地址时的特殊性
  - 可以通过加减整数算出同阵列其他元素的内存地址
    - 加 N 等同于向后移动 N 个元素后的内存地址
    - 减 N 等同于往回移动 N 个元素后的内存地址
  - a[b]运算等同于*(a+b)，反之亦同
    - 在该数组中从a开始往后移动b所在的数组元素
    - 当指针储存某数组第一个元素的内存地址后，用起来就跟该数组没什么两样
- 数组可以隐性转换为该数组的第一个元素的内存地址



## 23-7 指针与递增递减运算符

### example

数组归零

```c
int main(){
	int v[5];
	int i;
	for(i = 0; i < 5; i++) {
		v[i] = 0;
	}
	return 0;
}
```



使用指针

```c
// 1
int main(){
	int v[5];
	int i;
	int *p = v;
	for(i = 0; i < 5; i++) {
		p[i] = 0;
	}
	return 0;
}

// 2
int main(){
	int v[5];
	int i;
	int *p;
	for(p = v; p != &v[5]; p++) {
		*p = 0;
	}
	return 0;
}

// 3
int main(){
	int v[5];
	int i;
	int *p;
	for(p = v; p != v+5; p++) {
		*p = 0;
	}
	return 0;
}

// 4
int main(){
	int v[5];
	int *p = v;
    while(p != v+5) {
        *p = 0;
        p++;
        // *p++ = 0
        // *(p++) = 0
    }
	return 0;
}
```

