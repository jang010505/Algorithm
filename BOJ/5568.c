#include <stdio.h>
int n, k, d[10]={}, cnt=0, dd[10000]={}, chk[10]={}, l=0;
int f(int i, int res){
	if(i==k){
		for(int j=0;j<l;j++){
			if(res==dd[j]) return 0; 
		}
		dd[l++]=res;
		return 0;
	}
	for(int j=0;j<n;j++){
		if(chk[j]!=1){
			chk[j]=1;
			if(d[j]>=10) f(i+1, res*100+d[j]);
			else f(i+1, res*10+d[j]);
			chk[j]=0;
		}
	}
	return 0;
}
int main(){
	scanf("%d", &n);
	scanf("%d", &k);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	f(0, 0);
	printf("%d", l);
}
