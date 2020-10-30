#include <stdio.h>
#include <stdlib.h>
int n, m, a[8], b[8], d[10];
int c(const void* x, const void* y){
	if(*(int*)x>*(int*)y) return 1;
	else if(*(int*)x<*(int*)y) return -1;
	else return 0;
}
int f(int x){
	if(x==m){
		for(int i=0;i<m-1;i++){
			if(a[i]>a[i+1]) return 0;
		}
		for(int i=0;i<m;i++) printf("%d ", a[i]);
		printf("\n");
	}
	else{
		int cnt=0;
		for(int i=0;i<n;i++){
			if(!b[i] && d[i]!=cnt){
				cnt=d[i];
				b[i]=1;
				a[x]=d[i];
				f(x+1);
				b[i]=0;
			}
		}
	}
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	qsort(d, n, sizeof(int), c);
	f(0);
}
