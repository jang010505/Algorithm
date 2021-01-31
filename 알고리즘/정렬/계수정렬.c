#include <stdio.h>

int main(){
	int n, m, d[1000], cnt[1000]={};
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	for(int i=0;i<n;i++) cnt[d[i]]++;
	for(int i=1;i<=m;i++){
		for(int j=0;j<cnt[i];j++) printf("%d ", i);
	}
}
