#include<stdio.h>
#define MaxSize 8
int main(){
int s,a,b,c;
printf("input a,b,c\n");
scanf("%d %d %d",&a,&b,&c);
if((a==0||b==0||c==0)||(a+b<=c||a+c<=b||b+c<=a))
printf("condition error");
else if(a==b&&b==c&&a==c)
printf("1等边三角形");
else if(a==b||b==c||a==c)
printf("2等腰三角形");
else if(a*a+b*b==c*c||c*c+b*b==a*a||a*a+c*c==b*b)
printf("3直角三角形");
else
printf("4一般三角形");
        return 0;

}
