#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, d[10001], dp[10001], max=0;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &d[i]);
	dp[1]=d[1];
	dp[2]=d[1]+d[2];
	max=MAX(dp[1], dp[2]);
	for(int i=3;i<=n;i++){
		dp[i]=MAX(dp[i-3]+d[i]+d[i-1], dp[i-2]+d[i]);
		dp[i]=MAX(dp[i-1], dp[i]);
		max=MAX(max, dp[i]);
	}
	printf("%d", max);
}
