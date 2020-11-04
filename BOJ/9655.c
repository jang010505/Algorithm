#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	if(n>4) n-=4;
	if(n%2) printf("SK");
	else printf("CY"); 
}
