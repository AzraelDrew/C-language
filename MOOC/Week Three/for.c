#include <stdio.h>
int main(){
	// printf("请输入一个整数:");
	// int n;
	// scanf("%d",&n);
	// int fact = 1;
	// int i  =1;
	// // while(i<=n){
	// // 	fact *= i;   //fact = fact * i
	// // 	i++;
	// // }

	// for(i=1;i<=n;i++){
	// 	fact*=i;
	// }

	// printf("%d! = %d\n",n,fact);
	int i=10;
	int s =1;
		for(i=10;i>0;i--){    //在for循环里面定义的话只能在c99中使用
		// printf("%d\n",i);
		s*=i;
		printf("%d\n",i);
	}
	printf("%d\n",s);
}
