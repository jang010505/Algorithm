#include <stdio.h>
int d[100]={1, 1, 2, };
int f(int a){
	if(d[a]!=0) return d[a];
	d[a]=f(a-1)+f(a-2)+f(a-3);
	return d[a];
}
int main(){
	int n, a;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		printf("%d\n", f(a));
	}
}
