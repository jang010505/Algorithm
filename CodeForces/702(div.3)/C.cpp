#include <cstdio>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
set<ll> s;
 
int main(){
	int T;
	scanf("%d", &T);
	for(ll i=1;i*i*i<=1000000000000;i++)
		s.insert(i*i*i);
	while(T--){
		ll x;
		int chk=0;
		scanf("%lld", &x);
		for(ll i=1;i*i*i<=x;i++){
			if(s.count(x-i*i*i)){
				chk=1;
				break;
			}
		}
		if(chk)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
