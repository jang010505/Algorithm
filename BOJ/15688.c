#include <stdio.h>
#include <stdlib.h>
int d[1000005];
int f(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d", &d[i]);
	qsort(d, n, sizeof(int), f);
	for(i=0;i<n;i++){
		printf("%d\n", d[i]);
	}
}
