#include <stdio.h>
#include <string.h>

int d[2000000];
int main(){
	int n, cnt1=0, cnt2=0;
	char s[500010];
	scanf("%d\n", &n);
	scanf("%s", s);
	for(int i=0;i<n;i++){
		while(i<n && s[i]==s[i+1]){
			i++;
		}
		if(s[i]=='B') cnt1++;
		else cnt2++;
	}
	printf("%d", cnt1<cnt2 ? cnt1+1:cnt2+1);
}
