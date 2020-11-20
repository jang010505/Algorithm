#include <stdio.h>
#include <string.h>
int main(){
	while(1){
		char a[10];
		gets(a);
		int l=strlen(a), z=1;
		if(a[0]=='0') return 0;
		if(l==1) printf("yes\n");
		else{
			z=1;
			for(int i=0;i<l/2;i++) if(a[i]!=a[l-i-1]) z=0;
			if(z) printf("yes\n");
			else printf("no\n");
		}
	}
}
