#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int main(){
	int n, dp[10000], d[10000], max=0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &d[i]);
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i;j++){
			if(d[j]<d[i]){
				dp[i]=MAX(dp[i], dp[j]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
		max=MAX(max, dp[i]);
	printf("%d", max);
}
