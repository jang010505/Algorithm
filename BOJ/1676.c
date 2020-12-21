#include <stdio.h>

int main(){
   int two=0, five=0, n;
   scanf("%d", &n);
   for(int i=2;i<=n;i*=2) two+=n/i;
   for(int i=5;i<=n;i*=5) five+=n/i;
   printf("%d", two<five ? two:five);
   return 0;
}
