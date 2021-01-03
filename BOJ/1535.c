#include <stdio.h>
#define max(a,b) a>b ? a : b
int n, d[21][2], dp[21][101];
int f(int a, int b){
	if(dp[a][b]) return dp[a][b];
	if(a>=n) return 0;
	dp[a][b]=b-d[a][0]>0 ? max(f(a+1, b-d[a][0])+d[a][1], f(a+1, b)) : max(dp[a][b], f(a+1, b));
	return dp[a][b];
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i][0]);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i][1]);
	printf("%d", f(0, 100));
}
