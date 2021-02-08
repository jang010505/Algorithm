#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll temp=p1.first*p2.second+p2.first*p3.second+p3.first*p1.second-p1.second*p2.first-p2.second*p3.first-p3.second*p1.first;
	if(temp>0)
		return 1;
	else if(temp==0)
		return 0;
	else
		return -1;
}

int solution(pair <ll, ll> A, pair <ll, ll> B, pair <ll, ll> C, pair <ll, ll> D){
	int tmp1=CCW(A, B, C)*CCW(A, B, D);
	int tmp2=CCW(C, D, A)*CCW(C, D, B);
	if(tmp1==0 && tmp2==0){
		if(A>B)
			swap(A, B);
		if(C>D)
			swap(C, D);
		if(A<=D && C<=B)
			return 1;
		else
			return 0;
	}
	if(tmp1<=0 && tmp2<=0)
		return 1;
	else
		return 0;
}

int main(){
	pair<ll, ll> p[4];
	for(int i=0;i<4;i++)
		scanf("%lld %lld", &p[i].first, &p[i].second);
	printf("%d", solution(p[0], p[1], p[2], p[3]));
	return 0;
}
