// // #include <stdio.h>
//
// 
// // int  loveYou(int n ){
// //     int a,b,c;
// //     if(n>1){
// //         loveYou(n-1);
// //     }
// //     printf("I Love You %d\n", n);
// //     return 0;
// // }
// // int main()
// // {
// //     loveYou(5);
// //     return 0;
// // }  




// // #include<stdio.h>
// // #include<stdlib.h>
// // #define InitSize 10

// // typedef int ElemType;

// // typedef struct {
// //  ElemType *data;
// //  int length;
// //  int MaxSize;
// // }SeqList;

// // void InitList(SeqList &L) {
// //  L.data = (ElemType *) malloc(sizeof(ElemType) * InitSize);
// //  L.length = 0;
// //  L.MaxSize = InitSize;
// // }

// // void IncreaseSize(SeqList &L, int len) {
// //  ElemType *p = L.data;
// //  L.data = (ElemType *)malloc(sizeof(ElemType)*(len + L.length));
// //  for (int i = 0; i < L.length; i++) {
// //   L.data[i] = p[i];
// //  }
// //  L.MaxSize = L.MaxSize + len;
// // }

// // bool InsertList(SeqList &L, int i, ElemType e) {
// //  if (i<1 || i>L.length+1 || i>=L.MaxSize) {
// //   return false;
// //  }
// //  for (int j = L.length; j > i; j--) {
// //   L.data[j] = L.data[j - 1];
// //  }
// //  L.data[i - 1] = e;
// //  L.length++;
// //  return true;
// // }

// // bool DelList(SeqList &L, int i, ElemType &e) {
// //  if (i<1 || i>L.length)
// //   return false;
// //  e = L.data[i - 1];
// //  for (int j = i; j < L.length; j++) {
// //   L.data[j - 1] = L.data[j];
// //  }
// //  L.data[L.length-1] = NULL;
// //  L.length--;
// //  return true;
// // }

// // ElemType GetElem(SeqList &L, int i) {
// //  return L.data[i - 1];
// // }

// // int GetLocation(SeqList &L, ElemType e) {
// //  for (int i = 0; i < L.length; i++) {
// //   if (L.data[i] == e)
// //    return i+1;
// //  }
// //  return -1;
// // }

// // int main() {
// //  SeqList L;
// //  InitList(L);
// //  for (int i = 1; i <= 10; i++) {
// //   InsertList(L,i, (ElemType)i);
// //  }
// //  for (int i = 0; i < 10; i++) {
// //   printf("%d\t", L.data[i]);
// //  }
//  #include <stdio.h>
//  #include <string.h>


//  int main(){
//   //  char a[10] = "1234";
//   //  gets(a);
//   //  printf("%c\n", a[2]);
//   //  printf("%c\n", a[3]);
//   //  strcat(a, "678");
//   //  printf("%s\n", a);
//   // int x[][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
//   // printf("%d\n",x[0][2]);
//   // printf("%d\n",x[1][1]);
//   // printf("%d\n",x[2][0]);

//   int x[5];
//   for (int i = 0; i < 5;i++){
//     scanf("%d", x[i]);
//   }
//   for (int i = 0; i < 5;i++){
//     printf("%4d\n", x[i]);
//   }
//     return 0;
//  }

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
  int top;
}SqStack;

void InitStack(SqStack &S){
	S.top =-1;
}

bool StackEmpty(SqStack S){
	if(S.top==-1){
    	return true;
    }
  return false;
}
bool PushStack(SqStack &S,ElemType e){
  if(S.top == MaxSize){
  	return false;
  }
  S.data[++S.top] = e;
  return true;
}

bool PopStack(SqStack &S,ElemType &e){
	if(StackEmpty(S)){
    	return false;
    }
  	e = S.data[S.top];
    S.top--;
    return true;
}

typedef struct {
  ElemType data[MaxSize];
  int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q){
  Q.front = Q.rear = 0;
}
bool isEmpty(SqQueue Q){
    if(Q.front ==Q.rear){
      return true;
    }
    return false;
}

bool EnQueue(SqQueue &Q,ElemType e){
  if((Q.rear+1)%MaxSize == Q.front){
    return false;
  }
  Q.data[Q.rear++] = e;
  Q.rear = (Q.rear) % MaxSize;
  return true;
}
bool DeQueue(SqQueue &Q,ElemType &e){
  if(Q.rear == Q.front){
    return false;
  }
  e = Q.data[Q.front++];
  Q.front = (Q.front)%MaxSize;
  return true;
}
int main(){
	SqStack S;
  	bool flag;
 	ElemType M;
  	InitStack(S);
  	ElemType x;
  	for(int i=0;i<3;i++){
    	scanf("%d",&x);
      	PushStack(S,x);
    }
  for(int i=0;i<3;i++){
      	PopStack(S,x);
    	printf("%2d",x);
    }
    printf("\n");
    SqQueue Q;
    InitQueue(Q);
    for (int i = 0; i < MaxSize; i++)
    {
      scanf("%d",&x);
      flag= EnQueue(Q, x);
      if(!flag){
        printf("false\n");
      }
    }

      for (int i = 0; i < MaxSize;i++){
        DeQueue(Q, x);
        printf("%2d", x);
        if(Q.rear==Q.front){
          break;
        }
      }
      printf("\n");
      return 0;
}
