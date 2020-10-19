#include <stdio.h>
int l, h, d[100][100]={};
int f(int x, int y){
	d[x][y]=0;
	if(d[x][y+1]==1 && y+1<h) f(x, y+1);
	if(d[x][y-1]==1 && y-1>=0) f(x, y-1);
	if(d[x+1][y]==1 && x+1<l) f(x+1, y);
	if(d[x-1][y]==1 && x-1>=0) f(x-1, y);
	return 0;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int k, x, y, cnt=0;
		scanf("%d %d %d", &l, &h, &k);
		for(int j=0;j<k;j++){
			scanf("%d %d", &x, &y);
			d[x][y]=1;
		}
		for(int j=0;j<l;j++){
			for(int v=0;v<h;v++){
				if(d[j][v]){
					f(j, v);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
    return 0;
}
