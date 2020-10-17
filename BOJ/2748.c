#include <stdio.h>
long long int d[100]={0, 1, 1,};
long long int f(int i){
	if(d[i]!=0) return d[i];
	d[i]=f(i-1)+f(i-2);
	return d[i];
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", f(n));
}
