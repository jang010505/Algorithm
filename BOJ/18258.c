#include <stdio.h>

int d[2000000];
int makeint(char x[]){
	int res=0, le=5;
	while(x[le]!='\0'){
		res*=10;
		res+=x[le]-48;
		le++;
	}
	return res;
}
int main(){
	int n, len=0, front=0, back=0;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		char x[1000];
		gets(x);
		if(x[0]=='p' && x[1]=='u'){
			d[back++]=makeint(x);
			len++;
		}
		else if(x[0]=='p' && x[1]=='o'){
			printf("%d\n", len==0 ? -1:d[front]);
			if(len>0){
				len--;
				front++;
			}
		}
		else if(x[0]=='s')
			printf("%d\n", len);
		else if(x[0]=='e')
			printf("%d\n", len==0 ? 1:0);
		else if(x[0]=='f')
			printf("%d\n", len==0 ? -1:d[front]);
		else if(x[0]=='b')
			printf("%d\n", len==0 ? -1:d[back-1]);
	}
}
