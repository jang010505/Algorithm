#include <stdio.h>
int min(int a, int b){
	if(a>b) return b;
	return a;
}
int main(){
	int n, d[1001][3], x[1001][3];
	scanf("%d", &n);
	for(int i=0;i<n;i++) 
		scanf("%d %d %d", &d[i][0], &d[i][1], &d[i][2]);
	x[0][0]=d[0][0];
	x[0][1]=d[0][1];
	x[0][2]=d[0][2];
	for(int i=1;i<n;i++){
		x[i][0]=min(x[i-1][1], x[i-1][2])+d[i][0];
		x[i][1]=min(x[i-1][0], x[i-1][2])+d[i][1];
		x[i][2]=min(x[i-1][0], x[i-1][1])+d[i][2];
	}
	int res=2100000000;
   for(int i=0;i<3;i++)
      if(x[n-1][i]<res)
			res=x[n-1][i];
	printf("%d", res);
   return 0;
}
