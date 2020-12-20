#include <stdio.h>
#include <stdlib.h>

int f(const void *a, const void *b){
	if(*(int*)a<*(int*)b) return -1;
	else if(*(int*)a>*(int*)b) return 1;
	else return 0;
}
int main(){
	int n, d[1000], res=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	qsort(d, n, sizeof(int), f);
	for(int i=0;i<n;i++)
		res+=d[i]*(n-i);
	printf("%d", res);
}
