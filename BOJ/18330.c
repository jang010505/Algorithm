#include<stdio.h>

int main(void){
	int a, b, res=0;
	scanf("%d %d", &a, &b);
	if(a-60<=b) res+=a*1500;
	else{
		if(a-b<=60) res+=a*1500;
		else{
			res+=(a-b-60)*3000;
			res+=(b+60)*1500;
		}
	}
	printf("%d", res);
	return 0;
}
