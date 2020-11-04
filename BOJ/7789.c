#include <stdio.h>
#include <math.h>

int main(){
	int n, d;
	scanf("%d %d", &n, &d);
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			printf("No");
			return 0;
		}
	}
	n+=d*1000000;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}
