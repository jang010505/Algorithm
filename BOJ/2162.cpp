#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int parent[3000];

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
int find(int num){
	if(parent[num]==num)
		return num;
	return parent[num]=find(parent[num]);
}
int Union(int num1, int num2){
	num1=find(num1);
	num2=find(num2);
	if(num1!=num2){
		parent[num1]=num2;
		return 0;
	}
	else{
		return 1;
	}
}
int main(){
	int n, visit[3000]={}, group_count=0, max_count=0;
	for(int i=0;i<3000;i++)
		parent[i]=i;
	pair<ll, ll> p[3000][2];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld %lld %lld %lld", &p[i][0].first, &p[i][0].second, &p[i][1].first, &p[i][1].second);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			if(solution(p[i][0], p[i][1], p[j][0], p[j][1]))
				Union(i, j);
		}
	}
	for(int i=0;i<n;i++)
		visit[find(i)]++;
	for(int i=0;i<n;i++){
		if(visit[i]>0)
			group_count++;
		max_count=max(max_count, visit[i]);
	}
	printf("%d\n%d", group_count, max_count);
	return 0;
}
