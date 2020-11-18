#include <stdio.h>

int main(){
	int n, d[10000][3]={}, max=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d", &d[i][0], &d[i][1], &d[i][2]);
		if(d[max][0]<d[i][0]) max=i;
		if(d[max][0]==d[i][0] && d[max][1]>d[i][1]) max=i;
		if(d[max][0]==d[i][0] && d[max][1]==d[i][1] && d[max][2]>d[i][2]) max=i;
	}
	printf("%d", max+1);
}
