#include <stdio.h>
#include <math.h>
int d[1000000]={1, 1, };
int main(){
	int n, cnt=0;
	scanf("%d", &n);
	for(int i=2;i*i<=1000000;i++){
		if(!d[i]){
			for(int j=i;j*i<=1000000;j++){
				d[i*j]=1;
			}
		}
	}
	for(int i=1;i<=1000000;i++){
		if(!d[i]){
			cnt++;
			if(cnt==n){
				printf("%d", i);
				return 0;
			}
		}
	}
}
