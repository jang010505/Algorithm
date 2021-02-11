#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
	return (p2.first-p1.first)*(p3.second-p1.second)-(p2.second-p1.second)*(p3.first-p1.first);	
}
int main(){
	int n;
	pair<ll, ll> p[10000];
	ll answer=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld %lld", &p[i].first, &p[i].second);
	for(int i=1;i<n-1;i++)
		answer+=CCW(p[0], p[i], p[i+1]);
	if(answer<0)
		answer*=-1;
	printf("%lld", answer/2);
	if(answer%2)
		printf(".5");
	else
		printf(".0");
	return 0;
}
