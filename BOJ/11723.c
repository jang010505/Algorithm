#include <stdio.h>
#include <string.h>

int main(){
	int n, d[100]={};
	char x[100];
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		gets(x);
		if(x[0]=='a' && x[1]=='d') d[x[4]-48]=1;
		if(x[0]=='r') d[x[7]-48]=0;
		if(x[0]=='c') printf("%d\n", d[x[6]-48]);
		if(x[0]=='t'){
			if(d[x[7]-48]) d[x[7]-48]=0;
			else d[x[7]-48]=1;
		}
		if(x[0]=='a' && x[1]=='l'){
			for(int j=1;j<=20;j++){
				d[j]=1;
			}
		}
		if(x[0]=='e'){
			for(int j=1;j<=20;j++){
				d[j]=0;
			}
		}
	}
}
