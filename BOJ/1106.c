#include <stdio.h>

int main(){
	int c, n, dp[2000]={}, min=1000000000;
	scanf("%d %d", &c, &n);
	for(int i=0;i<2000;i++)
		dp[i]=1000000000;
	dp[0]=0;
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		for(int j=b;j<2000;j++){
			if(dp[j]>dp[j-b]+a)
				dp[j]=dp[j-b]+a;
		}
	}
	for(int i=c;i<2000;i++)
		if(dp[i]<min)
			min=dp[i];
	printf("%d", min);
}
