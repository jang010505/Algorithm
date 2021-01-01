#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	while(n!=0){
		int d[250000], dp[250000];
		for(int i=0;i<n;i++)
			scanf("%d", &d[i]);
		dp[0]=d[0];
		for(int i=1;i<n;i++){
			if(d[i]<dp[i-1]+d[i])
				dp[i]=dp[i-1]+d[i];
			else
				dp[i]=d[i];
		}
		int max=-2100000000;
		for(int i=0;i<n;i++)
			if(dp[i]>max)
				max=dp[i];
		printf("%d\n", max);
		scanf("%d", &n);
	}
}
