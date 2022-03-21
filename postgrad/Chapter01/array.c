#include <stdio.h>
// 打印数组
void print(int array[],int len ){  //数组在传递时不能传递元素的个数,只会将数组的起始地址传过去
    int i;
    for (i = 0; i < len ;i++){
        printf("a[%d]=%-3d",i,array[i]);
    }
    array[9] = 20;   //函数内部也能更改数组的值
    printf("\na");
}
int main()
{
/* //array  类型 变量名[元素个数]
//int a[10];   //int类型的数组  变量名为a 它有10个元素
int a[10]={1, 3, 5, 6, 7};   //可以只赋值一部分  没有赋值的元素默认为0
int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};   
int c[10] = {0};  //赋值全为0
int d[] = {1, 2, 3, 4};  //也可以不指定数组长度 */

// int j=10;
// int a[5] = {1, 2, 3, 4, 5};
// int i=3;
// // a[5] = 20;   //访问越界(访问了不属于自己的空间)   访问越界会造成数据异常
// // printf("%d\n",j);

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
print(a, sizeof(a) / sizeof(a[0]));
printf("a[9]=%d\n",a[9]);
return 0;
}