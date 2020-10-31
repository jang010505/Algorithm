#include <stdio.h>

int main(){
	int a;
	scanf("%d", &a);
	if(a%2==1){
		printf("0");
		return 0;
	}
	a/=2;
	if(a%2) printf("1");
	else printf("2");
}
