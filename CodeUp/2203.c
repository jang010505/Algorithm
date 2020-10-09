#include <stdio.h>
long long int f(long long int x){
	for(long long int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	long long int n, i, max=-1, N;
	scanf("%lld", &n);
	if(f(n)){
	    printf("%lld", n);
	    return 0;
	}
	for(i=1;i*i<=n;i++){
		if(n%i==0){
		    N=n;
			while(N%i==0 && i!=1) N/=i;
			if(f(i)){
				if(max<i) max=i;
			}
			if(f(N)){
				if(max<N) max=N;
			}
		}
	}
	printf("%lld", max);
}
