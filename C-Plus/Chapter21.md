# Chapter21

## 21-1 没有指针的世界

### 没有指针之前不能处理的问题：

- 在被呼叫的函数中修改参数值

  - 函数呼叫时，参数值会复制一份到被呼叫的函数内做为参数使用。在函数内部对参数做任何变动不会改变到原本的参数值

  ```c
  #include<stdio.h>
  
  void addone(int n) {
  	n = n + 1;
  }
  
  int main() {
  	int a = 3;
  	addone(a);  // 复制a的值给addone
  	printf("%d",a); // 3
  	return 0;
  }
  ```

  

- 直接复制数组

  ```c
  // 编译失败
  int main() {
  	int v[5] = {1, 2, 3, 4, 5};
  	int n[5];
  	n = v;
  	return 0;
  }
  ```

  

- 直接复制字符串

  ```c
  // 编译失败
  int main() {
  	char v[6] = 'Hello';
  	char n[6];
  	n = v;
  	return 0;
  }
  ```

  

- 动态改变数组长度

  ```c
  // 编译失败
  int main(){
  	char v[5];
  	char n[10];
  	v = n;
  	return 0;
  }
  ```



在存储资料前需要先配置数组长度，如果一开始不知道资料总共有多少数量时，我们要怎么配置？

- 例如要让使用者输入任意数量的资料并储存起来该怎么做？





- 指针是一种数据类型，用来储存内存地址
  - 一般情况下是不需要指针的
  - 当解决以下问题时，需要用到此指针
    - 在被呼叫的函数中修改参数值
    - 直接复制数组
    - 直接复制字符串
    - 动态改变数组长度



## 21-2 指针变量宣告与取址运算

### 指针变量宣告(type*)

- 指针(pointer)是C语言的主要特性，是一种储存内存地址的数据类型
- 语法：
  - 数据类型 *变量名称
  - 表示变量内存放的是一个存放这种 数据类型 值的 内存地址

### 宣告指针变量与其他变量的差别

- 宣告整数变量：int count; （存int值）
  - (int *) 2293620
- 宣告浮点数变量：double count;
- 宣告指针变量：int *countAddr;  （存存int值的内存地址）
  - (int **)2293624



注意：

- 当数据类型是`int`，那么其内存地址类型是`int`;
- 当数据类型是`double`，那么其内存地址类型是`double`；
- 对于指针变量 `int *countAddr`，可以与`int`类型变量互相转化，而`double`类型则不能；

```c
int count = 9;

int a;
int *b;

a = count;  // (O) (int)   = (int)
b = count;  // (X) (int *) = (int)

a = &count; // (X) (int)   = (int *)
b = &count; // (O) (int *) = (int *)
```



### 取址运算符(&)

- 变量依照数据类型会占据一定的内存空间。我们可以利用取址运算符(&)去取变量开头的内存地址

```c
int count = 9;
int *countAddr = &count;
```

- count (int) 
  - count:9
  - address:2293620
- countAddr (int *) 
  - count:2293620
  - address:2293624



|  表示式   | 数据类型 |   值    |
| :-------: | :------: | :-----: |
|   count   |   int    |    9    |
|  &count   |  int *   | 2293620 |
| countAddr |  int *   | 2293620 |



## 21-3 指针间接运算

### 间接运算符(*)

- 相对地，我们可以利用间接运算符(*)从内存地址取得开头位于该地址的变量(不要跟宣告指针变量时用的 * 搞混)

```c
int count = 9;
int *countAddr = &count;
*countAddr;
```

- count (int) 
  - count:9
  - address:2293620
- countAddr (int *) 
  - count:2293620
  - address:2293624
- result (int)
  - count:9
  - address:2293632



|   表示式   | 数据类型 |   值    |
| :--------: | :------: | :-----: |
|   count    |   int    |    9    |
|   &count   |  int *   | 2293620 |
| countAddr  |  int *   | 2293620 |
| *countAddr |   int    |    9    |



```c
int count = 9;

int a;
int *b;

a = count;  // (O) (int)   = (int)
b = count;  // (X) (int *) = (int)

a = &count; // (X) (int)   = (int *)
b = &count; // (O) (int *) = (int *)

count = *a; // (X) (int) = (int *)
count = *b; // (O) (int) = (int **)
```



### 指针的特殊能力

```c
// (1)
int count = 9;
int *countAddr = &count;
int result = *countAddr;

// 相等于

int count = 9;
int result = count;


// (2)
// 此时count的值被改变了
int count = 9;  // 取值
int *countAddr = &count;  // 取址
*countAddr = 10; // 可以对其赋值

// 不相等于

// count的值并没有改变
int count = 9;
int result = count;
result = 10;

// 相等于

int count = 9;
count = 10;
```

关于指针的特殊能力

- 透过count的内存地址读取count值
- 透过count的内存地址写count值
- 要读写某个变量的值，可以透过变量的名称也可以透过变量所在的内存地址



```c
int countA = 9;
int countB = 10;
int *countAddr;

countAddr = &countA;
*countAddr = 0;

countAddr = &countB;
*countAddr = 0;

// 相当于

int countA = 9;
int countB = 10;
countA = 0;
countB = 0;
```





## 21-4  更多指针与取址间接运算的细节

### 指针类型与取址和间接运算

- 指针(type *)：可储存内存地址的类型
- 取址运算符(&)：可取得变量的内存起始地址
  - &变量
- 间接运算符(*)：取得以该内存地址起始的变量
  - *内存地址



### 取址与间接运算的关系

```c
int count = 9;
int *countAddr = &count;
int result = *countAddr; // &count
int result = *&count; // count

*countAddr = 10; // count = 10

*&*&*&*&result = 20; // result = 20

```



- count
  - type：int
  - count：9
  - address：(int *)&count
- countAddr
  - type：int *
  - count：&count
  - address：(int **)&countAddr
- result
  - type：int
  - count：? ?
  - address：(int *)&result