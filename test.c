

// #include <stdio.h>
// int main()
// {
//   int a;
//   int cnt = 0;
//   scanf("%d", &a);
//   int i, j, k;
//   i = a;
//   for (i = a; i <= a + 3; i++)
//   {
//     for (j = a; j <= a + 3; j++)
//     {
//       for (k = a; k <= a + 3; k++)
//       {
//         if (i != j)
//         {
//           if (i != k)
//           {
//             if (j != k)
//             {
//               cnt++;
//               printf("%d", i * 100 + j * 10 + k);
//               if (cnt == 6)
//               {
//                 printf("\n");
//                 cnt = 0;
//               }
//               else
//               {
//                 printf(" ");
//               }
//             }
//           }
//         }
//       }
//     }
//   }
//   printf("\n");
//   return 0;
// }

// #include <stdio.h>
// int main()
// {
//   int a;
//   int cnt = 0;
//   scanf("%d", &a);
//   int i, j, k;
//   for (i = a; i <= a + 3; i++)
//   {
//     for (j = a; j <= a + 3; j++)
//     {
//       for (k = a; k <= a + 3; k++)
//       {
//         if (i != j && i != k && j != k)
//         {
//           cnt++;
//           printf("%d%d%d", i, j, k);
//           if (cnt == 6)
//           {
//             printf("\n");
//             cnt = 0;
//           }
//           else
//           {
//             printf(" ");
//           }
//         }
//       }
//     }
//   }
//   printf("\n");
//   return 0;
// }
#include <stdio.h>
#define number 100
int main()
{
  // const int number = 100;
  int prime[number] = {2};
  printf("%d\n", prime[0]);
  return 0;
}