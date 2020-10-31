#include<stdio.h>

int main(void){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a+b*2+c*3>=10) printf("happy");
	else printf("sad"); 
}
