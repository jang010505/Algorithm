#include <stdio.h>
int fact(int x){
	if(x<2)
		return 1;
	else
		return fact(x-1)*x;
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d", fact(n));
	return 0;
}
