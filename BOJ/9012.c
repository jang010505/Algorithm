#include <stdio.h>
#include <string.h>

int main(){
	int z, n;
	char s[1000];
	scanf("%d\n", &n);
	for(int j=0;j<n;j++){
		z=1;
		gets(s);
		int l=strlen(s), scnt1=0, scnt2=0;
		for(int i=0;i<l;i++){
			if(s[i]=='(') scnt1++;
			if(s[i]==')') scnt2++;
			if(scnt1<scnt2) z=0;
		}
		if(scnt1 != scnt2) z=0;
		if(z) printf("YES\n");
		else printf("NO\n");
	}
}
