#include <stdio.h>
long long int dp[100001][3], n, a;
int main(){
	dp[1][0]=dp[2][1]=dp[3][0]=dp[3][1]=dp[3][2]=1;
	for(int i=4;i<=100000;i++){
		dp[i][0]=(dp[i-1][1]+dp[i-1][2])%1000000009;
      dp[i][1]=(dp[i-2][0]+dp[i-2][2])%1000000009;
      dp[i][2]=(dp[i-3][0]+dp[i-3][1])%1000000009;
	}
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		printf("%d\n", (dp[a][0]+dp[a][1]+dp[a][2])%1000000009);
	}
}
