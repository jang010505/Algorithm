#include <stdio.h>
#include <math.h>

int main(){
	int h, y, d[100];
	scanf("%d %d", &h, &y);
	d[0]=h;
	for(int i=1;i<=y;i++){
		d[i]=(int)d[i-1]*1.05;
		if(i>=3){
			if(d[i]<(int)d[i-3]*1.2) d[i]=(int)d[i-3]*1.2;
		}
		if(i>=5){
			if(d[i]<(int)d[i-5]*1.35) d[i]=(int)d[i-5]*1.35;
		}
	}
	printf("%d", d[y]);
}
