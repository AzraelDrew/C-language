#include<stdio.h>
#define MaxSize 8
int main(){
int a[MaxSize];
int temp;
int flag=1;
int s= 0;
for(int i=0;i<MaxSize;i++)
scanf("%d",&a[i]);
for(int i=0;(i<MaxSize)&&flag;i++){
flag = 0;
for(int j=MaxSize-1;j>=i;j--){
if(a[j]<a[j-1]){
temp = a[j];
a[j] = a[j-1];
a[j-1] = temp;
flag = 1;
}
}
}
for(int i=0;i<MaxSize;i++)
printf("%d ",a[i]);
}
