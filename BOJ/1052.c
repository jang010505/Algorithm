#include <stdio.h>
#include <math.h>

int main(){
	int n, k, cnt=0, z=1, d[100], res=0;
	scanf("%d %d", &n, &k);
	for(int i=30;n!=0 && i>=0;i--){
		int x=pow(2, i);
		if(n-x>=0){
			d[cnt++]=x;
			n-=x;
		}
	}
	while(cnt>k){
		if(d[cnt-2]==d[cnt-1]){
			d[cnt-2]+=d[cnt-1];
			cnt--;
		}
		else{
			res+=d[cnt-1];
			d[cnt-1]+=d[cnt-1];
		}
	}
	printf("%d", res);
	return 0;
}
