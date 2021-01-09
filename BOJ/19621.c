#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, d[26][3], dp[10001], max=0;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d", &d[i][0], &d[i][1], &d[i][2]);
	dp[1]=d[1][2];
	dp[2]=d[2][2];
	dp[3]=d[1][2]+d[3][2];
	max=MAX(dp[1], dp[2]);
	max=MAX(max, dp[3]);
	for(int i=4;i<=n;i++){
		dp[i]=MAX(dp[i-2]+d[i][2], dp[i-3]+d[i][2]);
		max=MAX(max, dp[i]);
	}
	printf("%d", max);
}
