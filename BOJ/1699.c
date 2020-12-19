#include <stdio.h>
int d[100001], n;
int f(int i){
	for(int j=1;j*j<=i;j++){
		int res=0;
		if(j*j==i) res=1;
		else res=d[j*j]+d[i-j*j];
		if(res<d[i] && res!=0) d[i]=res;
	}
	if(i==n) return 0;
	f(i+1);
}
int main(){
	scanf("%d", &n);
	d[0]=0;
	d[1]=1;
	for(int i=2;i<100001;i++)
		d[i]=5;
	if(n>1) f(2);
	printf("%d", d[n]);
}
