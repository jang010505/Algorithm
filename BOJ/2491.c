#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int main(){
	int n, d[100000], max=1, l=1;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	for(int i=1;i<n;i++){
		if(d[i]<=d[i-1]) l++;
		else l=1;
		max=MAX(max, l);
	}
	l=1;
	for(int i=1;i<n;i++){
		if(d[i]>=d[i-1]) l++;
		else l=1;
		max=MAX(max, l);
	}
	printf("%d", max);
}
