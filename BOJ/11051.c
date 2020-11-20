#include <stdio.h>
int d[1001][1001]={};
long long int f(long long int n, long long int m){
	if(m==0 || n==m){
		d[n][m]=1;
		return d[n][m]%10007;
	}
	if(d[n][m]!=0) return d[n][m]%10007;
	d[n][m]=(f(n-1, m-1)+f(n-1, m))%10007;
	return d[n][m]%10007;
}
int main(){
	long long int n, m, res;
	scanf("%lld %lld", &n, &m);
	d[1][1]=1;
	d[1][0]=1;
	res=f(n, m);
	printf("%lld", res);
}
