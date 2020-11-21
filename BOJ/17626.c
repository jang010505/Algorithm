#include <stdio.h>
#include <math.h>
int dp[500001]={}, n;
int f(int x){
	if(dp[x]!=5) return dp[x];
	int sq=sqrt(x);
	for(int i=sq;i>0;i--){
		if(dp[x]>f(x-i*i)+f(i*i)) dp[x]=f(x-i*i)+f(i*i);
	}
	return dp[x];
}
int main(){
	for(int i=2;i<50001;i++) dp[i]=5;
	for(int i=1;i<224;i++) dp[i*i]=1;
	dp[1]=1;
	scanf("%d", &n);
	printf("%d", f(n));
}
