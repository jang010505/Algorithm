#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, dp[2001], d[2001], max=0;
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &d[i]);
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(d[i]<d[j])
				dp[i]=MAX(dp[i], dp[j]+1);
		}
		max=MAX(max, dp[i]);
	}
	printf("%d", n-max);
}
