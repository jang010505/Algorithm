#include <stdio.h>
#include <stdlib.h>
int d[1000001], n;

int f(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return 1;
    else if(*(int*)a<*(int*)b) return -1;
    else return 0;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	qsort(d, n, sizeof(int), f);
	for(int i=0;i<n;i++)
		printf("%d\n", d[i]);
}
