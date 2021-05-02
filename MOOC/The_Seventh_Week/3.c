#include <stdio.h>
int search(int key, int a[], int len);
int amount[] = {1, 5, 10, 25, 50};
char *name[] = {"penny", "nickel", "dime", "quarter", "half-doallr"};
struct
{
  /* data */
  int amount;
  char *name;
} coins[] = {

    {1, "peeny"},
    {5, "nickel"},
    {10, "dime"},
    {25, "quarter"},
    {50, "half-dollar"},
};

int main()
{
  // int a[] = {1, 2, 3, 4, 5, 65, 64, 57, 5, 456, 34, 21, 43};
  int k = 50;
  // int r = search(k, amount, sizeof(amount) / sizeof(amount[0]));
  for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i++)
  {
    if (k == coins[i].amount)
    {
      printf("%s\n", coins[i].name);
      break;
    }
  }
  // if (r > -1)
  // {
  //   printf("%s\n", name[r]);
  // }
  // printf("%d\n", r);
  return 0;
}
int search(int key, int a[], int len)
{
  int ret = -1;
  for (int i = 0; i < len; i++)
  {
    if (key == a[i])
    {
      ret = i;
      break;
    }
  }
  return ret; //单一出口
}