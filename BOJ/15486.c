#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int t[1500000], p[1500000], dp[1500000];
int main(){
	int n, max=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d", &t[i], &p[i]);
		dp[i]=p[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+t[i];j<i+t[i+t[i]]+t[i] && j<=n;j++){
			dp[j]=MAX(p[j]+dp[i], dp[j]);
		}
	}
	for(int i=0;i<n;i++)
		if(i+t[i]<=n)
			max=MAX(max, dp[i]);
	printf("%d", max);
	return 0;
}
