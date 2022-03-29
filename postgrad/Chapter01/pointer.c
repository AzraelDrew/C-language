#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// void change(int j)
// {
//     j = 5;    //每个函数都有自己的内存空间  调用函数时创建j 只是把i的值赋值给j  
// }


// void change(int *j)    //使用指针时传递的是变量的地址 更改的是j中的存放的地址的值
// {
//     *j = 5;    //每个函数都有自己的内存空间  调用函数时创建j
// }

//数组名作为实参传递给子函数时会弱化为指针
// void change(char *d){  // char *d === char d[]   都是指针
//     *d = 'H';
//     d[1] = 'E';
//     *(d + 2) = 'L';
// }

// char *print_stack(){
//     char c[] = "I am print_stack";
//     puts(c);
//     return c;    //返回的指针不能是函数内的栈空间
// }
char *print_malloc(){
    char *p = (char *)malloc(30);
    strcpy(p, "I am print_malloc");
    puts(p);
    return p;
}

void change(int **p,int *p2,int **p3,int *p4){
    *p = p2;
    *p3 = p4;
}
int main()
{
/* 指针的本质是间接访问 
   地址就是指针
*/  
/* 
    //指针用于保存地址
    //&(引用) 是取地址
    // *(解引用) 取值
    //指针初始化为某个变量的地址
    int i = 5;
    int *i_pointer = &i;   //整型指针变量 必须指向一个整形变量的地址 (什么类型的指针必须指向一个同类型变量的地址)  变量名为i_pointer 而不是*i_pointer
    printf("i=%d\n", i);  //直接访问
    printf("*i_pointer=%d\n", *i_pointer); //间接访问 *i_pointer 拿到i的地址 再去内存中找这个地址对应的值

    // &*i_pointer  = &i   *&i = i  */



    /* 指针的传递与偏移(只有这两种情况下使用指针) */

    /* 传递 */
/*     int i = 10;
    printf("before change i=%d\n",i);
    // change(i);   //每个函数都有自己的内存空间 代码编译时就会为每个函数及其变量创建属于自己的内存空间   这种调用只是值传递
    change(&i);
    printf("before change i=%d\n", i); */



    /* 偏移(指针的加减 乘除没有意义 ) */
/*     int a[5] = {1, 2, 3, 4, 5};  //变量a 类型是数组   a里面存的是一个地址值  是数组的起始地址  数组中的每一个元素都是存放的地址
    int *p;  //对一个指针变量进行取值,得到的类型是基类型
    p = a;
    printf("*p=%d\n",*p);
    for (int i = 0; i < 5; i++)
    {
        printf("p[%d]=%p\n",i, (p + i)); //此处+"1"  加的是基类型大小
    }for (int i = 0; i < 5; i++)
    {
        printf("*p[%d]=%d\n",i, *(p + i)); //此处+"1"  加的是基类型大小
    }
    printf("%d\n", a[0]);
    printf("%p\n", &a[0]); */

    /* 指针的自增与自减 */

// int a[3] = {2, 7, 8};
// int *p;
// int j;
// p = a;
/* // j = *p++; // j=*p; p++  任何时候都把后加加去掉,第二步看另外一个运算符的优先级是否高于++
// printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p);
j = (*p)++; // j=*p; (*p)++  会将p指向的地址的值+1
printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p); */

/* j = *p++; // j=*p; p++  任何时候都把后加加去掉,第二步看另外一个运算符的优先级是否高于++
printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p);  // 2 2 7
j = p[0]++; // j=p[0]=7; p[0]++等价于(*p)++ 此时的p已经++  p[0]指向的是7 数组a中第二个元素的地址
printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p); */



/* 指针与一维数组 */
// 函数的调用的本质是值传递
//数组传递时弱化为指针

/* char c[20] = "hello";
change(c);
puts(c); */



/* 指针与动态内存申请 */
/* //malloc 可以实现动态数组
int i;
scanf("%d",&i);
char *p;
//我们使用时需要强制类型转换  且只能赋值给同类型的指针变量  (赋值的时候等号左右两边的类型必须一致)
p = (char*)malloc(i);  //malloc申请空间是以字节为单位,不强制类型转换会警告   且返回值是一个void类型的指针
strcpy(p, "malloc successfully");
puts(p);
// 在free 时不能将指针偏移等操作 否则会找不到对应的地址空间(即p的值必须和malloc返回的值一致)
free(p);  //释放空间  p的值没有变(还是申请的起始地址)  即申请的地址还在 但是里面的内容变了
// free之后应把p赋值为NULL
p = NULL;   //若不把p赋值为NULL(NULL=0),称为野指针(指向一个不属于自己的地址)*/


/* 栈空间与堆空间的差异 */

/* char *p;
// p = print_stack();   //栈空间会随着函数的执行结束而释放
// puts(print_stack());
// puts(p);   //当函数结束后就会将函数的空间收回 相应的函数中的所有的内容都会回收
p = print_malloc();  //堆空间不会随着子函数的执行结束而释放,必须自己free,当进程结束时也会释放 
puts(p);  */

/* 字符指针与字符数组的初始化 */

/* char *p = "hello";   //相当于把字符串常量"hello"的首地址赋值给p
char c[] = "hello";  //相当于strcpy(c,"hello")   将"hello"放在自己栈空间(可读写)
c[0] = 'H';
// p[0] = 'H';  //不能对常量区的数据进行修改
printf("c[0]=%c\n", c[0]);
printf("p[0]=%c\n",p[0]);
p = "world";   //将字符串"world"的首地址赋值给p
// c = "world";  //非法   因为c的地址无法改变    即c的值无法修改
puts(p); */

int i = 10, j = 5;
int *pi=&i, *pj=&j;
printf("i=%d,*pi=%d,*pj=%d\n", i,*pi,*pj );
change(&pi,pj,&pj,pi);   //&pi就是一个二级指针类型   二级指针的初始化必须是一个一级指针的地址 
printf("after change i=%d,*pi=%d,*pj=%d\n", i,*pi,*pj );
return 0;
} 