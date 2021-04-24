#include <stdio.h>
int main()
{
    struct SIMPLE
    {
        int a;
        char b;
        double c;
    };
    struct COMPLEX
    {
        char string[100];
        struct SIMPLE a;
    };

    struct COMPLEX f = {"fasdfa", 56, 78, 45.6};

    // printf("%s\n",f.string);
    // printf("%d\n",f.a.a);
    // printf("%d\n",f.a.b);
    // printf("%f\n",f.a.c);
    struct NODE
    {
        char string[100];
        struct NODE *next_node;
    };
    // struct NODE node={"124"}
    struct NODE node = {"456", &node};
    printf("%s\n", node.string);
    printf("%s\n", node.next_node->string);

    {

    };
    return 0;
}