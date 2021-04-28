#include <stdio.h>
int main()
{
    //const是一个修饰符(必须初始化)  加在int前面  这个变量的值将不能在修改
    /*     const int amount = 100;
    int price = 0;
    printf("请输入金额(元):");
    scanf("%d", &price);
    int change = amount - price;
    printf("您输入的金额为%d元\n", price);
    printf("找您%d元.\n", change);
 */
    int amount = 100;
    int price = 0;
    printf("请输入金额(元):");
    scanf("%d", &price);
    printf("请输入票面(元):");
    scanf("%d", &amount);
    int change = amount - price;
    printf("您输入的金额为%d元\n", price);
    printf("找您%d元.\n", change);
}