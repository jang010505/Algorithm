#include <stdio.h>
long long int a[1000005], n, m, i, j, cnt=0, k;

int main(){
	scanf("%lld %lld", &n, &m);
	for(i=2;i*i<=m;i++){
		long long int x=n/(i*i);
		if(n%(i*i)) x++;
		while(x*(i*i)<=m){
			a[x*(i*i)-n]=1;
			x++;
		}
	}
	for(i=0;i<=m-n;i++) if(!a[i]) cnt++;
    printf("%lld", cnt);
}
