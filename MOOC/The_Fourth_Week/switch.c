#include <stdio.h>
int main(){
    int type;
    printf("请输入数字:");
    scanf("%d",&type);
    // if(type==1){
    //  printf("你好\n");
    // }
    // else if(type==2){
    //  printf("早上好\n");   
    // }
    // else if(type==3){
    //  printf("晚上好\n");   
    // }
    // else if(type==4){
    //  printf("再见\n");   
    // }else{
    //  printf("啊, 什么啊?\n");
    // }

    // switch(type){
    //     case 1 :
    //         printf("你好\n");
    //         break;
    //     case 2 :
    //         printf("早上好\n");
    //         break;
    //     case 3 :
    //         printf("晚上好\n");
    //         break;
    //     case 4 :
    //         printf("再见\n");
    //         break;
    //     default :
    //         printf("啊,什么啊?");
    //         break;
    // }

    // switch(type){
    //     case 1 :
    //     case 2 :
    //         printf("早上好\n");
    //         break;
    //     case 3 :
    //         printf("晚上好\n");
    //     case 4 :
    //         printf("再见\n");
    //         break;
    //     default :
    //         printf("啊,什么啊?\n");
    //         break;
    // }

    // type = type /10;
    // switch(type){
    // case 10:
    // case 9:
    // printf("A\n");
    // break;
    // case 8:
    // printf("B\n");
    // break;
    // case 7:
    // printf("C\n");
    // break;
    // case 6:
    // printf("D\n");
    // break;
    // default:
    // printf("F\n");
    // break;
    // }

    int t=(type>=0)+(type==0);    
    //true + true = 2
    //true + false = 1
    //false + fasle = 0 
    switch(t){
        case 0:
            type=-1;
            break;
        case 1:
            type=2*type;
            break;
        case 2:
            type=0;
            break;

    }
    printf("%d\n",type);
}