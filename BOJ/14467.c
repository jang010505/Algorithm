#include <stdio.h>
#include <string.h>

int main(){
	int n, a[15], b[15]={}, i, x, y, cnt=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &x, &y);
		if(b[x]==0){
			b[x]=1;
			a[x]=y;
		}
		else{
			if(a[x]!=y){
				cnt++;
				a[x]=y;
			}
		}
	}
	printf("%d", cnt);
}
