#include <stdio.h>
#include <math.h>
int d[4000001]={}, x, cnt=0;
int f(int n){
	while(n){
		if(n%10==x) return 1;
		n/=10;
	}
	return 0;
}
int main(){
	int a, b;
	scanf("%d %d %d", &a, &b, &x);
	d[0]=1, d[1]=1;
	for(int i=2;i*i<=b;i++){
		if(!d[i]){
			for(int j=i;i*j<=b;j++){
				d[i*j]=1;
			}
		}
	}
	for(int i=a;i<=b;i++){
		if(!d[i]){
			if(f(i)) cnt++;
		}
	}
	printf("%d", cnt);
}
