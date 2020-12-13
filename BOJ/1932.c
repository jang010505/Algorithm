#include <stdio.h>
int max(int a, int b){
	if(a<b) return b;
	return a;
}
int main(){
	int n, d[501][501];
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			scanf("%d", &d[i][j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j==0) d[i][j]+=d[i-1][j];
			else if(j==i) d[i][j]+=d[i-1][j-1];
			else d[i][j]=max(d[i][j]+d[i-1][j-1], d[i][j]+d[i-1][j]);
		}
	}
	int res=0;
	for(int i=0;i<n;i++){
		if(d[n-1][i]>res){
			res=d[n-1][i];
		}
	}
	printf("%d", res);
   return 0;
}
