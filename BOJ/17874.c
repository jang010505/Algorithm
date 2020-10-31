#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a-b>b) b=a-b;
	if(a-c>c) c=a-c;
	printf("%d", b*c*4);
}
