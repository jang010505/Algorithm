#include <stdio.h>
#include <stdlib.h>

int sort(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int main(){
	int n, m, a, d1[10000], d2[10000], cnt1=0, cnt2=0, res=0;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		if(a<0) d1[cnt1++]=a;
		else d2[cnt2++]=a;
	}
	qsort(d1, cnt1, sizeof(int), sort);
	qsort(d2, cnt2, sizeof(int), sort);
	if(d1[0]*-1>d2[cnt2-1]){
		int i=cnt2-1;
		while(i>=0){
			res+=d2[i]*2;
			i-=m;
		}
		i=m;
		res+=d1[0]*-1;
		while(i<cnt1){
			res+=d1[i]*-2;
			i+=m;
		}
		printf("%d", res);
		return 0;
	}
	else{
		int i=0;
		while(i<cnt1){
			res+=d1[i]*-2;
			i+=m;
		}
		i=cnt2-1;
		res+=d2[i];
		i-=m;
		while(i>=0){
			res+=d2[i]*2;
			i-=m;
		}
		printf("%d", res);
		return 0;
	}
} 
