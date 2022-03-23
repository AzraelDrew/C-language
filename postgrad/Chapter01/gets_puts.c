#include <stdio.h>
int main()
{
    char c[50];   //字符数组的数组名里存的就是字符数组的起始地址  类型字符指针(c中每一个值的类型)    即 &c[0]=c
    gets(c); //读取字符串只有遇到换行时才会结束  且不会存储\n 而是改为存储'\0'
    puts(c); //等价于printf("%s",c);

    return 0;
}