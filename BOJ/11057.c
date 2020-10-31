#include <stdio.h>
#include <math.h>
int d[1001][11]={};
int f(int n, int m){
	if(d[n][m]!=0){
		return d[n][m]%10007;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<=i;j++){
			d[n][i]=(d[n][i]+f(n-1, j))%10007;
		}
	}
	for(int i=0;i<10;i++) d[n][10]+=d[n][i];
	return d[n][m]%10007;
}
int main(){
	int n;
	scanf("%d", &n);
	if(n==1){
		printf("10");
		return 0;
	}
	for(int i=0;i<10;i++) d[1][i]=1;
	printf("%d", f(n, 10));
	return 0;
}
