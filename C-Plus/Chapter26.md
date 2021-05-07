# Chapter26

## 26-1 指针间转型的限制

在函数间传递数组

```c
#include<stdio.h>

void print(int (*q)[3]){
	int i;
	for(i = 0; i < sizeof(*q) / sizeof((*q)[0]); i++){
		printf("%d",(*q)[i]);
	}
	printf("\n");
}

int main(){
	int v[] = {1, 2, 3};
	printf(&v);
	return 0;
}
```

- 此方法无法共用一个函数参数
- int (*q)[ ] = int * (*q)