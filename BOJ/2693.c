#include <stdio.h>
#include <stdlib.h>

int f(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		int a[10];
		for(j=0;j<10;j++) scanf("%d", &a[j]);
		qsort(a, 10, sizeof(int), f);
		printf("%d\n", a[7]);
	}
}
