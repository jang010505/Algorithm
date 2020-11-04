#include <stdio.h>

int main(){
	int n, cnt=0;
	scanf("%d", &n);
	if(n==1 || n==3){
		printf("-1");
		return 0;
	}
	if(n>=5){
		cnt+=n/5;
		n%=5;
	}
	if(n%2 && n!=0){
		cnt--;
		n+=5;
	}
	cnt+=n/2;
	printf("%d", cnt);
}
