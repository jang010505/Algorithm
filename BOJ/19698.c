#include<stdio.h>

int main(void){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if((b/d)*(c/d)<=a) printf("%d", (b/d)*(c/d));
	else printf("%d", a);
}
