#include <stdio.h>
#include<stdlib.h>
int n, m, a[8], b[8];
int f(int x){
	if(x==m){
		for(int i=0;i<m-1;i++){
			if(a[i]>=a[i+1]) return 0;
		}
		for(int i=0;i<m;i++) printf("%d ", a[i]);
		printf("\n");
	}
	else{
		for(int i=0;i<n;i++){
			if(b[i]==0){
				b[i]=1;
				a[x]=i+1;
				f(x+1);
				b[i]=0;
			}
		}
	}
}
int main(){
	scanf("%d %d", &n, &m);
	f(0);
}
