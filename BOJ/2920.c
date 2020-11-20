#include <stdio.h>

int main(){
	int d[8]={}, z=1;
    for(int i=0;i<8;i++) scanf("%d", &d[i]);
    if(d[0]==8){
    	for(int i=0;i<7;i++) if(d[i]!=d[i+1]+1) z=0;
		if(z) printf("descending");
		else printf("mixed");
	}
	else if(d[0]==1){
		for(int i=0;i<7;i++) if(d[i]!=d[i+1]-1) z=0;
		if(z) printf("ascending");
		else printf("mixed");
	}
	else printf("mixed");
}
