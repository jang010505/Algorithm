#include <cstdio>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
 
ll g1(ll n){
	ll result=0;
	int d[10]={};
	while(n){
		d[n%10]++;
		n/=10;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<d[i];j++){
			result*=10;
			result+=i;
		}
	}
	return result;
}
ll g2(ll n){
	ll result=0;
	int d[10]={};
	while(n){
		d[n%10]++;
		n/=10;
	}
	for(int i=1;i<10;i++){
		for(int j=0;j<d[i];j++){
			result*=10;
			result+=i;
		}
	}
	return result;
}
ll f(int n){
	return g1(n)-g2(n);
}
 
int main(){
	ll n, k;
	scanf("%lld %lld", &n, &k);
	ll tmp=n;
	for(int i=0;i<k;i++){
		tmp=f(tmp);
	}
	printf("%lld", tmp);
}
