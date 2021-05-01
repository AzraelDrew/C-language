#include <stdio.h>
int main()
{
  //行号可以省略  ，
  // int arr[][5] = {
  //     {0, 1, 2, 3, 4},
  //     {5, 6, 7, 8, 9}};
  // for (int i = 0; i < 2; i++)
  // {
  //   for (int j = 0; j < 5; j++)
  //   {
  //     printf("%d\n", arr[i][j]);
  //   }
  // }
  const int size = 3;
  int board[size][size];
  int i, j;
  int numOfX;
  int numOfO;
  int result = -1; //-1没人赢  1:X赢  0：O赢

  //检查行
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      scanf("%d", &board[i][j]);
    }
  }
  for (i = 0; i < size && result == -1; i++)
  {
    numOfO = numOfX = 0;
    for (j = 0; j < size; j++)
    {
      if (board[i][j] == 1)
      {
        numOfX++;
      }
      else
      {
        numOfO++;
      }
    }
  }
  if (numOfO == size)
  {
    result = 0;
  }
  else if (numOfX == size)
  {
    result = 1;
  }

  //检查列

  if (result == -1)
  {
    for (j = 0; j < size && result == -1; j++)
    {
      numOfO = numOfX = 0;
      for (i = 0; i < size; i++)
      {
        if (board[i][j] == 1)
        {
          numOfX++;
        }
        else
        {
          numOfO++;
        }
      }
    }
    if (numOfO == size)
    {
      result = 0;
    }
    else if (numOfX == size)
    {
      result = 1;
    }
  }

  //检查对角线
  //正对角线
  numOfX = numOfO = 0;
  for (i = 0; i < size; i++)
  {
    if (board[i][i] == 1)
    {
      numOfX++;
    }
    else
    {
      numOfO++;
    }
  }
  if (numOfX == size)
  {
    result = 0;
  }
  else if (numOfO == size)
  {
    result = 1;
  }
  //反对角线
  numOfX = numOfO = 0;
  for (i = 0; i < size; i++)
  {
    if (board[i][size - i - 1] == 1)
    {
      numOfX++;
    }
    else
    {
      numOfX++;
    }
  }
  return 0;
}