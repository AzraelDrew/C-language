#include <stdio.h>
int main()
{
  char word[8];
  char word2[8];
  scanf("%7s", word); //scanf 读入一个单词  (到空格，tab或回车为止)   7表示最多读7个字符
  scanf("%7s", word2);
  printf("%s##%s##\n", word, word2);
  return 0;
}