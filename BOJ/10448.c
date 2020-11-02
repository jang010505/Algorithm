#include <stdio.h>

int main(){
	int n, d[50]={}, a;
	scanf("%d", &n);
	for(int i=0;i<40;i++) d[i]=((i+1)*(i+2))/2;
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		int z=0;
		for(int j=0;j<40;j++){
			for(int k=0;k<=j;k++){
				for(int l=0;l<=k;l++){
					if(d[j]+d[k]+d[l]==a){
						printf("1\n");
						z=1;
						break;
					}
				}
				if(z==1) break;
			}
			if(z==1) break;
		}
		if(!z) printf("0\n");
	}
}
