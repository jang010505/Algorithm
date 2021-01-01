#include <stdio.h>

int main(){
	int n, d[100000]={0, }, temp=0;
	scanf("%d", &n);
	for(int i=3;i<=80000;i++){
		if(i%3==0 && i%7==0)
			temp+=i;
		else if(i%3==0)
			temp+=i;
		else if(i%7==0)
			temp+=i;
		d[i]=temp;
	}
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		printf("%d\n", d[a]);
	}
}
