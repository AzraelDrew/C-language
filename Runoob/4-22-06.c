/* 
指向指针的指针

 */

#include <stdio.h>
int main()
{
    int V;
    int *pt1;
    int **pt2;
    V = 100;
    pt1 = &V;
    pt2 = &pt1;
    printf("V = %d\n", V);
    printf("pt1 = %d\n", *pt1);
    printf("*pt1 = %p\n", pt1);
    printf("pt2 = %d\n", **pt2);
    printf("**pt2 = %p\n", pt2);
    return 0;
}