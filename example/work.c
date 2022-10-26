#include <stdio.h>
void func(int num){
	if( num >0 ){
	int temp = num%10;
	num /= 10;
	func(num);
	printf("%-2d",temp);
	}
}

int main(){
	printf("Please input a number:");
	int num;
	scanf("%d",&num);
	func(num);
	printf("\n");
	return 0;
}
