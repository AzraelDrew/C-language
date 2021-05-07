# Chapter20

## 20 字串简介

### 字符串

- 字符串是字符的序列
  - 字符类型(char)可用来存储一个字符，但需要处理的文字经常是一串字符。
    - "Hello world" 是一串字符串而不仅仅是一个字符
- C语言并没有为字符串定义一个新的数据类型
  - 字符串是用字符数组(char[])的形式来储存
  - 透过在<string.h>内提供各种处理字符数组的函数来实现对字符串的操作行为。



### 字符数组

- 字符与字符数组
  - 一个字符类型变量可以存储一个字符
    - char ch = 'H';
  - 一个字符数组类型变量可以存储一到多个字符
    - char str[ ] = {'H', 'e', 'l', 'l', 'o'};
- 字符与字符数组
  - 字符串是以'\0'表示结尾的字符数组
    - char str[ ] = {'H', 'e', 'l', 'l', 'o', '\0'};
  - 字符数组可以用 "字符串内容" 进行初始化，会自动加上 '\0' 字符
    - char str[ ]= "Hello";



范例

```c
#include<stdio.h>

// 打印单个字符
void str_print(char str[]){
	printf("%c", str[0]);
}

// 打印字符串
void str_print1(char str[]){
	int i;
	for(i=0; i<5; i++){
		printf("%c",str[i]);
	}
	printf("\n");
}

int main() {
	char str[] = {
		'H', 'e', 'l', 'l', 'o'
	};
	str_print(str);
	return 0;
}
```





当字符串长度变长，该如何操作？

```c
#include<stdio.h>

// 打印字符串
void str_print1(char str[]){
	int i;
	for(i=0; i<11; i++){
		printf("%c",str[i]);
	}
	printf("\n");
}

int main() {
	char str[] = {
		'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'
	};
	str_print(str);
	return 0;
}
```



解决方案 

(1) 添加获取字符串长度的函数

```c
#include<stdio.h>

// 打印字符串
void str_print1(char str[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%c",str[i]);
	}
	printf("\n");
}

int main() {
	char str[] = {
		'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'
	};
	str_print(str,11);
	return 0;
}
```



(2)通过特殊值来判断字符数组长度并输出字符串

```c
#include<stdio.h>

// 打印字符串
void str_print1(char str[]){
	int i;
	for(i=0; str[i] != '\0'; i++){
		printf("%c",str[i]);
	}
	printf("\n");
}

int main() {
	char str[] = {
		'H', 'e', 'l', 'l', 'o', '\0'
	};
	str_print(str);
	return 0;
}
```



使用`%s`打印字符串

```c
#include<stdio.h>

// 打印字符串
void str_print1(char str[]){
	printf("%s\n",str);
}

int main() {
	char str[] = "Hello world";
	str_print(str);
	return 0;
}
```





## 20-1 写计算字符串长度的练习(function)

 显示字符串大小及长度

```c
#include<stdio.h>

int str_len(char str[]){
    // 回传第一个`\0`的位置
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

int main(){
    char str[] = "Hello world";
    printf("Length：%zu\n",sizeof(str));  // 12  
    printf("Length：%d\n",str_len(str));  // 11
    return 0;
}

// %zu为C99标准，如果编译器不支持则必须改为 %u 或 %lu
```

注：字符串在定义时会自动补全 '\0'

C语言允许字符数组大小刚好只包含有文字内容的部分，但这样的字符数组不能直接拿来给一般字符串处理函数使用





## 20-2 从键盘输入读入一行字的练习

试写一程序，让使用者输入一行文字后，将使用者输入的文字重新打印出来。

关于从键盘输入

- 在一般情况下：
  - 标准输入(stdin)就像是个档案，在键盘点击输入(Enter)键就会把输入的资料写入到标准输入内
  - 执行到`scanf`时，程序会试着从stdin读入资料。如果这时stdin里没有还没读的新资料则程序就会卡住(blocking)



```c
// 流程
键盘 -> Hello world -> (点击输入) -> stdin
									  |scanf
									 程序
```



实现

```c
#include<stdio.h>

void str_read(char[]);

int main(){
    char str[15];
    str_read(str);
    printf("%s\n",str);
    return 0;
}

// 1
void str_read(char str[]){
    while(1){
        char ch;
        scanf("%c",&ch);
        if(ch == '\n'){
            break;
        }
        i++;
    }
    str[i] = '\0';
}

// 2
void str_read(char str[]){
    int i =0;
    while(1){
        scanf("%c",&str[i]);
        if(str[i] == '\n'){
            break;
        }
        i++;
    }
    str[i] = '\0';
}
```





## 20-3 关于读入字符串的缓冲区溢位问题



```c
#include<stdio.h>

void str_read(char[],int);

int main(){
	// 在读入字符前就要先决定存放字符串的缓冲区大小
    char str[15];
    str_read(str,14);
    printf("%s\n",str);
    return 0;
}

void str_read(char str[],int n){
    int i =0;
    for(i=0; i<n; i++) {
    	scanf("%c",&str[i];
    	if(str[i] == '\n'){
    		break;
    	}
    }
    str[i] = '\0';
}
```



- 可以一边读一边改变数组大小吗？
  - 不能。因为数组大小在宣告定义之后就不能改变
- 能改变大小就能解决问题吗？
  - 资源终究有限



## 20-4 使用scanf函数读入资料的问题

`scanf`读入资料时的一些情况

```c
#include<stdio.h>

int main(){
	int number;
	scanf("%d",&number);
	printf("%d\n",number);
	return 0;
}

//   3   忽略空白
// abc   未定义行为
```



判断`scanf`函数是否成功读入资料

```c
#include<stdio.h>

int main(){
	int number;
	if(scanf("%d",&number) == 1){
		printf("%d\n","number");
	} else {
        printf("Error:Invalid input\n");
    }
	return 0;
}
```



`scanf`函数读入资料失败的后遗症

```c
#include<stdio.h>

int main(){
	int number;
	while(scanf("%d",&number) != 1){
		printf("Error:Invalid input\n");
	}
	printf("%d\n","number");
	return 0;
}
```

