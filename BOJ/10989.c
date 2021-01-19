#include <stdio.h>

int main(){
	int d[10001]={}, n, a;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		d[a]++;
	}
	for(int i=1;i<=10000;i++)
		for(int j=0;j<d[i];j++)
			printf("%d\n", i);
}
