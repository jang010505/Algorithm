#include <stdio.h>
#include <stdlib.h>

int f(const void* x, const void* y){
	if(*(int*)x>*(int*)y) return 1;
	else if (*(int*)x<*(int*)y) return -1;
    else return 0;
}
int main(){
	int n, d[100001], res, cnt=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	scanf("%d", &res);
	qsort(d, n, sizeof(int), f);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(d[i]+d[j]>res) break;
			else if(d[i]+d[j]==res){
				cnt++;
				break;
			}
		}
	}
	printf("%d", cnt);
}
