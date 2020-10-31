#include <stdio.h>

int main(){
	int a;
	scanf("%d", &a);
	if(a%8==1) printf("1");
	else if(a%8==2 || a%8==0) printf("2");
	else if(a%8==3 || a%8==7) printf("3");
	else if(a%8==4 || a%8==6) printf("4");
	else printf("5");
}
