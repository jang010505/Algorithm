#include <stdio.h>

int main(){
	int n, N;
	scanf("%d", &n);
	N=n;
	for(int i=2;i<=n;i++){
		while(N%i==0){
			N/=i;
			printf("%d\n", i);
		}
	}
	return 0;
}
