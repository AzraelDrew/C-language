#include <stdio.h>
#include <stdbool.h>

int main(){
    bool b = 6>5;
    bool t = true;
    bool f = false;
    printf("%d\n%d\n",t,f);   //只会输出0或1不会输出true或false
}