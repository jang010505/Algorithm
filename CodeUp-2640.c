#include <stdio.h>

int main(){
	long long int n, k, i, x, d[100];
	scanf("%d %d", &n, &k);
	x=n;
	for(i=0;k!=1;i++){
		if(k%2) d[i]=1;
		else d[i]=0;
		k/=2;
	}
	i--;
	for(;i>=0;i--){
		if(d[i]){
			x*=x;
			x%=1000000007;
			x*=n;
			x%=1000000007;
		}
		else{
			x*=x;
			x%=1000000007;
		}
	}
	printf("%lld", x);
}
