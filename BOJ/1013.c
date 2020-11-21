#include <stdio.h>
#include <string.h>

int main(){
	int n, z;
	char x[1000];
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		gets(x);
		z=1;
		for(int j=0;j<strlen(x);){
			if(x[j]=='0'){
				if(x[j+1]!='1'){
					z=0;
					break;
				}
				j+=2;
			}
			else if(x[j]=='1'){
				int cnt=0;
				while(x[j+1]=='0' && j+1<strlen(x)){
					j++;
					cnt++;
				}
				if(cnt<2){
					z=0;
					break;
				}
				cnt=0;
				while(x[j+1]=='1' && j+1<strlen(x)){
					j++;
					cnt++;
				}
				if(cnt>1 && j+2<strlen(x) && x[j+1]=='0' && x[j+2]=='0'){
					continue;
				} 
				else{
					j++;
				}
			}
		}
		if(x[strlen(x)-1]=='0') z=0;
		if(z) printf("YES\n");
		else printf("NO\n");
	}
}
