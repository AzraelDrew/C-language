#include <stdio.h>
int main(int argc, char const *argv[])
{
  // char **a; //a是一个指针,指向另一个指针(指向字符串的指针)

  char a[][10] = {
      "Hello",
      "World",
      "snvcd"};
  char *a1[] = {//char *  ==a1[0]
                "Hello",
                "World",
                "sdfdshgjnvcd"};
  printf("%s\n", a[2]);

  int i;
  for (i = 0; i < argc; i++)
  {
    printf("%d:%s\n", i, argv[i]); //会输出  当你执行程序的时候后面输入的东西   如./build/8  123     会输出123
  }
  return 0;
}