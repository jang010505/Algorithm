#include <stdio.h>
int d[10000001]={1, 1};
int main(){
	int n=1;
	for(int i=2;i*i<=1000000;i++){
		if(d[i]==1) continue;
		for(int j=i;j*i<=1000000;j++) d[i*j]=1;
	}
	while(n){
		scanf("%d", &n);
		if(n){
			for(int i=2;;i++){
				if(d[i]==0 && d[n-i]==0){
					printf("%d = %d + %d\n", n, i, n-i);
					break;
				}
			}
		}
	}
}
