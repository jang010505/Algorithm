#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	int n=0;
	while(1){
		gets(s);
		if(strcmp(s, "고무오리 디버깅 시작")==0) continue;
		else if(strcmp(s, "문제")==0) n++;
		else if(strcmp(s, "고무오리")==0){
			if(n==0) n+=2;
			else n--;
		}
		else{
			if(n==0) printf("고무오리야 사랑해");
			else printf("힝구");
			return 0;
		}
	}
}
