#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int n, d[1000000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	qsort(d, n, sizeof(int), cmp);
	while(d[n-1]>=d[n-2]+d[n-3] && n>=3) n--;
	if(n<3) printf("-1");
	else printf("%d", d[n-1]+d[n-2]+d[n-3]);
}
