#include <stdio.h>
int d[200001];
int main(){
	int n, x, k;
	scanf("%d %d %d", &n, &x, &k);
	d[x]=1;
	for(int i=0;i<k;i++){
		int a, b, tmp;
		scanf("%d %d", &a, &b);
		tmp=d[a];
		d[a]=d[b];
		d[b]=tmp;
	}
	for(int i=1;i<=n;i++)
		if(d[i]==1) printf("%d", i);
}
