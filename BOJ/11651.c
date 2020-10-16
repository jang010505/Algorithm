#include <stdio.h>
#include<stdlib.h>
int f(const int (*a)[], const int (*b)[]){
	if((*a)[1]==(*b)[1]) return (*a)[0]>(*b)[0] ? 1:((*a)[0]<(*b)[0] ? -1:0);
	else return (*a)[1]>(*b)[1] ? 1:((*a)[1]<(*b)[1] ? -1:0);
}
int main(){
	int i, n, d[100000][2];
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d %d", &d[i][0], &d[i][1]);
	qsort(d, n, 8, f);
	for(i=0;i<n;i++) printf("%d %d\n", d[i][0], d[i][1]);
}
