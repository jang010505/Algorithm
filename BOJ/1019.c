#include <stdio.h>
#include <math.h>
int main()
{
   int N, i, j, k;
   int quo[10]; // 몫
   int rem[10]; // 나머지
   int cnt[10]; // 카운트

   for (i = 0;i < 10;i++)
   {
      quo[i] = 0;
      rem[i] = 0;
      cnt[i] = 0;
   }

   scanf("%d", &N);
   
   i = 0;
   while (N > 0)
   {
      quo[i] = N / 10;
      rem[i] = N % 10;
      N /= 10;
      i++;
   }
   i = 0;
   while (i<10 && !((quo[i] == 0) && (rem[i] == 0))) 
   {
      if (rem[i] == 0)
      {
         cnt[0] += ((quo[i] - 1) * pow(10, i));
         for (k = (i - 1);k >= 0;k--)
            cnt[0] += (rem[k] * pow(10, k));
         cnt[0]++;
      }

      else if(rem[i] > 0 && quo[i] != 0)
      {
         cnt[0] += (quo[i] * pow(10, i));
      }

      for (j = 1;j < 10;j++)
      {
         cnt[j] += (quo[i] * pow(10, i));
         if (rem[i] > j)
            cnt[j] += (pow(10, i));
         else if (rem[i] == j)
         {
            for (k = (i - 1);k >= 0;k--)
               cnt[j] += (rem[k] * pow(10, k));
            cnt[j]++;
         }
      }
      i++;
   }
   for (i = 0;i < 10;i++)
      printf("%d ", cnt[i]);
}
