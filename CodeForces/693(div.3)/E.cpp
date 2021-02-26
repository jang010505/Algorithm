#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int cmp(pair<pair<int, int> ,int> a, pair<pair<int, int> ,int> b){
	if(a.first.first<b.first.first)
		return 1;
	else if(a.first.first==b.first.first){
		if(a.first.second>b.first.second)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, answer[200000];
		scanf("%d", &n);
		vector<pair<pair<int, int> ,int> > d(n);
		for(int i=0;i<n;i++){
			int w, h;
			scanf("%d %d", &w, &h);
			d[i].first.first=min(w, h);
			d[i].first.second=max(w, h);
			d[i].second=i;
			answer[i]=-1;
		}
		sort(d.begin(), d.end(), cmp);
		int min_w=d[0].first.first, min_h=d[0].first.second, min_idx=d[0].second;
		for(int i=1;i<n;i++){
			if(d[i].first.first>min_w && d[i].first.second>min_h)
				answer[d[i].second]=min_idx+1;
			else{
				min_w=d[i].first.first;
				min_h=d[i].first.second;
				min_idx=d[i].second;
			}
		}
		for(int i=0;i<n;i++)
			printf("%d ", answer[i]);
		printf("\n");
	}
}
