#include <stdio.h>
char s[1000001];
int main(){
	int res=0, d[26]={3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
	scanf("%s", s);
	for(int i=0;s[i]!='\0';i++){
		res+=d[s[i]-65];
	}
	printf("%s", (res%10)%2==0 ? "You're the winner?":"I'm a winner!");
}
