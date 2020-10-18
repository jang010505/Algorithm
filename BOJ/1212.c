#include <stdio.h>
int f(int x, int i){
	if(i==0 && x!=0){
		f(x/2, i);
		printf("%d", x%2);
	}
	else if(x>=4){
		f(x, 0);
	}
	else if(x>=2){
		printf("0");
		f(x, 0);
	}
	else if(x>=1){
		printf("00");
		f(x, 0);
	}
	return 0;
}
int main(){
	char a[333394];
	scanf("%s", a);
	if(a[0]=='0') printf("0");
	else{
		for(int i=0;a[i]!='\0';i++){
			if(a[i]!='0')f(a[i]-48, i);
			else printf("000");
		}
	}
}
