#include <stdio.h>

int main(){
	int n, m;
	char s[501][501];
	scanf("%d %d\n", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", s[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='W'){
				if(i>0 && s[i-1][j]=='S'){
					printf("0");
					return 0;
				}
				if(j>0 && s[i][j-1]=='S'){
					printf("0");
					return 0;
				}
				if(i+1<n && s[i+1][j]=='S'){
					printf("0");
					return 0;
				}
				if(j+1<m && s[i][j+1]=='S'){
					printf("0");
					return 0;
				}
			}
			else if(s[i][j]=='.') s[i][j]='D';
		}
	}
	printf("1\n");
	for(int i=0;i<n;i++)
		printf("%s\n", s[i]);
}
