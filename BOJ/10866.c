#include <stdio.h>

int main(){
	int n, i, a=-1, d[100001]={};
	char s[100];
	scanf("%d\n", &n);
	for(i=0;i<n;i++){
		gets(s);
		if(s[0]=='p' && s[1]=='u' && s[5]=='f'){
			int m=0;
			for(int j=11;;j++){
				if(s[j]<48 || s[j]>57) break;
				m=m*10+s[j]-48;
			}
			for(int i=a;i>=0;i--) d[i+1]=d[i];
			d[0]=m;
			a++;
		}
		else if(s[0]=='p' && s[1]=='u' && s[5]=='b'){
			a++;
			int m=0;
			for(int j=10;;j++){
				if(s[j]<48 || s[j]>57) break;
				m=m*10+s[j]-48;
			}
			d[a]=m;
		}
		else if(s[0]=='b'){
			if(a==-1) printf("-1\n");
			else printf("%d\n", d[a]);
		}
		else if(s[0]=='f'){
			if(a==-1) printf("-1\n");
			else printf("%d\n", d[0]);
		}
		else if(s[0]=='p' && s[1]=='o' && s[4]=='f'){
			if(a!=-1){
				printf("%d\n", d[0]);
				for(int j=1;j<a+1;j++) d[j-1]=d[j];
				a--;
			}
			else{
				printf("-1\n");
			}
		}
		else if(s[0]=='p' && s[1]=='o' && s[4]=='b'){
			if(a!=-1){
				printf("%d\n", d[a]);
				a--;
			}
			else{
				printf("-1\n");
			}
		}
		else if(s[0]=='s') printf("%d\n", a+1);
		else if(s[0]=='e'){
			if(a==-1) printf("1\n");
			else printf("0\n");
		}
	}
}
