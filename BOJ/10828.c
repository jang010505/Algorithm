#include <stdio.h>

int main(){
	int n, i, a=-1, d[100001]={};
	char s[100];
	scanf("%d\n", &n);
	for(i=0;i<n;i++){
		gets(s);
		if(s[0]=='p' && s[1]=='u'){
			a++;
			int m=0;
			for(int j=5;;j++){
				if(s[j]<48 || s[j]>57) break;
				m=m*10+s[j]-48;
			}
			d[a]=m;
		}
		else if(s[0]=='t'){
			if(a==-1) printf("-1\n");
			else printf("%d\n", d[a]);
		}
		else if(s[0]=='p' && s[1]=='o'){
			if(a!=-1){
				printf("%d\n", d[a]);
				d[a]=0;
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
