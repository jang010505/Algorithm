#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, dp[100001][3], max=0;
int main(){
	int n;
	scanf("%d", &n);
	dp[1][0]=1;
	dp[1][1]=1;
	dp[1][2]=1;
	for(int i=2;i<=n;i++){
		dp[i][0]=(dp[i-1][1]+dp[i-1][2])%9901;
		dp[i][1]=(dp[i-1][0]+dp[i-1][2])%9901;
		dp[i][2]=(dp[i-1][1]+dp[i-1][0]+dp[i-1][2])%9901;
	}
	printf("%d", (dp[n][0]+dp[n][1]+dp[n][2])%9901);
}
