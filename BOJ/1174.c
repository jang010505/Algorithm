#include <stdio.h>
#include <stdlib.h>

long long int d[10000], n, cnt=0;

int cmp(const void* a, const void* b){
	if(*(long long int*)a>*(long long int*)b) return 1;
	else if(*(long long int*)a<*(long long int*)b) return -1;
	else return 0;
}
int f(long long int res, int x){
	d[cnt++]=res;
	for(int i=x;i>=0;i--) f(res*10+i, i-1);
}
int main(){
	scanf("%lld", &n);
	for(int i=9;i>=0;i--) f(i, i-1);
	qsort(d, cnt, sizeof(long long int), cmp);
	if(cnt<n) printf("-1");
	else printf("%lld", d[n-1]);
}
