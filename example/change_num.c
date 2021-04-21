#include <stdio.h>
int main()
{
    int a, b, c;
    int q, p;
    a = 1,
    b = 2,
    c = 3;
    printf("a=%d,b=%d,c=%d\n", a, b, c);
    q = a; //q=1
    a = b; //a=2
    p = b; //p=2
    b = c; //b=c
    c = q; //c=1

    // a = a + b + c;   //1+2+3
    // c = a - (b + c); //6-(2+3)
    // b = a - (b + c); //6-(2+1)
    // a = a - (b + c); //6-(3+1)
    printf("a=%d,b=%d,c=%d\n", a, b, c);
    return 0;
}