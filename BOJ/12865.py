#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, d[101][2], dp[101][100001]={};

int main(){
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
		scanf("%d %d", &d[i][0], &d[i][1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j>=d[i][0])
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-d[i][0]]+d[i][1]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d", dp[n][k]);
}
