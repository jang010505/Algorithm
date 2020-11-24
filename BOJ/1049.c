#include <stdio.h>

int main(){
	int n, m, a, b, min1=1000, min2=1000;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d %d", &a, &b);
		if(min1>a) min1=a;
		if(min2>b) min2=b;
	}
	if(min1>min2*6) printf("%d", n*min2);
	else{
		if(n%6 > min1/min2) printf("%d", (n/6+1)*min1);
		else printf("%d", n/6*min1+n%6*min2);
	}
}
