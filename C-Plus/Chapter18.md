# Chapter18

## 18-1 关于数组的记忆体配置

非数组类型变量的记忆体配置

```c
int v; // 未定义行为
int v = 3;


int v[6];
int v[6] = {1,2,3,4,5,6};
```





## 18-2 数组的数组

元素类型是数组的数组

```c
int v[2][3];
// v[2] => v[0] v[1]
// v[0] => (int[3])  v[1] => (int[3])
// v[0][0]  v[0][1] v[0][2]... v[1][2]
```



初始化

```c
int v[2][3] = {{1, 2, 3},{4, 5 ,6}};

int v[3][2] = {{1, 2} {3, 4}, {5, 6}};
```





## 18-3 用二维数组表示九宫格



```c
1 2 3   		1 4 7
4 5 6   		2 5 8
7 8 9   		3 6 9

int v[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

printf("%d\n",v[1][2]); // 6
```



实现:

(1)

```c
#include<stdio.h>

int main(){
    int v[3][3] = {
        {1, 2, 3},
        {4 ,5, 6},
        {7, 8, 9}
    };
    
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<i; j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
    int v[3][3],i,j,k = 1;
   	for(i=0; i<3; i++){
   		for(j=0; j<i; j++){
   			v[i][j] = k;
   			k++;
   			// v[i][j] = i * 3 + j + 1;
   		}
   	} 
   
    for(i=0; i<3; i++){
        for(j=0; j<i; j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```





## 18-4 用一维数组表示九宫格

九宫格

```c
1 2 3   		1 4 7
4 5 6   		2 5 8
7 8 9   		3 6 9

int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

printf("%d\n",v[3*1+2]); // 6
```



实现

(1)

```c
#include<stdio.h>

int main(){
	int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;
	
	for(i=0; i<9; i++){
		printf("%d ",v[i]);
		if(i % 3 == 2){
			printf("\n");
		}
	}
	return 0;
}
```



(2)

```c
#include<stdio.h>

int main(){
	int v[9];
	int i, k = 1;
    
    for(i=0; i<9; i++){
        v[i] = k;
        k++;
        // v[i] = i + 1; 
    }
	
	for(i=0; i<9; i++){
		printf("%d ",v[i]);
		if(i % 3 == 2){
			printf("\n");
		}
	}
	return 0;
}
```





## 18-5 随机生成九宫格

实现

一维数组：

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    arand(time(0));
    int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    for(i=0; i<9; i++){
        int m = rand() % (9-i) + i;
        int t = v[i];
        v[i] = v[m];
        v[m] = t;
    }
    for(i=0; i<9; i++){
        printf("%d ",v[i]);
        if(i % 3 == 2){
            printf("\n");
        }
    }
    return 0;
}
```





二维数组：

```c

int main(){
	srand(time(0));
	int v[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
	int i,j,k = 0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            int r = rand() % (9-k) + k;
            int m = r / 3;
            int n = r % 3;
            int t = v[i][j];
            v[i][j] = v[m][n];
            v[m][n] = t;
            k++;
        }
    }
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
	return 0;
}
```

