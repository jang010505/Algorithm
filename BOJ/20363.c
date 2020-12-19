#include <stdio.h>
#include <string.h>

int d[200001];
int main(){
	int x, y, res=0, a, b;
	scanf("%d %d", &x, &y);
	while(x!=0 || y!=0){
		if(x<y){
			int tmp=y;
			y=x;
			x=tmp;
		}		
		res+=x;
		x-=x;
		res+=y;
		x+=y/10;
		y-=y;
	}
	printf("%d", res);
}
