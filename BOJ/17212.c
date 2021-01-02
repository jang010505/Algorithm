#include <stdio.h>
#define min(a, b) (a<b ? a:b) 

int dp[100001], n;
int main(){
	dp[0]=0;
	dp[1]=dp[2]=dp[5]=dp[7]=1;
	dp[3]=dp[4]=dp[6]=2;
	for(int i=8;i<=100000;i++){
		if(i%7){
			dp[i]=min(dp[i-5], min(dp[i-2], dp[i-1]))+1;
		}
		else
			dp[i]=i/7;
	}
	scanf("%d", &n);
	printf("%d", dp[n]);
}
