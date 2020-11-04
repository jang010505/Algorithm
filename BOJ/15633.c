#include <stdio.h>
#include <math.h>

int main(){
	int n, res=0;
	scanf("%d", &n);
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(n/i!=i) res+=n/i;
			res+=i;
		}
	}
	printf("%d", res*5-24);
}
