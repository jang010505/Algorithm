#include <stdio.h>

int main(){
	int n;
	double d[10000];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lf", &d[i]);
	double ans=d[0];
	for(int i=1;i<n;i++){
		if(d[i]<=d[i]*d[i-1]) d[i]=d[i]*d[i-1];
		if(ans<d[i]) ans=d[i];
	}
	printf("%.3lf", ans);
}
