#include <iostream>
#include <cmath>
using namespace std;
int d[2200][2200], res[3];
int g(int x1, int y1, int N1){
	int s=d[x1][y1];
	for(int i=x1;i<x1+N1;i++){
		for(int j=y1;j<y1+N1;j++){
			if(s!=d[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
void f(int x, int y, int N){
	if(g(x, y, N)){
		res[d[x][y]]++;
	}
	else{
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				f(x+i*N/3, y+j*N/3, N/3);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int v;
			scanf("%d", &v);
			d[i][j]=v+1;
		}
	}
	f(0, 0, n);
	printf("%d\n%d\n%d", res[0], res[1], res[2]);
}
