#include <stdio.h>
int main()
{
    //变量定义的一般形式<类型名称> <变量名称>
    int price = 0; //定义变量  int类型  初始值为0  也可以没有初始值  也可以同时定义多个变量用逗号隔开
    printf("请输入金额(元):");
    scanf("%d", &price); //捕获输入  将捕获到的值赋值给price
    //当输入的不是数字时会给一个默认值为0
    int change = 100 - price;
    printf("您输入的金额为:%d\n", price);
    printf("找您%d元\n", change);
    return 0;
}
