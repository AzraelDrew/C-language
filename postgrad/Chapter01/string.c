// 字符常量 


#include <stdio.h>
int main()
{
    char c = 'a';   //只能使用单引号  占一个字节
    printf("%c\n", c);  //以字符形式输出对应的数据  
    printf("%d\n", c);  //输出字符c的ASCII码值
    printf("%c\n", 97);  //输出97(ASCII)对应的字符



   // 字符大小写转换
    printf("%c,%c,%d\n", c,c - 32,c-32);  // a,A,65
    char b = 'A';
    printf("%c,%c,%d\n",b,b+32,b);   //A,a,65
    return 0;
} 