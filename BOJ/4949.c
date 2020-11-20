#include <stdio.h>
#include <string.h>

int main(){
	int z;
	char s[1000], d[1000];
	while(1){
		z=1;
		gets(s);
		memset(d, '\0', sizeof(char));
		int l=strlen(s), cnt=0, scnt1=0, scnt2=0, bcnt1=0, bcnt2=0;
		if(s[0]=='.' && l==1) return 0;
		for(int i=0;i<l;i++){
			if(s[i]=='('){
				d[cnt++]='(';
				scnt1++;
			}
			if(s[i]=='['){
				d[cnt++]='[';
				bcnt1++;
			}
			if(s[i]==')'){
				if(d[--cnt]!='(') z=0;
				scnt2++;
			}
			if(s[i]==']'){
				if(d[--cnt]!='[') z=0;
				bcnt2++;
			}
			if(scnt1<scnt2 || bcnt1<bcnt2) z=0;
		}
		if(scnt1 != scnt2 || bcnt1 !=bcnt2) z=0;
		if(z) printf("yes\n");
		else printf("no\n");
	}
}
