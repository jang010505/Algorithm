#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	int res=0, sum=0, make=0, chk=1;
	scanf("%s", s);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='-'){
			if(chk) res+=make;
			else res-=sum+make;
			sum=0;
			make=0;
			chk=0;
		}
		else if(s[i]=='+'){
			if(chk) res+=make;
			else sum+=make;
			make=0;
		}
		else{
			make*=10;
			make+=s[i]-48;
		}
	}
	if(chk) res+=sum+make;
	else res-=sum+make;
	printf("%d", res);
}
