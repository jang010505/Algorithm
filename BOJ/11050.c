#include <stdio.h>

int main(){
	long long int n, m, res=1;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++) res=res*(n-i)/(i+1);
	printf("%lld", res);
}
