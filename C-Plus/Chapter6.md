# Chapter6

## 6-1 对两个变量按照大小排序(使用if)

(1)

```c
#include<stdio.h>

int main(){
	int a,b,t;
	scanf("%d %d",&a,&b);
	printf("Before : %d %d\n",a,b);
	if(a > b){
		t = a;
		a = b;
		b = t;
	}
	printf("After:   %d %d\n",a,b);
	return 0;
}
```





## 6-2 三个变量的数值交换

(1) ABC->CAB

```c
#include<stdio.h>
int main(){
	int a,b,c,t;
	scanf("%d %d %d",&a,&b,&c);
	printf("Before: %d %d %d\n",a,b,c);
	// 将a与c交换
	t = a;
	a = c;
	c = t;
	// 将b与c交换
	t = b;
    b = c;
    c = t;
	printf("After:   %d %d %d\n",a,b,c);
	return 0;
}
```



(2) ABC->BCA

```c
#include<stdio.h>
int main(){
	int a,b,c,t;
	scanf("%d %d %d",&a,&b,&c);
	printf("Before: %d %d %d\n",a,b,c);
	// 将a与b交换
	t = a;
    a = b;
    b = c;
    c = a;
    
    // a与b交换
    t = a;
    a = b;
    b = t;
    
    
    // b与c交换
    t = b;
    b = c;
    c = t;
	printf("After:   %d %d %d\n",a,b,c);
	return 0;
}
```







## 6-3 对三个变量依照大小排序练习

总结：对三个变量依照大小排序

- 由小到大排序
- 变量间可能的大小顺序关系：
  - a < b < c  -->  不用任何处理
  - a < c < b  -->  c与b做数值交换[两个变量] (c,b) --> (b,c)
  - b < a < c  -->  b与a做数值交换[两个变量] (b,a) --> (a,b)
  - b < c < a  -->  b,c,a间做数值交换[三个变量] (b,c,a) --> (a,b,c)
  - c < a < b  -->   c,a,b间做数值交换[三个变量] (c,a,b) --> (a,b,c)
  - c < b < a -->  c与a做数值交换[两个变量] (c,a) --> (a,c)



```c
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("Before: %d %d %d\n",a,b,c);
	if(a < c && c < b){
		// c 与 b 做数值交换: (c,b) -> (b,c)
	}
	if(b < a && a < c){
		// b 与 a 做数值交换: (b,a) -> (a,b)
	}
	if(b < c && c < a){
		// b,c,a 间做数值交换: (b,c,a) -> (a,b,c)
	}
	if(c < a && a < b){
		// c,a,b 间做数值交换: (c,a,b) -> (a,b,c)
	}
	if(c < b && b < a){
		// c 与 b 做数值交换: (c,a) -> (a,c)
	}
	printf("After:   %d %d %d\n",a,b,c);
	return 0;
}
```





```c
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c); // 3 3 2
	printf("Before: %d %d %d\n",a,b,c);
	if(a < c && c < b){
		t = b; b = c; c = t;// c 与 b 做数值交换: (c,b) -> (b,c)
	}
	if(b < a && a < c){
		t = a; a = b; b = t;// b 与 a 做数值交换: (b,a) -> (a,b)
	}
	if(b < c && c < a){
		t = a; a = b; b = c; c = t;// b,c,a 间做数值交换: (b,c,a) -> (a,b,c)
	}
	if(c < a && a < b){
		t = a; a = c; c = b; b = t;// c,a,b 间做数值交换: (c,a,b) -> (a,b,c)
	}
	if(c < b && b < a){
		t = a; a = c; c = t;// c 与 b 做数值交换: (c,a) -> (a,c)
	}
	printf("After:   %d %d %d\n",a,b,c);
	return 0;
}
```





## 6-4 用两个变量的数值交换对三个变量做排序

- 将a,b,c中最大的数值换到变量a
  - 将a,b中较大的数值换到变量a
  - 将a,c中较大的数值换到变量a
- 将b,c中较大的属猪换到变量b

```c
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c); // 3 3 2
	printf("Before: %d %d %d\n",a,b,c);
	if( b < a ){
		t = b; b = a; a = t;
	}
	if( c < a ){
		t = c; c = a; a = t;
	}
	if(c < b){
		t = c; c = b; b = t;
	}
	printf("After:   %d %d %d\n",a,b,c);
	return 0;
}
```



- 将a,b,c中最大的数值换到变量c
  - 将a,c中较大的数值换到变量c
  - 将b,c中较大的数值换到变量c
- 将a,b中较大的属猪换到变量b



```c
#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c); // 3 3 2
	printf("Before: %d %d %d\n",a,b,c);
	if( c < a ){
		t = c; c = a; a = t;
	}
	if( c < b ){
		t = c; c = b; b = t;
	}
	if( b < a ){
		t = b; b = a; a = t;
	}
	printf("After:   %d %d %d\n",a,b,c);
	return 0;
}
```



## 6-5 用排序简化三角形种类判断条件(使用if)

输入某三角形的三边长(皆为整数),判断这个三角形是不是下列各种三角形

- 正三角形(Regular triangle)：三边都一样长
- 等腰三角形(Isosceles triangle)：有两边一样长
- 直角三角形(Rectangular triangle)：两边长的平方和等于第三边的平方

```c
#include<stdio.h>
int main(){
    int side1,side2,side3;
	printf("Please enter the lengths: ");
    scanf("%d %d %d",&side1,&side2,&side3);
    // 排序 side1 <= side2 <= side3
    if(side1 > side2) { t = side1; side1 = side2; side2 = t };
    if(side1 > side3) { t = side1; side1 = side3; side3 = t };
    if(side2 > side3) { t = side2; side2 = side3; side3 = t };
    
    // 三角形种类判断
    if(side1 == side3){
        printf("Regular triangle.\n");
    }
    if(side1 == side2 || side2 == side3){
        printf("Isosceles triangle.\n");
    }
    if(side1 * side1 + side2 * side2 == side3 * side3){
        printf("Rectangular triangle.\n");
    }
    return 0;
}
```

