#include <stdio.h>

long long int d[100]={0, 1, 1, };
long long int f(int n){
	if(d[n]) return d[n];
	if(n>1) d[n]=f(n-1)+f(n-2);
	return d[n];
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", 4*f(n)+2*f(n-1));
}
