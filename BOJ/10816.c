#include <stdio.h>
#include <stdlib.h>

int d[500001];
int lb(int x, int y){
	int left=0, right=x-1, mid;
	while(left<right){
		mid=(left+right)/2;
		if(d[mid]>=y) right=mid;
		else left=mid+1;
	}
	return right;
}
int ub(int x, int y){
	int left=0, right=x-1, mid;
	while(left<right){
		mid=(left+right)/2;
		if(d[mid]>y) right=mid;
		else left=mid+1;
	}
	return right;
}
int f(const void*x, const void *y){
	if(*(int*)x>*(int*)y) return 1;
	else if(*(int*)x<*(int*)y) return -1;
	else return 0;
}
int main(){
	int n, a, m;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	qsort(d, n, sizeof(int), f);
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d", &a);
		int x=lb(n, a), y=ub(n, a);
		if(y==n-1 && d[n-1]==a) y++;
		if(d[x]==a) printf("%d ", y-x);
		else printf("0 ");
	}
}
