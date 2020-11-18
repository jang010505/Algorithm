#include <stdio.h>
#include <string.h>

int main(){
	int n;
	char s[51], res[51];
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", s);
		if(!i) strcpy(res, s);
		else{
			for(int j=0;j<strlen(s);j++){
				if(res[j]!=s[j]){
					res[j]='?';
				}
			}
		}
	}
	printf("%s", res);
}
