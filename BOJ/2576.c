#include <stdio.h>

int main(){
	int a, sum=0, min=100;
	for(int i=0;i<7;i++){
		scanf("%d", &a);
		if(a%2){
			sum+=a;
			if(min>a) min=a;
		}
	}
    if(sum==0) printf("-1");
	else printf("%d\n%d", sum, min);
}
