#include <stdio.h>

int main(){
	int n, k, d[50001]={}, cnt=0, j;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++) d[i]=i;
	j=k;
	printf("<");
	while(1){
		if(cnt!=n-1) printf("%d, ", d[j]);
		else printf("%d", d[j]);
		d[j]=0;
		cnt++;
		if(cnt==n){
			printf(">");
			return 0;
		}
		int cnt1=0;
		for(;cnt1<k;){
			j++;
			if(j>n) j-=n;
			if(d[j]) cnt1++;
		}
	}
}
