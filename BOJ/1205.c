#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return -1;
	else if(*(int*)a<*(int*)b) return 1;
	return 0;
}
int main(){
	int n, x, p, d[1000];
	scanf("%d %d %d", &n, &x, &p);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	d[n]=x;
	qsort(d, n+1, sizeof(int), cmp);
	for(int i=0;i<=n;i++){
		if(d[i]==x){
			int I=i;
			while(i<n && d[i]==d[i+1]) i++;
			if(i+1>p) printf("-1");
			else printf("%d", I+1);
			return 0;
		}
	}
}
