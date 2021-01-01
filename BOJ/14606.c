#include <stdio.h>

int main(){
	int n, dp[11]={};
	scanf("%d", &n);
	dp[0]=0;
	dp[1]=0;
	for(int i=1;i<=n;i++){
		if(i%2)
			dp[i]+=(i/2)*(1+i/2)+dp[i/2]+dp[i/2+1];
		else
			dp[i]+=(i/2)*(i/2)+dp[i/2]*2;
	}
	printf("%d", dp[n]);
}
