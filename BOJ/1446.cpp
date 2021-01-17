#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P> > q;

int main(){
	int n, m, d[13][3];
	cin >> n >> m;
	
	for(int i=0;i<n;i++)
		cin >> d[i][0] >> d[i][1] >> d[i][2];
	d[n][0]=d[n][1]=m;
	d[n][2]=0;
	q.push({0, 0});
	while(!q.empty()){
		P c=q.top();
		q.pop();
		if(c.second==m){
			cout << c.first;
			break;
		}
		for(int i=0;i<=n;i++)
			if(d[i][0]>=c.second)
				q.push({d[i][2]+d[i][0]-c.second+c.first, d[i][1]});
	}
}
