#include <stdio.h>
int main(int argc, char const *argv[])
{
  // char **a; //a是一个指针,指向另一个指针(指向字符串的指针)

  char a[][10] = {
      "Hello",
      "World",
      "snvcd"};
  int b[] = {1};
  char *a1[6] = {
      "Hello",
      "World",
      "snvcd"};
  for (int i = 0; i < 3;i++){
    printf("a:%s\n", a[i]);
    printf("--------------\n");
    printf("a1:%s\n",a1[i]);
    printf("--------------\n");

  }
  

  int i;
  for (i = 0; i < argc; i++)
  {
    printf("%d:%s\n", i, argv[i]); //会输出  当你执行程序的时候后面输入的东西   如./build/8  123     会输出123
  }
  return 0;
}