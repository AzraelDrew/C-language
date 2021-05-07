# Chapter24

## 24 指针与字符串

### 字符串

- 字符串是字符的序列，使用字符数组储存

  - 字符串是以`\0`表示结尾的字符数组

    ```c
    char str[] = {'t', 'e', 's', 't', '\0'};
    ```

  - 字符数列可以用"字符串"进行初始化，会自动加上`\0`字符

    ```c
    char str[] = "test";
    ```



### 在函数间传递字符串

```c
char strA[] = "test";
char strB[] = {'t', 'e', 's', 't', '\0'};

printf(strA);       // (O) 隐性转型成指针
printf(strB);		// (O) 隐性转型成指针

printf("test");										// (O:字符串字面量)
printf({'t', 'e', 's', 't', '\0'});				    // (X)

char *strC = "test";							    // (?: 字符串字面量)
char *strD = {'t', 'e', 's', 't', '\0'};  			// (X)

printf((char[]){'t', 'e', 's', 't', '\0'}); 		// {C99:复合字面量}
```





## 24-1 字符串常量的特殊性



```c
char strA[] = 'test';
char *strB = 'test';  // 字符串字面量可隐性转型成字符指针

strA[0] = 'T'; // (O)
strB[0] = 'T'; // (X) 未定义行为

strA = 'Test'; // (X) 编译失败
strB = 'Test'; // (O) 
```





## 24-2 const修饰字

### 概述

- 数据类型被const修饰的变量在 初始化 之外不能再赋值
  - 在C语言里可以看待成一个只读(read-only)的属性



```c
int a = 3;
const int b = 5;
const int c;    // 未定义行为
a = 4;
b = 6; // 编译失败
```



### 对数组元素使用const修饰字

- 数据类型被 const 修饰的变量在 初始化 之外不能再被赋值

```c
int a[3] = {3, 4, 5};
const int b[3] = {5, 6, 7};

a[0] = 4;
b[0] = 6;   // 编译失败
```



## 24-3 字符串字面量与const char*

### 使用 const char* 类型传递字符串

```c
int printf( const char * format,...);
```

详情至`cplusplus`

### 结论

一般情况下，能够放双引号的地方（即可放字符串字面量的地方），通常是一个 const  print的形式。





## 24-4 指针与const

### Type * 可以转成 const Type *

```c
char strA[] = "test";
char *strB = "test";
const char *strC = "test";

strA[0] = 'T'; // O
strB[0] = 'T'; // 未定义行为
strC[0] = 'T'; // 编译失败

strA = strB; // (char[]) = (char *);
strA = strC; // (char[]) = (const char *);
strB = strA; // (char *) = (char[]);        (O)
strB = strC; // (char *) = (const char *);
strC = strA; // (const char *) = (char [])  (O)
strC = strB; // (const char *) = (char *)   (O)
```



## 24-5 使用函数复制字符串

### 字符串的复制

错误做法

```c
#include<stdio.h>
#include<string.h>

int main(){
	char source[5] = "test";
	char destination[5];
	
	destination = source; // 编译失败
	
	printf("%s\n",destination);
	return 0;
}
```



浅复制

```c
#include<stdio.h>
#include<string.h>

int main(){
	char source[5] = "test";
	char *destination;
	
	// 浅复制(shallow copy)
	destination = source; 
	
	printf("%s\n",destination);
	return 0;
}
```



深复制

```c
#include<stdio.h>
#include<string.h>

int main(){
	char source[5] = "test";
	char destination[5];
	
	// 深复制(deep copy)
	int i;
	for(i = 0; i < 5; i++){
		destination[i] = source[i];
	}
	
	printf("%s\n",destination);
	return 0;
}
```



### 复制字符串的函数

`strcpy`

char * strcpy ( char * destination, const char * source);

copy string

将`source` 复制到`destination`

```c
#include<stdio.h>
#include<string.h>

int main(){
	const char *source = "test"; // char source[5] = 'test'
	// const char destination[5];
    char destination[5];
	
	strcpy(destination, source); 
	
	printf("%s\n",destination);
	return 0;
}
```



