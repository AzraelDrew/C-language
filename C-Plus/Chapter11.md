# Chapter11

## 11.1 打印九九乘法表(for)

(1)

```c
#include<stdio.h>

int main() {
	int i,j;
	for(i = 1; i <= 9; ++i){
		for(j = 1; j <= i; ++j){
			printf("%d * %d = %d",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main() {
	int c;
	for(c = 1; c <= 72; ++c){
		int i = (c-1)/9+2;
		int j = (c-1)%9+1;
		printf("%d x %d = %d\n",i,j,i*j);
		
	}
	return 0;
}
```



## 11.2 用文字绘制长方形的练习



```c
#include<stdio.h>

int main() {
        int M,N;
        printf("M = ");
        scanf("%d",&M);
        printf("N = ");
        scanf("%d",&N);
        int i,j;
        //  控制行
        for(i = 1;i <= N;i++){
            //  控制列
            for(j = 1;j <=M;j++){
                printf("*");
            }
            printf("\n");
        }
    	return 0;
}
```





## 11.3 用文字绘制空心长方形的练习

原理

```c
#include<stdio.h>
// N = 3
int main() {
    int N;
    printf("N = ");
    scanf("%d",&N);

    int i;
    for(i=1; i<=N; i++){
    	printf("*");
    }
    printf("\n");

    printf("*");
    for(i=1; i<=N-2; i++){
    	printf(" ");
    }
    printf("*\n");

    for(i=1; i<=N; i++){
    	printf("*");
    }
    printf("\n");
    return 0;
}
```

具体实现

```c
#include<stdio.h>

int main() {
    int N;
    printf("N = ");
    scanf("%d",&N);
    
    int i,j;
    for(j=1; j<=N; ++j){
    	printf("*");
    }
    printf("\n");
    
    for(i=1; i<=N-2; ++i){
    	printf("*");
    	for(j=1; j<=N-2; ++j){
    		printf(" ");
    	}
    	printf("*\n");
    }
    
    for(j=1; j<=N; ++j){
    	printf("*");
    }
    printf("\n");
    return 0;  
}
```





## 11-4 用文字绘制三角形

（1）

```c
#include<stddio.h>

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
	
	printf("*\n");   // 打印 i 个星星 + 换行 (i = 1)
	printf("**\n");  // (i = 2)
	printf("***\n"); // (i = 3)
    
    return 0;
}
```



（2）

```c
#include<stdio.h>

int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
	
	int i,j;
    for(i=1; i<=N; i++){
        for(j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
```



## 11-5 空心三角形

原理

```c
#include<stdio.h>
int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
	
	printf("*\n");    // 印1个星星 + 换行
	printf("**\n");   // 印2个星星 + 换行
	printf("* *\n");  // 印1个星星 + 1个空白 + 1个星星 + 换行
	printf("*  *\n"); // 印1个星星 + 2个空白 + 1个星星 + 换行
	printf("*****\n");// 印5个星星 + 换行
    
    printf("*\n");    // 印1个星星 + 换行
	printf("**\n");   // 印1个星星 + i个空白 + 1个星星 + 换行 (i=0)
	printf("* *\n");  // 印1个星星 + i个空白 + 1个星星 + 换行 (i=1)
	printf("*  *\n"); // 印1个星星 + i个空白 + 1个星星 + 换行 (i=2)
	printf("*****\n");// 印5个星星 + 换行
}
```



实现

```c
#include<stdio.h>
int main(){
	int N;
	printf("N = ");
	scanf("%d",&N);
	
	int i,j;
	printf("*\n"); // 印1个星星 + 换行
	for(i=0; i<=2; ++i){
		printf("*"); // 印1个星星
		for(j=0;j<=i;++j){ // 印i个空白
			printf(" ");
		}
		printf("*\n");     // 印1个星星 + 换行
	}
	printf("******\n"); // 印1个星星 + 3个星星 + 1个星星 + 换行
	return 0;
}
```



## 11-6 基于坐标法用文字绘制三角形

显示坐标

```c
#include<stdio.h>
int main(){
	int i,j;
	for(i=1;i<=5;++i){
		for(j=1;j<=5;++j){
			printf("(%d,%d)",i,j);
		}
		printf("\n");
	}
	return 0;
}
```



显示代表直角三角形的坐标

```c
#include<stdio.h>
int main(){
	int i,j;
	for(i=1;i<=5;++i){
		for(j=1;j<=i;++j){
			printf("(%d,%d)",i,j);
		}
		printf("\n");
	}
	return 0;
}
```



使用坐标法绘制直角三角形

```c
#include<stdio.h>
int main(){
	int i,j;
	for(i=1;i<=5;++i){
		for(j=1;j<=i;++j){
			if(i>=j){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
```



使用坐标法绘制空心直角三角形

```c
		
		int N;
        printf("N = ");
        scanf("%d",&N);

        int i,j;
        for(i = 1;i <= N;i++){
            for(j = 1;j <= N;j++){
//            j==1 || i==N || i==j   左
//            i == 1 || j == N || i==j
              if(j == N || i==N || i+j == N+1){
                   printf("*");
              }else{
                   printf(" ");
                }
            }
            printf("\n");
        }
```

