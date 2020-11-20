#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f(const void *a, const void *b){
	if(*(int*)a>*(int*)b) return -1;
	else if(*(int*)a<*(int*)b) return 1;
	else return 0;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int m, k, x[50000], y[50000], z[50000], t, l=0, qf=0, qb;
		memset(x, 0, sizeof(int)*50000);
		memset(y, 0, sizeof(int)*50000);
		memset(z, 0, sizeof(int)*50000);
		scanf("%d %d", &m, &k);
		for(int j=0;j<m;j++){
			scanf("%d", &x[j]);
			y[j]=x[j];
			z[j]=j;
			if(k==j) t=x[j];
		}
		qb=m;
		qsort(x, m, sizeof(int), f);
		while(1){
			while(y[qf]!=x[l]){
				y[qb]=y[qf]; 
				z[qb++]=z[qf++];
			}
			if(t==x[l] && z[qf]==k){
				printf("%d\n", l+1);
				break;
			}
			qf++;
			l++;
		}
	}
}
