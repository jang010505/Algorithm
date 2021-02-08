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
int chk2(ll p1, ll p2, ll p3, ll p4){
	if(p1>p2){
		ll tmp=p1;
		p1=p2;
		p2=tmp;
	}
	if(p1<p3 && p2<=p3)
		return 0;
	if(p4<=p1 && p4<p2)
		return 0;
	return 1;
}
int solution(pair<ll, ll> l1, pair<ll, ll> l2, pair<ll, ll> s1, pair<ll, ll> s2, pair<ll, ll> s3, pair<ll, ll> s4){
	int tmp1, tmp2, tmp3, tmp4, count=0;
	if(l1.first==l2.first && chk2(l1.second, l2.second, s3.second, s2.second) && (l1.first==s2.first || l1.first==s3.first))
		return 4;
	if(l1.second==l2.second && chk2(l1.first, l2.first, s3.first, s2.first) && (l1.second==s2.second || l1.second==s3.second))
		return 4;
	tmp1=chk(l1, l2, s1, s2);
	if(tmp1)
		count++;
	tmp2=chk(l1, l2, s1, s3);
	if(tmp2)
		count++;
	tmp3=chk(l1, l2, s2, s4);
	if(tmp3)
		count++;
	tmp4=chk(l1, l2, s3, s4);
	if(tmp4)
		count++;
	if(tmp1 && tmp2)
		if(CCW(l1, l2, s1)==0)
			count--;
	if(tmp1 && tmp3)
		if(CCW(l1, l2, s2)==0)
			count--;
	if(tmp2 && tmp4)
		if(CCW(l1, l2, s3)==0)
			count--;
	if(tmp3 && tmp4)
		if(CCW(l1, l2, s4)==0)
			count--;
	return count;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		pair<ll, ll> l1;
		pair<ll, ll> l2;
		pair<ll, ll> s1;
		pair<ll, ll> s2;
		scanf("%lld %lld", &s1.first, &s1.second);
		scanf("%lld %lld", &s2.first, &s2.second);
		scanf("%lld %lld", &l1.first, &l1.second);
		scanf("%lld %lld", &l2.first, &l2.second);
		pair<ll, ll> p[4];
		p[0].first=s1.first;
		p[0].second=s2.second;
		p[1]=s2;
		p[2]=s1;
		p[3].first=s2.first;
		p[3].second=s1.second;
		printf("%d\n", solution(l1, l2, p[0], p[1], p[2], p[3]));
	}
	return 0;
}
