#include <stdio.h>
char s[1000001];
int main(){
	int n, d[1005], dp[1005];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	dp[0]=d[0];
	int ans=dp[0];
	for(int i=1;i<n;i++){
		dp[i]=d[i];
		for(int j=0;j<i;j++){
			if(d[j]<d[i]){
				if(dp[i]<dp[j]+d[i])
					dp[i]=dp[j]+d[i];
			}
		}
		if(ans<dp[i])
			ans=dp[i];
	}
	printf("%d", ans);
}
