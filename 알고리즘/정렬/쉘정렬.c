#include <stdio.h>

void intervalSort(int d[], int left, int right, int interval){
   for(int i=left+interval;i<=right;i+=interval){
      int temp=d[i];
      int j;
      for(j=i-interval;j>=left;j-=interval){
         if(d[j]>temp)
				d[j+interval]=d[j];
         else
				break;
      }
      d[j+interval]=temp;
   }
   return;
}
void shellSort(int d[], int n){
    for(int interval=n/2;interval>0;interval/=2){
      if((interval%2)==0)
			interval++;
      for(int i=0;i<interval;i++)
         intervalSort(d, i, n-1, interval);
   }
}
void print(int d[], int n){
	for(int i=0;i<n;i++)
		printf("%d ", d[i]);
	return;
}
int main(){
	int d[100001], n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	shellSort(d, n);
	print(d, n);
	return 0;
}
