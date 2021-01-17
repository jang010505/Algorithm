#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> P;
int cost[101];
vector<P> vec[101];
void dijkstra(int start, vector<P> vec[101]){
	cost[start]=0;
	priority_queue<P, vector<P>, greater<P> > q;
	q.push({cost[start], start});
	while(!q.empty()){
		int distance=q.top().first;
		int now=q.top().second;
		q.pop();
		if(cost[now]<distance) continue;
		for(int i=0;i<vec[now].size();i++){
			int nextdistance=distance+vec[now][i].second;
			int next=vec[now][i].first;
			if(nextdistance<cost[next]){
				cost[next]=nextdistance;
				q.push({nextdistance, next});
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k, d[101], temp[101], answer=987654321, index=1;
		for(int i=0;i<=n;i++)
			temp[i]=0;
		cin >> n >> m;
		vector<P> vec[101];
		for(int i=0;i<m;i++){
			int s, e, v;
			cin >> s >> e >> v;
			vec[s].push_back({e, v});
			vec[e].push_back({s, v});
		}
		cin >> k;
		for(int i=0;i<k;i++){
			cin >> d[i];
			for(int j=1;j<=n;j++)
				cost[j]=987654321;
			dijkstra(d[i], vec);
			for(int j=1;j<=n;j++)
				temp[j]+=cost[j];
		}
		for(int i=1;i<=n;i++){
			if(answer>temp[i]){
				answer=temp[i];
				index=i;
			}
		}
		cout << index << '\n';
	}
}
