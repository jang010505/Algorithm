#include <stdio.h>
int d[50][50]={};
int f(int n, int m){
	if(m==1 || n==m) return 1;
	if(d[n][m]) return d[n][m];
	d[n][m]=f(n-1, m)+f(n-1, m-1);
	return d[n][m];
}
int main(){
	long long int r, c, w, res=0;
	d[1][1]=1, d[2][1]=1, d[2][2]=1;
	scanf("%d %d %d", &r, &c, &w);
	for(int i=0;i<w;i++){
		for(int j=0;j<=i;j++){
			res+=f(r+i, c+j);
		}
	}
	printf("%lld", res);
}
