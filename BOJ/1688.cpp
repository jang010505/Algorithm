#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
pair<ll, ll> p[10000];

int CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
	ll temp=p1.first*p2.second+p2.first*p3.second+p3.first*p1.second-p1.second*p2.first-p2.second*p3.first-p3.second*p1.first;
	if(temp>0)
		return 1;
	else if(temp==0)
		return 0;
	else
		return -1;
}
int chk(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D){
	int tmp1=CCW(A, B, C)*CCW(A, B, D);
	int tmp2=CCW(C, D, A)*CCW(C, D, B);
	if(tmp1==0 && tmp2==0){
		if(A>B)
			swap(A, B);
		if(C>D)
			swap(C, D);
		return A<=D && C<=B;
	}
	else
		return tmp1<=0 && tmp2<=0;
}
int chkin(ll a, ll b, ll c){
	if(b>c)
		swap(b, c);
	return b<=a && a<=c;
}
int solution(pair<ll, ll> s){
	int cnt=0;
	pair<ll, ll> end;
	end.first=1000000001;
	end.second=s.second+1;
	if(s.first==p[n-1].first && s.second==p[n-1].second)
		return 1;
	if(s.first==p[0].first && s.second==p[0].second)
		return 1;
	if(CCW(s, p[n-1], p[0])==0 && chkin(s.first, p[n-1].first, p[0].first) && chkin(s.second, p[n-1].second, p[0].second))
		return 1;
	if(chk(s, end, p[n-1], p[0]))
		cnt++;
	for(int i=1;i<n;i++){
		if(s.first==p[i-1].first && s.second==p[i-1].second)
			return 1;
		if(s.first==p[i].first && s.second==p[i].second)
			return 1;
		if(CCW(s, p[i-1], p[i])==0 && chkin(s.first, p[i-1].first, p[i].first) && chkin(s.second, p[i-1].second, p[i].second))
			return 1;
		if(chk(s, end, p[i-1], p[i]))
			cnt++;
	}
	if(cnt%2==0)
		return 0;
	else
		return 1;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld %lld", &p[i].first, &p[i].second);
	for(int i=0;i<3;i++){
		pair<ll, ll> s;
		scanf("%lld %lld", &s.first, &s.second);
		printf("%d\n", solution(s));
	}
	return 0;
}
