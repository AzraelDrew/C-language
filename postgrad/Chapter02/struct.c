#include <stdio.h>
struct student{   // struct为关键字 student为结构体类型
    //结构体成员
    int num;
    char name[100];
    char sex;
    float score;
    //结构所占内存空间大小不能直接计算   内存编址时会对齐  
    //有些数据类型可能占不到一个字的空间(即结构体的空间会大于计算的空间)  用sizeof计算空间
    //目的是为了提高cpu效率  空间换时间
};   //结构体声明一定要加分号
struct test{
    int num;
    char name[100];
    char sex;
};
int main()
{
// 1001 lele M 98.50
// 1002 lili M 98.50
// 1001 nene M 98.50

/* 结构体与结构体数组 */
/*     struct student s = {1001,"lele",'M',98.5};  //s为结构体变量  定义及初始化
    printf("%d %s %c %5.2f\n",s.num,s.name,s.sex ,s.score);  //访问结构体成员
    struct student sarr[3]; //结构体数组
    for (int i = 0;i<3; i++){

        scanf("%d %s %c %f",&sarr[i].num,sarr[i].name,&sarr[i].sex,&sarr[i].score); 
    }
    for(int i = 0;i<3;i++){
        printf("%d %s %c %f\n",sarr[i].num,sarr[i].name,sarr[i].sex,sarr[i].score); 

    } */


    /* 结构体指针 */

    struct test s = {1001,"lili",'M'};
    struct test sarr[3] = {1001,"lili",'M',1004,"lele",'M',1006,"nene",'F'};
    struct test *p;
    p = &s;
    printf("%d %s %c\n",(*p).num,(*p).name,(*p).sex);
    printf("%d %s %c\n",p->num,p->name,p->sex);  //指针的成员选择
    p = sarr;
    printf("%d %s %c\n", p->num, p->name, p->sex);
    int num;
    printf("--------------------------------\n");
    num = p->num++;  //num=p->num; (p->num)++
    printf("num=%d,p->num=%d\n", num, p->num);  //1001 1002
    num = p++->num;  //num = p->num; p++
    printf("num=%d,p->num=%d\n", num, p->num);  //1002 1005 
    return 0;
}