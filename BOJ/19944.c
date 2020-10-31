#include<stdio.h>

int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	if(b<3) printf("NEWBIE!");
	else if(b<=a) printf("OLDBIE!");
	else printf("TLE!");
}
