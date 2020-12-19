#include <stdio.h>
#include <math.h>
int n, a, b, min=1000000000;
int f(int v, int z, int x, int y) {
	if(x==y){
		if(min>v-1) min=v-1;
		return 0;
	}
	int d=abs(y-x);
	if(x+z<=n){
		if(d%(z*2*2)==z*2 && y-z>0) f(v+1, z*2, x+z, y-z);
		if(d%(z*2*2)==0 && y+z<=n) f(v+1, z*2, x+z, y+z);
	}
	if(x-z>0){
		if(d%(z*2*2)==0 && y-z>0) f(v+1, z*2, x-z, y-z);
		if(d%(z*2*2)==z*2 && y+z<=n) f(v+1, z*2, x-z, y+z);
	}
}
int main() {
	scanf("%d %d %d", &n, &a, &b);
	f(1, 1, a, b);
	if(min>100000000) printf("-1");
	else printf("%d", min);
}
