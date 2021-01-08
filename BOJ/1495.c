#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, s, m, d[101], dp[101][1001];
int main(){
	scanf("%d %d %d", &n, &s, &m);
	for(int i=1;i<=n;i++)
		scanf("%d", &d[i]);
	dp[0][s]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(dp[i-1][j]){
				if(j-d[i]>=0) dp[i][j-d[i]]=1;
				if(j+d[i]<=m) dp[i][j+d[i]]=1;
			}
		}
	}
	for(int i=m;i>=0;i--){
		if(dp[n][i]){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
