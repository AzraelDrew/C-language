#include <stdio.h>
#include <stdlib.h>
void modifynum(int &b){  //把&写到形参的位置是c++的语法  c++称为引用
    b++;
}
void modify_pointer(int *&p)
{
    p = (int *)malloc(20);
    *p = 5; //*p = p[0]
    p[1] = 10;
    // free(p);
}
int main()
{
    int a = 10;
    modifynum(a);
    printf("%d\n",a);
    int *p= NULL;
    modify_pointer(p);
    printf("%d,%d\n",*p,p[1]);
    return 0;
}