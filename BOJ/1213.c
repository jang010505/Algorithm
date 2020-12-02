#include <stdio.h>
#include <string.h>

int main(){
	char x[100];
	int d[26]={}, z=1, l, v;
	scanf("%s", x);
	l=strlen(x);
	for(int i=0;i<l;i++) d[x[i]-65]++;
	for(int i=0;i<26;i++){
		if(!z && d[i]%2==1){
			printf("I'm Sorry Hansoo");
			return 0;
		}
		if(d[i]%2==1){
			z=0;
			v=i;
		}
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<d[i]/2;j++){
			printf("%c", i+65);
		}
		d[i]/=2;
	}
	if(!z) printf("%c", v+65);
	for(int i=25;i>=0;i--){
		for(int j=0;j<d[i];j++){
			printf("%c", i+65);
		}
	}
}
