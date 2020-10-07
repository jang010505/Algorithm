#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", (a-c-1)/(b-c)+1);
}
