#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, dp[191230], a;
int main(){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=191229;i++)
		dp[i]=(dp[i-1]+dp[i-2])%1000000007;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		printf("%d\n", dp[a]);
	}
}
