#include <stdio.h>
#include <stdlib.h>

int d[100001];
int g(int x, int y){
	int left=0, right=x-1, mid;
	while(left<=right){
		mid=(left+right)/2;
		if(d[mid]==y){
			printf("1\n");
			return 0;
		}
		else if(d[mid]<y) left=mid+1;
		else right=mid-1;
	}
	printf("0\n");
	return 0;
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
		g(n, a);
	}
}
