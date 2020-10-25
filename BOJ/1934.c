#include <stdio.h>

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
int main(){
	int n, a, b, i, res;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &a, &b);
		res=gcd(a, b);
		printf("%d\n", a*b/res);
	}
}
