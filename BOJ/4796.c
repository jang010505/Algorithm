#include <stdio.h>

int main(){
	int a, b, c, i=1;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if(!a && !b && !c) return 0;
		if(c%b>a) printf("Case %d: %d\n", i++, (c/b)*a+a);
		else printf("Case %d: %d\n", i++, (c/b)*a+c%b);
	}
}
