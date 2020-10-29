#include <stdio.h>

int main(){
	int n, m, k, i, j, d[101][101];
	scanf("%d %d %d", &n, &m, &k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d", &d[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(d[j][i]>=k){
				printf("%d %d", j+1, i+1);
				return 0;
			}
			d[j][i+1]+=d[j][i];
		}
	}
}
