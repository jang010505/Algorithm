#include <stdio.h>
long long int d[36];
int main(){
	int n;
	scanf("%d", &n);
	d[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			d[i]+=d[j]*d[i-j-1];
		}
	}
	printf("%lld", d[n]);
}
