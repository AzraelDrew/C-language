#include <stdio.h>
int main()
{

    int year;
    scanf("%d", &year);

    //可以被400整除,或能被4整除但是不能被100整除
    if(year%400==0 || year%4==0 && year%100!=0){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}