#include <stdio.h>

int main(){
	int n;
	scanf("%lld", &n);
	for(int i=1;i<=n;i++)
		if(30%(i+1)==0)
			printf("%d\n", i);
}
