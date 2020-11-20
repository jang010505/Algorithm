#include <stdio.h>
#include <string.h>
#include <string.h>
long long int n, m, d[1000000], max=-1, res=0, left=0, right, mid, ans=0;
int main(){
	scanf("%lld %lld", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%lld", &d[i]);
		if(max<d[i]) max=d[i];
	}
	right=max;
	while(left<=right){
		mid=(left+right)/2;
		res=0;
		for(int i=0;i<n;i++) if(mid<d[i]) res+=d[i]-mid;
		if(res>=m){
			if(ans<mid) ans=mid;
			left=mid+1;
		}
		else right=mid-1;
	}
	printf("%lld", ans);
}
