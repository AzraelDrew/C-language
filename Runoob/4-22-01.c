/* 
传递数组给函数

如果您想要在函数中传递一个一维数组作为参数，您必须以下面三种方式来声明函数形式参数，

这三种声明方式的结果是一样的，因为每种方式都会告诉编译器将要接收一个整型指针。同样地，您也可以传递一个多维数组作为形式参数。

方式 1
形式参数是一个指针（您可以在下一章中学习到有关指针的知识）：

void myFunction(int *param)
{
.
.
.
}
方式 2
形式参数是一个已定义大小的数组：

void myFunction(int param[10])
{
.
.
.
}
方式 3
形式参数是一个未定义大小的数组：

void myFunction(int param[])
{
.
.
.
}
 */

#include <stdio.h>
int getAverage(int arr[], int size);
int main()
{
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    avg = getAverage(balance, sizeof(balance) / sizeof(balance[0]));
    // sizeof 可以获得数据类型或变量在内存中所占的字节数
    // sizeof(balance) / sizeof(balance[0])  获取数组长度
    printf("平均值是:%f\n", avg);
    return 0;
}

int getAverage(int arr[], int size)
{
    int i;
    double avg;
    double sum;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    avg = sum / size;
    return avg;
}