#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a+b+c>=100) printf("OK");
	else{
		if(a>b && c>b) printf("Korea");
		if(a>c && b>c) printf("Hanyang");
		if(c>a && b>a) printf("Soongsil");
	}
}
