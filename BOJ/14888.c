#include <stdio.h>
#include <stdlib.h>
int n, x[11], a, b, c, d, min=2100000000, max=-2100000000;
int f(int m, int o, int p, int q, int r, int res){
	if(m==n){
		if(min>res) min=res;
		if(max<res) max=res;
		return 0;
	}
	if(o<a) f(m+1, o+1, p, q, r, res+x[m]);
	if(p<b) f(m+1, o, p+1, q, r, res-x[m]);
	if(q<c) f(m+1, o, p, q+1, r, res*x[m]);
	if(r<d) f(m+1, o, p, q, r+1, res/x[m]);
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &x[i]);
	}
	scanf("%d %d %d %d", &a, &b, &c, &d);
	f(1, 0, 0, 0, 0, x[0]);
	printf("%d\n%d", max, min);
}
