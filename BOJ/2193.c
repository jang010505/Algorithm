#include <stdio.h>
long long int d[200]={1,1}, n;

long long int f(int i){
	if(d[i]!=0) return d[i];
	d[i]=f(i-1)+f(i-2);
	return d[i];
}
int main(){
	scanf("%lld", &n);
	printf("%lld", f(n-1));
}
