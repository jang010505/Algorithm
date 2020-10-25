#include <stdio.h>
#include <string.h>

int main(){
	long long int n, res1=0, res2=0, i, a[100005];
	scanf("%lld", &n);
	for(i=0;i<n;i++){
		scanf("%lld", &a[i]);
		res1+=a[i];
	}
	for(i=0;i<n;i++){
		res1-=a[i];
		res2+=res1*a[i];
	}
	printf("%lld", res2);
}
