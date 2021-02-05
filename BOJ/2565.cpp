#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, dp[100]={}, answer=0;
	scanf("%d", &n);
	vector <pair<int, int> > v(n);
	for(int i=0;i<n;i++)
		scanf("%d %d", &v[i].first, &v[i].second);
	sort(v.begin(), v.end());
	for(int i=1;i<n;i++){
		int tmp_a=v[i].first;
		int tmp_b=v[i].second;
		for(int j=0;j<i;j++){
			if(tmp_a>v[j].first && tmp_b>v[j].second)
				dp[i]=max(dp[i], dp[j]+1); 
		}
		answer=max(answer, dp[i]);
	}
	printf("%d", n-answer-1);
    return 0;
}
