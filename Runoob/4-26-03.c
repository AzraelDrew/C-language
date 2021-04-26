/*  

输入 & 输出

scanf() 函数用于从标准输入（键盘）读取并格式化， printf() 函数发送格式化输出到标准输出（屏幕）。

所有的 C 语言程序都需要包含 main() 函数。 代码从 main() 函数开始执行。

printf() 用于格式化输出到屏幕。printf() 函数在 "stdio.h" 头文件中声明。

stdio.h 是一个头文件 (标准输入输出头文件) and #include 是一个预处理命令，用来引入头文件。 

当编译器遇到 printf() 函数时，如果没有找到 stdio.h 头文件，会发生编译错误。

return 0; 语句用于表示退出程序。

getchar() & putchar() 函数
int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。

这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。

int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。

这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符。
*/

#include <stdio.h> // 执行 printf() 函数需要该库
int main()
{
    printf("菜鸟教程\n"); //显示引号中的内容
    int testInteger = 5;
    printf("Number = %d\n", testInteger);
    float f;
    printf("Enter a number:");
    scanf("%f", &f);
    printf("Value = %f\n", f);

    int c;
    printf("Enter a value:");
    c = getchar();
    printf("\n You entered:");
    putchar(c);
    printf("\n");

    char str[100];
    int i;

    printf("Enter a value :");
    scanf("%s %d", str, &i);

    printf("\nYou entered: %s %d ", str, i);
    printf("\n");
    return 0;
}