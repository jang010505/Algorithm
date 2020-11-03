#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, k, d[10], cnt=0;
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	for(int i=n-1;i>=0;i--){
		cnt+=k/d[i];
		k%=d[i];
	}
	printf("%d", cnt);
}
