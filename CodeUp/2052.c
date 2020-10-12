#include <stdio.h>

int main(){
	int x, i, j;
	for(i=0;i<5;i++){
		scanf("%d", &x);
		int res=1;
		for(j=2;j*j<=x;j++){
			if(x%j==0){
				res+=j;
				if(x/j!=j) res+=x/j;
			}
		}
		if(res==x) printf("yes\n");
		else printf("no\n");
	}
}
