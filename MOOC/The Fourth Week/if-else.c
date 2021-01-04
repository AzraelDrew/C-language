#include <stdio.h>
int main(){
//     int a;
//     int b;
//     int c;
//     int max;
//     printf("请输入三个数(中间用空格隔开):");
//     scanf("%d %d %d",&a,&b,&c);
//     if(a>b){ 
//         if(a>c){
//             max=a;
//         }else{
//             max=c;
//         }
//     }else if(a<b){
//         if(b>c){
//             max=b;
//         }else{
//             max=c;
//         }
//     }
// printf("max=%d\n",max);

const int READY = 24;
int code = 0;
int count = 0;

scanf("%d %d",&code,&count);
if(code == READY){
    if(count<20){
        printf("一切正常\n");
    }else{
        printf("继续等待\n");
    }
}
}

// else总是和最近的那个if匹配