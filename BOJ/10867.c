#include <stdio.h>
#include <stdlib.h>

int n, d[100000];
int f(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &d[i]);
	}
	qsort(d, n, sizeof(int), f);
	for(int i=0;i<n;i++){
		while(d[i]==d[i+1]) i++;
		printf ("%d ", d[i]);
	}
}
