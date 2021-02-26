
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, d[200001], MAX=0, dp[200001]={};
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
			scanf("%d", &d[i]);
		for(int i=n;i>0;i--){
			if(i+d[i]>n)
				dp[i]=d[i];
			else
				dp[i]=dp[i+d[i]]+d[i];
			MAX=max(MAX, dp[i]);
		}
		printf("%d\n", MAX);
	}
}
