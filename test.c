

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
// #include <stdio.h>
// int main()
// {
//   // const int number = 100;
//   // int prime[number] = {2};
//   // printf("%d\n", prime[0]);
//   // return 0;

//   int a = 15, b = 99, c = 222;
//   int *p = &a;
//   *p = b;
//   c = *p;
//   printf("%d %d %d %d\n", a, b, c, *p);
// 
#include <stdio.h>
#include <string.h>

int main()
{
struct flower{
  char *name;
  char color[20];
  float average_radius; 
  float average_height;
  char season[20];
} Pflower;
struct flower f1;
struct flower f2;
struct flower f3;

  Pflower.name="red";
  printf("%s\n",Pflower.name);
  strcpy( f1.name, "rose");
  strcpy( f1.color, "red");
  strcpy( f1.season, "A"); 
  f1.average_radius=2.36;
  f1.average_height=32.15;


  // strcpy( f2.name, "chrysanthemum");
  // strcpy( f2.color, "yellow");
  // strcpy( f2.season, "F"); 
  f2.average_radius=4.79;
  f2.average_height=28.31;

  // strcpy( f3.name, "Peony");
  // strcpy( f3.color, "pink");
  // strcpy( f3.season, "S"); 
  f3.average_radius=3.61;
  f3.average_height=25.12;

  printf("%s\n",f3.name);
}