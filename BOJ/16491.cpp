#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, visit[11], answer[11], flag=0;
pair<ll, ll> p[11];
pair<ll, ll> s[11];

int CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
	ll temp=p1.first*p2.second+p2.first*p3.second+p3.first*p1.second-p1.second*p2.first-p2.second*p3.first-p3.second*p1.first;
	if(temp>0)
		return 1;
	else if(temp==0)
		return 0;
	else
		return -1;
}

int cross(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D){
	int abc=CCW(A, B, C);
	int abd=CCW(A, B, D);
	int tmp1=abc*abd;
	int acd=CCW(C, D, A);
	int bcd=CCW(C, D, B);
	int tmp2=acd*bcd;
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
	else if(tmp1<=0 && tmp2<=0)
		return 1;
	else
		return 0;
}

int chk(int now){
	for(int i=1;i<=now;i++)
		for(int j=i+1;j<=now;j++)
			if(cross(p[i], s[answer[i]], p[j], s[answer[j]]))
				return 0;
	return 1;
}

void dfs(int now){
	if(chk(now-1)==0)
		return;
	if(now==n+1){
		flag=1;
		for(int i=1;i<=n;i++)
			printf("%d\n", answer[i]);
		return;
	}
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i]=1;
			answer[now]=i;
			dfs(now+1);
			if(flag)
				return;
			visit[i]=0;
		}
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%lld %lld", &p[i].first, &p[i].second);
	for(int i=1;i<=n;i++)
		scanf("%lld %lld", &s[i].first, &s[i].second);
	dfs(1);
	return 0;
}
