/* 

强制类型转换

(type_name) expression

int x;
(double) x;   
 */

#include "stdio.h"
int main()
{
    int sum = 17, count = 5;
    double mean;
    mean = (double)sum / count;
    /* 
    这里要注意的是强制类型转换运算符的优先级大于除法，因此 sum 的值首先被转换为 double 型，然后除以 count，得到一个类型为 double 的值。
     */
    printf("Value of mean:%f\n", mean);

    int i = 17;
    char c = 'c'; /* ascii 值是 99 */
    int sum1;
    /* 在这里，sum 的值为 116，因为编译器进行了整数提升，在执行实际加法运算时，把 'c' 的值转换为对应的 ascii 值。 */
    sum1 = i + c;
    printf("Value of sum : %d\n", sum1);
    int i1 = 17;
    char c1 = 'c'; /* ascii 值是 99 */
    float sum2;
    /* 在这里，c 首先被转换为整数，但是由于最后的值是 float 型的，所以会应用常用的算术转换，编译器会把 i 和 c 转换为浮点型，并把它们相加得到一个浮点数。 */
    sum2 = i1 + c1;
    printf("Value of sum : %f\n", sum2);
    return 0;
}