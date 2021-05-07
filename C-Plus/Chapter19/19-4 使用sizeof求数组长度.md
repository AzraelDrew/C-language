# 19-4 使用sizeof求数组长度

## 关于sizeof

- 数据类型占用的记忆体空间大小大多属于"实作定义"，会随着编译器与设定上的不同而有所差异。

- `sizeof`可以求出某个值或某种类型所占用的记忆体大小(以位元组为单位)

  - `sizeof`运算的结果为`size_t`类型(在`printf`时使用`zu`)

  ```c
  printf("Size of long int: %zu\n",sizeof(long int));
  printf("Size of 3: %zu\n",sizeof(3));
  ```

  



## 用sizeof求数组长度

### 在主函数内引用数组

```c
#include<stdio.h>

int main() {
	int v[3] = {1,2,3};
	printf("Size of int: %zu\n",sizeof(int)); // 4
	printf("Size of v[0]: %zu\n",sizeof(v[0])); // 4
	printf("Size of v: %zu\n",sizeof(v));  // 12
	printf("Length of v: %zu\n",sizeof(v[0]));  // 3
	return 0;
}
```



### 在函数内引用数组

```c
#include<stdio.h>
int f(int[3]);

int main() {
	int v[3] = {1,2,3};
	f(v);
	return 0;
}

void f(int v[3]){
	printf("Size of int: %zu\n",sizeof(int)); // 4
	printf("Size of v[0]: %zu\n",sizeof(v[0])); // 4
	printf("Size of v: %zu\n",sizeof(v));  // 8
	printf("Length of v: %zu\n",sizeof(v[0]));  // 2
}
```

