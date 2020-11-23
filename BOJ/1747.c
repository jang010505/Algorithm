#include <stdio.h>
#include <stdlib.h>

int d[2000001]={};
int f(int x){
	char z[100];
	int i=0;
	while(x!=0){
		z[i]=x%10;
		x/=10;
		i++;
	}
	for(int j=0;j<i/2;j++){
		if(z[j]!=z[i-j-1]) return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d", &n);
	d[0]=1, d[1]=1;
	for(int i=2;i*i<=2000000;i++){
		if(d[i]) continue;
		for(int j=i;j*i<=2000000;j++) d[i*j]=1;
	}
	for(int i=2;i<=2000000;i++){
		if(!d[i]){
			if(!f(i)) d[i]=1;
		}
	}
	for(int i=n;;i++){
		if(!d[i]){
			printf("%d", i);
			return 0;
		}
	}
} 
