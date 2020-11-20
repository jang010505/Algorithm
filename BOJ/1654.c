#include <stdio.h>

int main(){
	long long int n, m, d[10000], maxt=0, max=0;
	scanf("%lld %lld", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%lld", &d[i]);
		if(maxt<d[i]) maxt=d[i];
	}
	long long int left=1, right=maxt, mid, res;
	while(left<=right){
		res=0;
		mid=(left+right)/2;
		for(int i=0;i<n;i++) res+=d[i]/mid;
		if(res>=m){
			if(max<=mid) max=mid;
			left=mid+1;
		}
		else right=mid-1;
	}
	printf("%lld", max);
}
