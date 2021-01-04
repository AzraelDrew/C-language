#include <stdio.h>
int main(){
    int count;
    printf("请输入一个数:");
    scanf("%d",&count);
    count = count > 20 ? count - 10 : count + 10;
    printf("%d\n",count);
}