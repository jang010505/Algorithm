#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, dp[1000001], d[1000001], max=0;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	for(int i=0;i<n;i++)
		dp[d[i]]=MAX(dp[d[i]], dp[d[i]-1]+1);
	for(int i=0;i<n;i++)
		max=MAX(max, dp[d[i]]);
	printf("%d", max);
}
