#include <stdio.h>
#include <string.h>
char s[5000000];
int main(){
	int n, str, cnt=0;
	scanf("%d", &n);
	scanf("%d\n", &str);
	scanf("%s", s);
	for(int i=0;i<str;i++){
		if(s[i]=='I'){
			int cnt1=0;
			while(i+2<str && s[i+1]=='O' && s[i+2]=='I'){
				i+=2;
				cnt1++;
			}
			if(cnt1>=n) cnt+=cnt1-n+1;
		}
	}
	printf("%d", cnt);
}
