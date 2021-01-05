#include <stdio.h>

int main(){
	int n, dp[31]={};
	scanf("%d", &n);
	dp[2]=3;
	for(int i=4;i<=n;i+=2){
		dp[i]=dp[i-2]*3+2;
		for(int j=4;j<i;j+=2){
			dp[i]+=dp[i-j]*2;
		}
	}
	printf("%d", dp[n]);
}
