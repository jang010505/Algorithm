#include <stdio.h>
#include <stdlib.h>
int f(const void *a, const void *b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	int n, m, d[10000], res=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	scanf("%d", &m);
	qsort(d, n, sizeof(int), f);
	if(d[0]>m){
		for(int j=1;j<m;j++){
			res+=d[0]-m;
		}
		res+=d[0]-m-1;
		printf("%d", res);
		return 0;
	}
	if(d[n-1]==m){
		printf("0");
		return 0;
	}
	for(int i=0;i<n-1;i++){
		if(d[i]==m || d[i+1]==m || (d[i]+1==m && m+1==d[i+1])){
			printf("0");
			return 0;
		}
		else if(d[i]<m && m<d[i+1]){
			for(int j=d[i]+1;j<m;j++){
				res+=d[i+1]-m;
			}
			res+=d[i+1]-m-1;
			printf("%d", res);
			return 0;
		}
	}
} 	
