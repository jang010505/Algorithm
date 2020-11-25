#include <stdio.h>

int main(){
	int n, m, min, j=0, k=0, max=0;
	char d[100][100];
	scanf("%d %d\n", &n, &m);
	for(int i=0;i<n;i++) scanf("%s", d[i]);
	if(n<m) min=n;
	else min=m;
	for(int i=0;i<min;i++){
		for(j=0;j<n;j++){
			for(k=0;k<m;k++){
				if(j+i>=n || k+i>=m) continue;
				if(d[j][k]==d[j][k+i] && d[j][k]==d[j+i][k] && d[j][k]==d[j+i][k+i]){
					if(max<(i+1)*(i+1)) max=(i+1)*(i+1);
				}
			}
		}
	}
	printf("%d", max);
}
