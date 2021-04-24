/* 
字符串*

在 C 语言中，字符串实际上是使用 null 字符 \0 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。

其实，您不需要把 null 字符放在字符串常量的末尾。C 编译器会在初始化数组时，自动把 \0 放在字符串的末尾。
C 中有大量操作字符串的函数：


1	strcpy(s1, s2);

复制字符串 s2 到字符串 s1。

2	strcat(s1, s2);

连接字符串 s2 到字符串 s1 的末尾。

3	strlen(s1);

返回字符串 s1 的长度。

4	strcmp(s1, s2);

如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。

5	strchr(s1, ch);

返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。

6	strstr(s1, s2);

返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。

*/
#include <stdio.h>
#include <string.h>
int main()
{
    char site[7] = {'R', 'U', 'N', 'O', 'O', 'B'};
    char site1[] = "RUNOOB";
    printf("菜鸟教程：%s\n", site);
    printf("菜鸟教程：%s\n", site1);

    char str1[14] = "runoob";
    char str2[14] = "google";
    char str3[14];
    int len;

    // 把str1复制给str3
    strcpy(str3, str1);
    printf("strcpy(str3,str1):%s\n", str3);
    // 连接str2到str1的末尾
    strcat(str1, str2);
    printf("strcat(str1,str3):%s\n", str1);
    len = strlen(str1);
    printf("strlen(str1):%d\n", len);
    printf("%d\n", strcmp(str1, str2));
    return 0;
}