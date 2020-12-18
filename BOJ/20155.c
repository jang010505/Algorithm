#include <stdio.h>
char s[1000001];
int main(){
	int n, m, d[1000]={}, x, max=0;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		d[x]++;
	}
	for(int i=0;i<n;i++){
		if(max<d[i]) max=d[i];
	}
	printf("%d", max);
}
