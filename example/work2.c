 #include<stdio.h>
#define MaxSize 100
int main(){
int lightnum;
int a[MaxSize];
printf("input:");
scanf("%d",&lightnum);
for(int i=0;i<lightnum;i++){
a[i] = 0;
if((i+1)%2==0)
a[i] = 1;
if((i+1)%3==0)
a[i] = a[i]?0:1;
}
for(int i=3;i<lightnum;i++){
for(int j=1;j*(i+1)<=lightnum;j++)
a[j*(i+1)-1] = a[j*(i+1)-1]?0:1;
}
for(int i=0;i<lightnum;i++){
if(a[i]==1)
printf("section %-3d is %-5s;\n",i+1,a[i]?"open":"close");
}
}
