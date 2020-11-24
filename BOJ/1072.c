#include <stdio.h>

int main(){
	int n, m, cnt=0;
	scanf("%d %d", &n, &m);
	double x=100*(double)m/(double)n, y=100*(double)m/(double)n;
	if(n==m || (int)x==99){
		printf("-1");
		return 0;
	}
	int left=1, right=n, mid;
	while(left<right){
		mid=(left+right)/2;
		if((int)(100*(double)(m+mid)/(double)(n+mid))<(int)x+1) left=mid+1;
		else right=mid;
	}
	printf("%d", right);
}
