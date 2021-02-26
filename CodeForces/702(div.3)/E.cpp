#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int check(vector<ll> d1, int now){
	ll tmp=d1[now];
	for(int i=0;i<d1.size();i++){
		if(i==now)
			continue;
		if(tmp<d1[i])
			return 0;
		tmp+=d1[i];
	}
	return 1;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		vector<ll> d1;
		vector<ll> d2;
		vector<int> answer;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			ll x;
			scanf("%lld", &x);
			d1.push_back(x);
			d2.push_back(x);
		}
		sort(d1.begin(), d1.end());
		int left=-1;
		int right=n-1;
		while(left+1<right){
			int mid=(left+right)/2;
			if(check(d1, mid))
				right=mid;
			else
				left=mid;
		}
		for(int i=0;i<n;i++)
			if(d1[right]<=d2[i])
				answer.push_back(i+1);
		printf("%d\n", answer.size());
		for(int i=0;i<answer.size();i++)
			printf("%d ", answer[i]);
		printf("\n");
	}
}
