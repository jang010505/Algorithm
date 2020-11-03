#include <stdio.h>
#include <stdlib.h>

int f(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	int n, l, d[1000], cnt=1, x=0;
	scanf("%d %d", &n, &l);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	qsort(d, n, sizeof(int), f);
	for(int i=0;i<n-1;i++){
		x+=d[i+1]-d[i];
		if(x+1>l){
			x=0;
			cnt++;
		}
	}
	printf("%d", cnt);
}
