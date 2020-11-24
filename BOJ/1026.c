#include <stdio.h>
#include <stdlib.h>
int f(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	int n, a[100], b[100], res=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(int i=0;i<n;i++) scanf("%d", &b[i]);
	qsort(b, n, sizeof(int), f);
	qsort(a, n, sizeof(int), f);
	for(int i=0;i<n;i++) res+=a[i]*b[n-i-1];
	printf("%d", res);
}
