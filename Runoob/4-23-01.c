/* 

传递指针给函数 

C 语言允许您传递指针给函数，只需要简单地声明函数参数为指针类型即可。

通过引用或地址传递参数，使传递的参数在调用函数中被改变。
*/

#include <stdio.h>
#include <time.h>

int getSecoonds(unsigned long *par)
{
    *par = time(NULL); //获取当前秒数
    return 0;
}
double getAverage(int *arr, int size)
{
    int i, sum = 0;
    double avg;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    avg = (double)sum / size;
    return avg;
}
int main()
{
    unsigned long sec;
    getSecoonds(&sec);
    printf("Number of seconds:%ld\n", sec);
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    /* 传递一个指向数组的指针作为参数 */
    avg = getAverage(balance, 5);
    printf("Average value is:%f\n", avg);

    int *a;
    int balance2[5] = {1000, 2, 3, 17, 50};
    a = balance2;
    printf("%d\n", a[1]);
    return 0;
}