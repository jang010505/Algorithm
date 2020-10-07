#include <stdio.h>

int main(){
	int a, b, c, d, e, z=1;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if(a+b==c){
		printf("%d ", d+e);
		z=0;
	}
	if(a-b==c){
		printf("%d ", d-e);
		z=0;
	}
	if(a*b==c){
		printf("%d", d*e);
		z=0;
	}
	if(a/b==c){
		printf("%d", d/e);
		z=0;
	}
	if(z) printf("NO");
	return 0;
}
