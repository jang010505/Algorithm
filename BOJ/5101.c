#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if(a==b && b==c && a==0) break;
		if(c==a && b==0) printf("1");
		else if((c-a)%b==0 && b>0 && a<c) printf("%d\n", (c-a)/b+1);
		else if((c-a)%b==0 && b<0 && a>c) printf("%d\n", (c-a)/b+1);
		else printf("X\n");
	}
}
