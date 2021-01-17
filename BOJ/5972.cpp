#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int answer[50001];
vector<P> vec[50001];

void dijkstra(int start){
	answer[start]=0;
	priority_queue<P, vector<P>, greater<P> > q;
	q.push({answer[start], start});
	while(!q.empty()){
		int distance=q.top().first;
		int now=q.top().second;
		q.pop();
		if(answer[now]<distance) continue;
		for(int i=0;i<vec[now].size();i++){
			int next=vec[now][i].first;
			int nextDistance=distance+vec[now][i].second;
			if(nextDistance<answer[next]){
				answer[next]=nextDistance;
				q.push({nextDistance, next});
			}
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		answer[i]=987654321;
	for(int i=0;i<m;i++){
		int s, e, v;
		cin >> s >> e >> v;
		vec[s].push_back({e, v});
		vec[e].push_back({s, v});
	}
	dijkstra(1);
	cout << answer[n];
}
