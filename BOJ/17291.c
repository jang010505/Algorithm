#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, dp[21];
int main(){
	scanf("%d", &n);
	dp[1]=1;
	dp[4]=-1;
	for(int i=2;i<=n;i++){
		if(i%2){
			dp[i]+=2*dp[i-1];
			dp[i+3]-=dp[i-1];
		}
		else{
			dp[i]+=2*dp[i-1];
			dp[i+4]-=dp[i-1];
		}
	}
	printf("%d", dp[n]);
}
