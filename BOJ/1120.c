#include <stdio.h>
#include <string.h>

int main(){
	char x[100], y[100];
	scanf("%s %s", x, y);
	int lx=strlen(x), ly=strlen(y), min=50;
	for(int i=0;i<=ly-lx;i++){
		int cnt=0;
		for(int j=0;j<lx;j++){
			if(x[j]!=y[i+j]) cnt++;
		}
		if(cnt<min) min=cnt;
	}
	printf("%d", min);
}
