#include <stdio.h>
#include <stdlib.h>
int s[1000000];
int static f(const void *a, const void *b){
	if(*(int*)a>*(int*)b) return 1;
	if(*(int*)a<*(int*)b) return -1;
	return 0;
}
int main(){
	int i, j, k, s[10], sum=0;
	for(i=0;i<9;i++){
		scanf("%d", &s[i]);
		sum+=s[i];
	}
	for(i=0;i<8;i++){
		for(j=i+1;j<9;j++){
			if(sum-s[i]-s[j]==100){
				s[i]=-1;
				s[j]=-1;
				qsort(s, 9, sizeof(int), f);
				for(k=2;k<9;k++) printf("%d\n", s[k]);
				return 0;
			}
		}
	}
}
