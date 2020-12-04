#include <stdio.h>

int main(){
	int a, b, d[100001]={1, 1, }, result=0;
	for(int i=2;i*i<=100000;i++){
		if(d[i]) continue;
		for(int j=2;j*i<=100000;j++) d[i*j]=1;
	}
	scanf("%d %d", &a, &b);
	for(int i=a;i<=b;i++){
		if(!d[i]) continue;
		int count=0, n=i, j=2;
		while(n!=1){
			if(d[j]){
				j++;
				continue;
			}
			if(n%j) j++;
			else{
				n/=j;
				count++;
			}
		}
		if(!d[count]) result++;
	}
	printf("%d", result);
}
