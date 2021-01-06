#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int n, dp[1001], d[1000], max=0;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	for(int i=0;i<n;i++){
		dp[i]+=d[i];
		for(int j=0;j<i;j++){
			if(d[i]>d[j]){
				dp[i]=MAX(dp[i], dp[j]+d[i]);
			}
		}
	}
	for(int i=0;i<n;i++)
		max=MAX(max, dp[i]);
	printf("%d", max);
}
