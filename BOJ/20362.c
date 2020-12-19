#include <stdio.h>
#include <string.h>

int d[200001];
int main(){
	int n, x, cnt=0;
	char s[100], ans[1001][100], name[1000][100];
	scanf("%d %s", &n, s);
	for(int i=0;i<n;i++){
		scanf("%s %s", name[i], ans[i]);
		if(strcmp(name[i], s)==0){
			x=i;
		}
	}
	for(int i=0;i<x;i++){
		if(strcmp(ans[i], ans[x])==0){
			cnt++;
		}
	}
	printf("%d", cnt);
}
