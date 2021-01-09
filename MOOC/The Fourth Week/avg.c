#include <stdio.h>
int main(){
    int number ;
    int sum =0;
    int count = 0;
    printf("请输入你需要求的数字(输入-1结束):");
    scanf("%d",&number);
    while(number!=-1){
        sum += number;
        count++;
        printf("请输入你需要求的数字(输入-1结束):");
        scanf("%d",&number);

    }
    printf("%f\n",1.0*sum/count);
}