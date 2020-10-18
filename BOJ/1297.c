#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	double d=sqrt(b*b+c*c), x1, x2;
	x1=a*b/d;
	x2=a*c/d;
	printf("%d %d", (int)x1, (int)x2);
}
