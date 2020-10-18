#include <stdio.h>
#include <math.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	if((a+b)%2 || a<b) printf("-1");
	else printf("%d %d", (a+b)/2, (a-b)/2);
}
