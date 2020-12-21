#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n, x=0;
	cin >> n;
	vector<pair<int, int> > v(n);
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first;
		v[i].second=i;
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++){
		int tmp=x, index=v[i].second;
		ans[index]=tmp;
		x++;
		while(i<n && v[i].first==v[i+1].first){
         ++i;
         index=v[i].second;
         ans[index]=tmp;
      }
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << ' ';
}
