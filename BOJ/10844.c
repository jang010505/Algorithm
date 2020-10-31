#include <stdio.h>
long long int d[200][15], cnt=0, n;;

int f(int i){
	if(i>n) return 0;
	for(int j=0;j<=9;j++){
		if(j==0) d[i][j]=d[i-1][1]%1000000000;
		else if(j==9) d[i][j]=d[i-1][8]%1000000000;
		else d[i][j]=(d[i-1][j-1]+d[i-1][j+1])%1000000000;
	}
	f(i+1);
}
int main(){
	scanf("%lld", &n);
	d[1][0]=0;
	for(int i=1;i<=9;i++) d[1][i]=1;
	f(2);
	for(int j=0;j<=9;j++) cnt+=d[n][j];
	printf("%lld", cnt%1000000000);
}
