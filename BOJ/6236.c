#include <stdio.h>
int n, m, d[100000], sum=0, max=0;
int sol(int x){
	int cnt=1, res=0;
	for(int i=0;i<n;i++){
		if(res+d[i]>x){
			cnt++;
			res=d[i];
		}
		else res+=d[i];
	}
	return cnt;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &d[i]);
		sum+=d[i];
		if(max<d[i]) max=d[i];
	}
	int left=max, right=sum, mid;
	while(left<right){
		mid=(left+right)/2;
		int z=sol(mid);
		if(z>m) left=mid+1;
		else right=mid;
	}
	printf("%d", right);
}
