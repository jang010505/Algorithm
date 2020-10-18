#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c;
	scanf("%d %d", &a, &b);
	scanf("%d", &c);
	b+=c;
	a+=b/60;
	b%=60;
	a%=24;
	printf("%d %d", a, b);
}
