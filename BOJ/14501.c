#include <stdio.h>

int main(){
	int n, d[20][2], dp[21]={0, };
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d", &d[i][0], &d[i][1]);
		dp[i]=d[i][1];
	}
	for(int i=1;i<n;i++){
 		for(int j=0;j<i;j++){
         if(i-j>=d[j][0]){
         	if(dp[i]<d[i][1]+dp[j])
            	dp[i]=d[i][1]+dp[j];
         }
      }
	}
	int max=0;
	for(int i=0;i<n;i++){
      if(i+d[i][0]<=n){
         if(max<dp[i])
            max=dp[i];
      }
   }
   printf("%d", max);
}
