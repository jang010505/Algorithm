#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

struct node{
	int from, to;
	ll dist;
};
struct cmp{
	bool operator()(node& a, node& b){
		return a.dist>b.dist;
	}
};

int x[2001], y[2001], parent[2001];

int find(int num){
	if(parent[num]==num) return num;
	return parent[num]=find(parent[num]);
}

void Union(int num1, int num2){
	int a=find(num1);
	int b=find(num2);
	if(a!=b) parent[b]=a;
}

int parentFind(int num1, int num2){
	int a=find(num1);
	int b=find(num2);
	if(a!=b)
		return 0;
	else
		return 1;
}

int main(){
	int n, k, count=0;
	ll answer=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
		parent[i]=i;
	}
	priority_queue<node, vector<node>, cmp> q;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ll dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			node tmp;
			tmp.from=i;
			tmp.to=j;
			tmp.dist=dist;
			if(dist>=k) q.push(tmp);
		}
	}
	while(!q.empty()){
		int i=q.top().from;
		int j=q.top().to;
		ll dist=q.top().dist;
		q.pop();
		if(!parentFind(i, j)){
			Union(i, j);
			answer+=dist;
			count++;
		}
	}
	if(count!=n-1) answer=-1;
	cout << answer;
	return 0;
}
