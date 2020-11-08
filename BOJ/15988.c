#include <stdio.h>
long long int d[1000005]={1, 1, 2, };
long long int f(long long int a){
	if(d[a]!=0) return d[a];
	d[a]=(f(a-1)+f(a-2)+f(a-3))%1000000009;
	return d[a];
}
int main(){
	long long int n, a;
	scanf("%lld", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &a);
		printf("%lld\n", f(a));
	}
}
