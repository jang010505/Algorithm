#include <stdio.h>
#define MIN(x, y) (x<y ? x:y)
int main(){
	int n, dp[300001]={}, d1[10000]={}, d2[10000]={};
	d2[1]=1;
	d1[1]=1;
	for(int i=2;i<126;i++){
		d2[i]+=1;
		d1[i]=d1[i-1]+i;
		for(int j=i;j<126;j++){
			d2[j]+=d1[i];
		}
	}
	for(int i=0;i<=300000;i++)
		dp[i]=300000;
	scanf("%d", &n);
	dp[0]=0;
	for(int i=1;i<126;i++){
		for(int j=d2[i];j<=n;j++){
			if(dp[j-d2[i]]!=300000){
				dp[j]=MIN(dp[j], dp[j-d2[i]]+1);
			}
		}
	}
	printf("%d", dp[n]);
}
