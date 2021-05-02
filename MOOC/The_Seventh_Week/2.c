#include <stdio.h>
int isPrime(int x, int knownPrimes[], int numberOfKonownPrimes);
int main()
{

  const int number = 100;
  int prime[100] = {2};
  int count = 1;
  int i = 3;
  while (count < number)
  {
    if (isPrime(i, prime, count))
    {
      prime[count++] = i;
    }
    i++;
  }
  for (i = 0; i < number; i++)
  {
    printf("%d", prime[i]);
    if ((i + 1) % 5)
      printf("\t");
    else
      printf("\t");
  }
  printf("------------------------------");
  const int maxNumber = 25;
  int isPrime[25];
  int j;
  int x;
  for (j = 0; j < maxNumber; j++)
  {
    isPrime[i] = 1;
  }
  for (x = 2; x < maxNumber; x++)
  {
    if (isPrime[x])
    {
      for (j = 2; j * x < maxNumber; j++)
      {
        isPrime[j * x] = 0;
      }
    }
  }
  for (j = 2; i < maxNumber; j++)
  {
    if (isPrime[i])
    {
      printf("%d\t", j);
    }
  }
  printf("\n");

  return 0;
}
int isPrime(int x, int knownPrimes[], int numberOfKonownPrimes)
{
  int ret = 1;
  int i;
  for (i = 0; i < numberOfKonownPrimes; i++)
  {
    if (x % knownPrimes[i] == 0)
    {
      ret = 0;
      break;
    }
  }
  return ret;
}