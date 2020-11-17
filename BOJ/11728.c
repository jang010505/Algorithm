#include <stdio.h>
#include <stdlib.h>

int n, m, d[2000000];
int f(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n+m;i++) scanf("%d", &d[i]);
	qsort(d, n+m, sizeof(int), f);
	for(int i=0;i<n+m;i++) printf("%d ", d[i]);
}
