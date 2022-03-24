#include <stdio.h>
#include <string.h>
int main()
{

    //strlen(c)   统计字符串长度
    // strcpy(d,c)  将c(c也可以为字符串常量)复制到d
    //strcmp(a,b)     用于比较两个字符串大小(比较的是每个位置的ASCII码值,当匹配到第几个不相等时就会结束  相等为0   大于为1  小于为-1)
    //strcat(a,b)   用于拼接两个字符串, 把b拼接到a的后面  (把b数组中的内容填充到a数组中  注意a数组的大小要能够容纳拼接后的字符串)

    char c[20] = "wangdao";
    printf("数组c内字符串长度为:%d\n",strlen(c));
    char d[20];
    strcpy(d,c);
    puts(d);
    strcpy(d,"stduy");
    puts(d);

    printf("两个字符串比较后的结果:%d\n", strcmp("hello","hello"));
    printf("两个字符串比较后的结果:%d\n", strcmp("how","hello"));   //o>e
    printf("两个字符串比较后的结果:%d\n", strcmp("hello","how"));   //o<e
    strcat(c, d);
    puts(c);
    return 0;
}