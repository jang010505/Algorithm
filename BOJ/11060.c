#include <stdio.h>
#define MIN(x, y) (x<y ? x:y)
int n, dp[1000], d[1000];
int main(){
	for(int i=0;i<1000;i++)
		dp[i]=10000;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=d[i] && i+j<n;j++){
			dp[i+j]=MIN(dp[i+j], dp[i]+1);
		}
	}
	if(dp[n-1]!=10000) printf("%d", dp[n-1]);
	else printf("-1");
}
