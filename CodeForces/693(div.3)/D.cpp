#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
int cmp(ll a, ll b){
	return a>b;
}
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		ll n, d[200001], sum1=0, sum2=0;
		scanf("%lld", &n);
		for(int i=0;i<n;i++)
			scanf("%lld", &d[i]);
		sort(d, d+n, cmp);
		for(int i=0;i<n;i++){
			if(i%2 && d[i]%2)
				sum2+=d[i];
			else if(i%2==0 && d[i]%2==0)
				sum1+=d[i];
		}
		if(sum1==sum2)
			printf("Tie\n");
		else if(sum1<sum2)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
}
