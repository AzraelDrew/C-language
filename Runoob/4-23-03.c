/* 

函数指针

函数指针是指向函数的指针变量。

通常我们说的指针变量是指向一个整型、字符型或数组等变量，而函数指针是指向函数。

函数指针可以像一般函数一样，用于调用函数、传递参数。

函数指针变量的声明：

typedef int (*fun_ptr)(int,int); // 声明一个指向同样参数、返回值的函数指针类型

 */
#include <stdio.h>
#include <stdlib.h>
int max(int x, int y)
{
    return x > y ? x : y;
}
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = getNextValue();
    }
}
int getNextRandomValue(void)
{
    return rand();
}
int main()
{
    /* *p 是函数指针 */
    int (*p)(int, int) = max;
    int a, b, c, d;
    printf("请输入三个数字:");
    scanf("%d %d %d", &a, &b, &c);

    d = p(p(a, b), c); /* 与直接调用函数等价，d = max(max(a, b), c) */
    printf("最大的数字是：%d\n", d);

    int marray[10];
    populate_array(marray, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++)
    {
        /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于执行了getNextValue函数会得到一个返回值 , 而不是函数指针*/
        printf("%d\n", marray[i]);
        /* code */
    }

    return 0;
}