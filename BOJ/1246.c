#include <stdio.h>
#include <stdlib.h>
int f(const void *a, const void *b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	int n, m, d[10000], max=0, res=0;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++) scanf("%d", &d[i]);
	qsort(d, m, sizeof(int), f);
	if(n>=m){
		for(int i=0;i<m;i++){
			if(d[i]*(m-i)>max){
				max=d[i]*(m-i);
				res=d[i];
			}
		}
	}
	else{
		for(int i=m-n;i<m;i++){
			if(d[i]*(m-i)>max){
				max=d[i]*(m-i);
				res=d[i];
			}
		}
	}
	printf("%d %d", res, max);
}
