#include <stdio.h>
#include <stdlib.h>
long long int n, t, res=0, x[500000]={};
int f(const void *a, const void *b){
	if(*(long long int*)a>*(long long int*)b) return 1;
	else if(*(long long int*)a<*(long long int*)b) return -1;
	else return 0;
}
int main(){
	scanf("%lld %lld", &n, &t);
	for(int i=0;i<n;i++){
		long long int a, b;
		scanf("%lld %lld", &a, &b);
		x[i]=b;
		res+=a;
	}
	qsort(x, n, sizeof(long long int), f);
	for(int i=0;i<n;i++){
		res+=(t-i-1)*x[n-i-1];
	}
	printf("%lld", res);
}
