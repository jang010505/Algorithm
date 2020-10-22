#include <stdio.h>
char d[1000];
int main(){
	while(1){
		scanf("%s", d);
		if(d[0]=='0') break;
		int res=0;
		for(int i=0;d[i]!='\0';i++){
			res+=d[i]-48;
		}
		int res1=0;
		while(res>=10){
			while(res!=0){
				res1+=res%10;
				res/=10;
			}
			res=res1;
			res1=0;
		}
		printf("%d\n", res);
	}
}
