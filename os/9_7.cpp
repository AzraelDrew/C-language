#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define False 0
#define True 1
#define n 3
#define m 8

struct 
{
    char type[10];          //设备类名
    int count;              //拥有设备台数
    int remain;             //空闲台数
    int address;            //该设备在设备表中的起始地址
}equipType[n];

struct 
{
    int equipID;             //设备绝对号
    int remain;             // 设备是否已分配
    char jobName[5];        //占用设备的进程名
    int relNumber;          //设备分配的相对号
}equipment[m];              //设备表定义，假定系统有m个设备

int allocate(char * J,char * type,int mm)
{
    int i,t;
    //查询该类设备
    i = 0;
    while(i<n && strcmp(equipType[i].type,type)!=0)
    i++;
    if(i>=n)
    {
        printf("无该类设备，设备分配失败!\n");
        return False;
    }
    if(equipType[i].remain<1)
    {
        printf("该类设备不足，设备分配失败\n");
        return False;
    }
    t = equipType[i].address;               //取出该类设备表中的起始地址
    while(!(equipment[t].remain == 0))
    t++;
    //填写进程名，相对号，状态改为已经分配
    equipType[i].remain--;
    equipment[t].remain = 1;
    strcpy(equipment[t].jobName,J);
    equipment[t].relNumber = mm;
    printf("设备分配成功!\n");
    return True;
}                           //设备分配函数结束
int reclaim(char * J,char *type)
{
    int i,t,j,k,nn;
    i = 0;
    while (i<n && strcmp(equipType[i].type,type)!=0)
    i++;

    if(i >= n)
    {
        printf("无该类设备，设备回收失败!\n");
        return False;        
    }
    t = equipType[i].address;                   //取出该设备在内存中的起始地址
    j = equipType[i].count;                     //取出该设备的数量
    k = 0;
    nn = t + j;

    for(; t<nn; t++)
    if(strcmp(equipment[t].jobName,J)== 0 && equipment[t].remain == 1)
    {
        equipment[t].remain = 0;
        strcpy(equipment[t].jobName,"");
        equipment[t].relNumber = 0;
        k++;
    }
    equipType[i].remain = equipType[i].remain + k;
    if(k == 0)
        printf("该进程没有使用该类设备!\n");
    printf("设备回收成功!\n");
    return True;
}                               //设备回收该函数

int main(int argc,char * argv[])
{
    char J[5];
    int i,mm,a;
    char type[10];
    //设备类表初始化
    strcpy(equipType[0].type, "input");        //输人机
    equipType[0].count = 2;
    equipType[0].remain = 2;
    equipType[0].address = 0;
    strcpy(equipType[1].type, "printer");      //打印机
    equipType[1].count = 3;
    equipType[1].remain = 3;
    equipType[1].address = 2;
    strcpy(equipType[2].type, "type");          //磁带机
    equipType[2].count = 3;
    equipType[2].remain = 3;
    equipType[2].address = 5;
    //设备表初始化
    for(i = 0;i<8;i++)
    {
        equipment[i].equipID = i;
        equipment[i].remain = 0;
    }
    while(1)
    {
        printf("1 - 分配,2 - 回收,3 - 显示,0 - 退出\n");
        printf("请选择功能项(0 - 3):");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            printf("请输入进程名、所需设备类和设备相对号:\n");
            scanf("%s%s%d",J,type,&mm);
            allocate(J,type,mm);
            break;
        case 2:
            printf("请输入进程名和进程归还的设备类:\n");
            scanf("%s%s",J,type);
            reclaim(J,type);
            break;
        case 3:
            printf("输入设备类表:\n");
            printf("设备类型    设备总量    空闲设备\n");
            for(i = 0;i<n;i++)
                printf("%s\t\t%d\t%d\n",equipType[i].type,equipType[i].count,equipType[i].remain);
            printf("输出设备表:\n");
            printf("绝对号  已/未分配   占用进程名  相对号\n");
            for(i = 0;i<m;i++)
                printf("%d\t%d\t\t%s\t%d\n",equipment[i].equipID,equipment[i].remain,equipment[i].jobName,equipment[i].relNumber);
            break;
        case 0:
            exit(0);
        }
    }
    return 0;


}