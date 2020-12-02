#include <stdio.h>
int n, d[1000001][20], res=0;
int main(){
	scanf("%d", &n);
	d[0][0]=1;
	d[1][0]=1;
	for(int i=2;i<=n;i++){
		int k=0, j=1;
		while(i>=j){
			for(int l=0;l<=k;l++) d[i][k]=(d[i][k]+d[i-j][l])%1000000000;
			k++;
			j*=2;
		}
	}
	for(int i=0;i<20;i++) res=(res+d[n][i])%1000000000;
	printf("%d", res);
}
