#include <stdio.h>
#include <math.h>
unsigned long long int d[100001];
int f(int x){
	if(d[x]!=0) return d[x]%2000000000;
	d[x]=(f(x-1)+f(x-2))%2000000000;
	return d[x]%2000000000;
}
int main(){
	int n;
	d[0]=0, d[1]=1, d[2]=1;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i+1, f(a)%b);
	}
} 
