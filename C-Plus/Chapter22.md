# Chapter22

## 22-1 指针与函数呼叫

### 函数呼叫的特性

- 在呼叫函数时，作为参数的变量会被复制一份到函数内成为参数。在被呼叫的函数内对参数做任何的变动都不会改变到原本的变量。


```c
#include<stdio.h>
void addone(int n) {
	n = n + 1;
} 

int main(){
	int a = 3;
	addone(a);  // 4
	printf("%d\n",a); // 3
	return 0;
}
```

- 对函数`addone`来说他只是得到一个`int`的复制品，无法知道该整数原本存放的地方或来源



### 函数呼叫时复制内存地址

在呼叫函数时，可以将变量的 内存地址 作为参数传入函数执行。此时在函数内部对该参数通过 间接运算符 赋予新的数值时就可以改变原来的变量值。

```c
#include<stdio.h>

void addone(int *n) {
	// 
    *n = *n + 1;   
    // a = a + 1;
}

int main() {
	int a = 3;
	addone(&a); // 复制a的内存地址给addone
	printf("%d\n",a);
	return 0;
	
}
```





## 22-2 两个变量的数值交换(function)

试着写一个swap，将输入的两个整数变量的值交换

```c
#include<stdio.h>
void swap(int,int);

int main(){
    int a = 3,b = 5;
    swap(a,b);
    printf("a：%d\n",a); // 3
    printf("b：%d\n",b); // 5
    return 0;
}

void swap(int a,int b){
    int t = a;
    a = b;
    b = t;
}
```

执行此程序并不会使数值进行交换

- 函数的特性：在呼叫函数时，作为参数的变量会被复制一份到函数内成为参数。在被呼叫的函数内对参数做任何的变动都不会改变到原本的变量。
- 此时要使用变量的内存地址使得 a 和 b 的值发生变化

```c
#include<stdio.h>
void swap(int *,int *);

int main(){
    int a = 3,b = 5;
    swap(&a,&b);
    printf("a：%d\n",a); // 3
    printf("b：%d\n",b); // 5
    return 0;
}

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
```





## 22-3 两个变量的排序(function)

试写一函数sort，将输入的两个整数变量依值排序

### 不使用函数

```c
#include<stdio.h>

int main(){
	int a = 5,b = 3;
	if(a > b) {
		int t = a;
		a = b;
		b = t;
	}
	printf("a：%d\n",a);
	printf("b：%d\n",b); 
	return 0;
}
```



### 使用函数

```c
#include<stdio.h>
void swap(int *,int *);
void sort(int *,int *);

int main(){
    int a = 5,b = 3;
    sort(&a,&b);
    printf("a：%d\n",a); // 3
    printf("b：%d\n",b); // 5
    return 0;
}

void sort(int *a,int *b){
    if(*a > *b){
       swap(&*a,&*b);
    }
}

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
```





## 22-4 该传变量还是地址

### 两个数的最大值

```c
#include<stdio.h>
int max2(int *, int *);

int main(){
	int a = 3,b = 5;
	printf("Max：%d\n",max2(&a,&b));
	return 0;
}

int max2(int *a, int *b){
	if(*a > *b) {
		return *a;
	} else {
		return *b;
	}
}

```



注：常数不能取址 `&4` 会导致编译失败。



### 该传变量值还是址

- 基本原则：
  - 可以传值就传值
    - 复制一份比较安全，不怕被偷改，确保函数间干净的关系。
    - 用起来比较方便，可以传一般的常数
- 额外规则：
  - 作为参数的变量在呼叫函数后值会变动的时候（例如数值交换的范例）
  - 无法直接复制值的时候（例如数组和字符串）
  - 复制的成本太高的时候（例如较复杂的结构）





