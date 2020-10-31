#include <stdio.h>
#include <math.h>
int d[20005]={0, 1, 3};
int f(int n){
	if(d[n]!=0) return d[n]%10007;
	d[n]=f(n-2)*2+f(n-1);
	return d[n]%10007;
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d", f(n)); 
	return 0;
}
