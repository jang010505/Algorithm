#include <stdio.h>
#include <stdlib.h>
int n, cnt=0, max=7500000, a[7500001]={1, 1,};
int f(){
    for(int i=2;i*i<=max;i++){
    	if(a[i]==0){
    		for(int j=i*i;j<=max;j+=i){
    			a[j]=1;
			}
		}
	}
}
int main(){
	scanf("%d", &n);
	f();
    for(int i=2;;i++){
    	if(a[i]==0) cnt++;
    	if(cnt==n){
    		printf("%d", i);
    		return 0;
		}
	}
}
