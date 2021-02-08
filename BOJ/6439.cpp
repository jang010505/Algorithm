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
int chk(pair<ll, ll> A,  pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D){
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
int solution(pair<ll, ll> l1, pair<ll, ll> l2, pair<ll, ll> s1, pair<ll, ll> s2, pair<ll, ll> s3, pair<ll, ll> s4){
	if(chk(l1, l2, s1, s2) || chk(l1, l2, s3, s4) || chk(l1, l2, s1, s3) || chk(l1, l2, s2, s4))
		return 1;
	else{
		if(s3.first<=l1.first && l1.first<=s2.first && s3.first<=l2.first && l2.first<=s2.first)
			if(s3.second<=l1.second && l1.second<=s2.second && s3.second<=l2.second && l2.second<=s2.second)
				return 1;
		return 0;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		pair<ll, ll> l1;
		pair<ll, ll> l2;
		pair<ll, ll> s1;
		pair<ll, ll> s2;
		scanf("%lld %lld", &l1.first, &l1.second);
		scanf("%lld %lld", &l2.first, &l2.second);
		scanf("%lld %lld", &s1.first, &s1.second);
		scanf("%lld %lld", &s2.first, &s2.second);
		if(s1.first>s2.first){
			if(s1.second>s2.second)
				swap(s1, s2);
			else{
				int tmp=s1.first;
				s1.first=s2.first;
				s2.first=tmp;
			}
		}
		else{
			if(s1.second>s2.second){
				int tmp=s1.second;
				s1.second=s2.second;
				s2.second=tmp;
			}
		}
		pair<ll, ll> p[4];
		p[0].first=s1.first;
		p[0].second=s2.second;
		p[1]=s2;
		p[2]=s1;
		p[3].first=s2.first;
		p[3].second=s1.second;
		if(solution(l1, l2, p[0], p[1], p[2], p[3]))
			printf("T\n");
		else
			printf("F\n");
	}
	return 0;
}
