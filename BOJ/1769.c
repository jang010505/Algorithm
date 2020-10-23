#include <stdio.h>

int main(){
	char s[1000005];
	int res=0, i, cnt=0;
	scanf("%s", s);
	for(i=0;s[i]!='\0';i++) res+=s[i]-48;
	if(res<10){
		printf("0\n");
		if(res%3) printf("NO");
		else printf("YES");
		return 0;
	}
	cnt++;
	while(res>=10){
		int x=res;
		res=0;
		while(x){
			res+=x%10;
			x/=10;
		}
		cnt++;
	}
	printf("%d\n", cnt);
	if(res%3) printf("NO");
	else printf("YES");
}
