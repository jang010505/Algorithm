#include <stdio.h>

int main(){
	int a, res1=0, res2=0, i;
	for(i=0;i<6;i++){
		scanf("%d", &a);
		if(i<3) res1+=a*(3-i%3);
		else res2+=a*(3-i%3);
	}
	if(res1<res2) printf("B");
	else if(res1>res2) printf("A");
	else printf("T");
}
