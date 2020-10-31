#include <stdio.h>

int main(){
	char a[10];
	scanf("%s", a);
	if(a[0]==a[1] && a[1]==a[2] && a[2]=='5') printf("YES");
	else printf("NO");
}
