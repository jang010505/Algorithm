#include <stdio.h>
int cntw=0, cntb=0, n, d[128][128];
int f(int x, int y, int N){
	int cnt1=0;
	for(int i=x;i<x+N;i++){
		for(int j=y;j<y+N;j++){
			if(d[i][j]==1) cnt1++;
		}
	}
	if(cnt1==0){
		cntb++;
		return 0;
	}
	else if(N*N==cnt1){
		cntw++;
		return 0;
	}
	else{
		f(x, y, N/2);
		f(x+N/2, y, N/2);
		f(x, y+N/2, N/2);
		f(x+N/2, y+N/2, N/2);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &d[i][j]);
		}
	}
	f(0, 0, n);
	printf("%d\n%d", cntb, cntw);
}
