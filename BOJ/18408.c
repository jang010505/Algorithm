#include<stdio.h>

int main(void){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a+b+c>4) printf("2");
	else printf("1");
	return 0;
}
