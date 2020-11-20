#include <stdio.h>
#include <string.h>

int main(){
	int n, d[100000], a, l=0, res=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		if(a) d[l++]=a;
		else d[l--]=0;
	}
	for(int i=0;i<l;i++) res+=d[i];
	printf("%d", res);
}
