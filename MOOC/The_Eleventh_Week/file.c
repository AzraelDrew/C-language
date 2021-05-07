#include <stdio.h>
int main()
{
  FILE *fp = fopen("./fileTest", "r");
  if (fp)
  {
    int num;
    fscanf(fp, "%d", &num);
    printf("%d\n", num);
    fclose(fp);
  }
  else
  {
    printf("无法打开文件\n");
  }

  return 0;
}