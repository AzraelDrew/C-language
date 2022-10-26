#include<stdio.h>
#define studentnum 2
#define classnum 5


int main(){
int a[studentnum][classnum];
int sum=0,total=0;
int i,j;
for(i=0;i<studentnum;i++){
printf("stu%d:\n",i);
for(j=0;j<classnum;j++)
scanf("%d",&a[i][j]);
}
for(i=0;i<studentnum;i++){
total = 0;
for(j=0;j<classnum;j++){
if(a[i][j]>=90)
total+=1;
if(total>=3)
break;
}
if(total>=3)
sum+=1;
}
printf("%d\n",sum);
return 0;
} 
