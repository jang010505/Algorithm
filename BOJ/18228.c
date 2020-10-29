#include <stdio.h>

int main(){
	int n, i, a, res, min=1000000000;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a);
		if(a==-1){
			res=min;
			min=1000000000;
		}
		else if(min>a) min=a;
	}
	printf("%d", res+min);
}
