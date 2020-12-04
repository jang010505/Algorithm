#include <stdio.h>

int f(long long int x){
	
	for(long long int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int main(){
	long long int n, a;
	scanf("%lld", &n);
	for(long long int i=0;i<n;i++){
		scanf("%lld", &a);
		for(long long int j=a;j<=5000000000;j++){
			if(j==1 || j==0){
				printf("2\n");
				break;
			}
			if(f(j)){
				printf("%lld\n", j);
				break;
			}
		}
	}
}
