#include <stdio.h>
#include <string.h>
char s[10000];
int l;
int f(int j){
	for(int i=0;i<(l-j)/2;i++){
		if(s[l-1-i]!=s[i+j]) return 0;
	}
	return 1;
}
int main(){
	scanf("%s", s);
	l=strlen(s);
	for(int i=0;i<l;i++){
		if(f(i)){
			printf("%d", l+i);
			return 0;
		}
	}
}
