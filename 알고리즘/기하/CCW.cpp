#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
	ll temp=p1.first*p2.second+p2.first*p3.second+p3.first*p1.second-p1.second*p2.first-p2.second*p3.first-p3.second*p1.first;
	if(temp>0)
		return 1;
	else if(temp==0)
		return 0;
	else
		return -1;
}
int main(){
	pair<ll, ll> p[3];
	for(int i=0;i<3;i++)
		scanf("%lld %lld", &p[i].first, &p[i].second);
	printf("%d", CCW(p[0], p[1], p[2]));
	return 0;
}
