#include <stdio.h>

int main()
{

// scanf 发生错误时会返回EOF(mac按下 control+z  windows 在开头不输入连续三个ctrl+z)

/*

循环读取
int i;
while(scanf("%d",&i)!=EOF){   //EOF 在"stdio.h"头文件中定义为-1  为了代码的可阅读性
    printf("i=%d\n", i);
    //若先输入一个数字回车后再输入一个字符就会一直打印上一个输入的数字进入死循环
    //因为输入一个字符不会跟%d匹配 而scanf的返回值是匹配成功的个数 没有匹配成功则返回0  1!=-1 会继续循环
} */
/*
int i;
while(rewind(stdin),scanf("%d",&i)!=EOF){  //stdin是标准输入    逗号运算符的值是最后一个表达式的值  
    printf("i=%d\n", i);

    //使用rewind(stdin)清空缓冲区后就不会进入死循环
} */


/* //循环读取字符
char c;
while (scanf("%c",&c))
{
 if(c!='\n'){
     printf("%c",c-32);
 }
 else{
     printf("\n");
 }
} */

/* 
//混合输入(多种类型数据输入) 空格的ASCII码值为32
//混合输入时在%c之前加一个空格(为避免匹配到空格)
int i;
char c;
float f;
scanf("%d %c%f", &i, &c, &f);
printf("i=%d,c=%c,f=%f",i,c,f); */



//pintf格式化输出
//%4.1f   一共输出4位小数点后显示一位 
//%3d 输出4位 默认靠右对齐  %-3d 输出3位靠左对齐
// printf("name=%s,age=%3d,sex=%c,score=%4.1f\n","Azrael",22,'m',99.9);   
// printf("name=%s,age=%-3d,sex=%c,score=%4.1f\n","Azrael",22,'m',99.9);   

int i;
char j;
float k;
	scanf("%d %c%f",&i,&j,&k);
    printf("%5.2f",i+j+k);
    return 0;
}