#include <stdio.h>
#include <stdlib.h>
int n, a[20][20], b[20]={}, min=2100000000;
int f(int z, int x){
	if(x==n/2){
		int res1=0, res2=0, o[10]={}, p[10]={}, k=0, l=0;
		for(int i=0;i<n;i++){
			if(b[i]==1) o[k++]=i;
			if(b[i]==0) p[l++]=i;
		}
		for(int i=0;i<n/2-1;i++){
			for(int j=i+1;j<n/2;j++){
				res1+=a[o[i]][o[j]]+a[o[j]][o[i]];
				res2+=a[p[i]][p[j]]+a[p[j]][p[i]];
			}
		}
		if(min>abs(res1-res2)) min=abs(res1-res2);
	}
	for(int i=z;i<n;i++){
		if(b[i]==0){
			b[i]=1;
			f(i, x+1);
			b[i]=0;
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	f(0, 0);
	printf("%d", min);
}
