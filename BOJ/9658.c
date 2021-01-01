#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int dp[1001];
	dp[1]=dp[3]=0;
	dp[2]=dp[4]=1;
	for(int i=5;i<=n;i++){
		if(dp[i-1]==1 && dp[i-3]==1 && dp[i-4]==1)
			dp[i]=0;
		else
			dp[i]=1;
	}
   if(dp[n])
   	printf("SK");
   else
   	printf("CY");
}
