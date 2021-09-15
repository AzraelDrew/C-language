// #include "stdafx.h"
#include "stdio.h"
// #include "<iostream>"
int main(){
  int m=7;
  int n=4;
  int (**array) = new int *[m];
  for(int i=0;i<m;i++){
    array[i] =  new int[n];
  }
  for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
      array[i][j] =0;
    }
  }
int count =1;
int x=-1,y=n-1;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int k=0;
while(count<m*n){
   k%=4;
  if((x+dir[k][0]>m-1)||(y+dir[k][1]>n-1)||(x+dir[k][0]<0)||(y+dir[k][1]<0)||array[x+dir[k][0]][y+dir[k][1]]!=0){
    k++;
    continue;
  }
  x+=dir[k][0];
  y+=dir[k][1];
  array[x][y]=count++;
  // while(x<m-1 && array[x+1][y]==0){
  //   x++;
  //   array[x][y] = count;
  //   count++;
  // }
  // while(y>=-1 && array[x][y-1]==0){
  //   y--;
  //   array[x][y] = count;
  //   count++;
  // }
  // while(x>0 && array[x-1][y]==0){
  //   --x;
  //   array[x][y] = count;
  //   count++;
  // }
  // while(y<n-1 && array[x][y+1]==0){
  //   ++y;
  //   array[x][y] = count;
  //   count++;
  // }
}

  for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
      printf("%4d ",array[i][j]);
    }
    printf("\n");
  }
  for(int i=0;i<m;++i){
    delete[]array[i];
  }
  delete[]array;

  return 0;
}
