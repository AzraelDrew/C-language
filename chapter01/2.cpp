#include "stdio.h"
int main(){
  int data[8][8];
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      data[i][j]=1;
    }
  }
  for(int i=2;i<8;i++){
    for(int j=1;j<i;j++){
      data[i][j]= data[i-1][j-1]+data[i-1][j];
    }
  }
  for(int i=0;i<8;i++){
    for(int j=0;j<=8;j++){
      printf("%4d",data[i][j]);
    }
    printf("\n");
  }
  getchar();
  return 0;
}