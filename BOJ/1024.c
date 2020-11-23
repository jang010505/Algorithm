#include <stdio.h>

int main(){
	int n, l;
	scanf("%d %d", &n, &l);
	for(int i=l;i<=100;i++){
		int a, b;
		a=i/2+n/i;
		b=a+1-i;
		if(b<0) continue;
		if(a>n) continue;
		if(a*a+a-b*b+b==n*2){
			for(;b<=a;) printf("%d ", b++);
			return 0;
		}
	}
	printf("-1");
} 
