//scanf读取标准输入缓冲区的原理

//原理对于初试不重要,机试很重要
#include <stdio.h>
int main()
{
    //scanf    读取标准输入
    //printf   标准输出到terminal
/*     int a, b;
    int s = scanf("%d%d",&a,&b);   //前(字符串中%号的数目)后(变量的数目)参数的数目必须保持一致(可混合使用不限制数目)    scanf的返回值为输入的个数
    printf("%d,%d\n",a,b);
    printf("你输入了%d个数\n",s); */

//scanf只有当缓冲区为空的时候才会阻塞
//scanf为"行缓冲"(若只输入了10没有回车并不会触发I/O操作,只有遇到换行符时才会执行I/O操作)   当输入10 回车后才会执行I/O操作
//输入10且回车后标准输入缓冲区里就会有字符串(回车也会输入进缓冲区 ) "10\n"(三个字符1,0,\n)    (缓冲区里都是字符串)  
//第一个scanf就回把  "10"(两个字符) scanf会把 "10" 转成对应的数据类型赋值给i 剩下"\n"
//执行第二个scanf时缓冲区并不为空 即不会阻塞   会将 "\n" 匹配给a


//scanf在读取整型,浮点型,字符串时会忽略"\n" 空格符等字符 忽略是指 scanf在执行前会先把缓冲区中的内容删除,然后再阻塞
//scanf在读取字符型时不会忽略任何字符  所以scanf还是读取了缓冲区中残留的"\n"

/* 下列输出结果为:
10
i=10
c=

Hello World!
Hello World!%  

若匹配给a的字符串为空 则应该输出c=%  而不是c=(换行)
 */

    int i;
    char a;
    scanf("%d", &i);
    printf("i=%d\n", i);
    scanf("%c", &a);
    printf("a=%c\n", a);
    printf("Hello World!\n");
    printf("Hello World!");

    int j, k;
    scanf("%d%d", &j, &k); //  此处的%d%d 中间可加空格也可不加空格 加空格scanf会自动匹配  不加scanf会忽略   但输入时一定要用空格隔开
    printf("%d,%d", j, k);
    return 0;
}