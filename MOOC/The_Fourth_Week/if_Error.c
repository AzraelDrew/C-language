#include <stdio.h>
int main()
{
    // 忘记大括号
    int age = 65;
    double salary1 = 4000;
    if (age > 60)
        salary1 = salary1 * 1.2;
    printf("%f\n", salary1);

    // if后面的分号
    double salary2 = 4000;
    if (age > 70)
        ;
    {
        salary1 = salary1 * 1.2;
        printf("%f\n", salary2);
    }

    // 错误使用==和=
    double salary3 = 4000;
    if (age = 60)
    { //if只要求()里的值是零或非零
        salary3 = salary3 * 1.2;
        printf("age=%d,salary=%f\n", age, salary3);
    }

    //代码风格
}