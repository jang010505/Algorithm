#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > v(n);
	for(int i=0;i<n;i++) cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());
	int early=0, res=0;
	for(int i=0;i<n;i++){
      int start=v[i].second, end=v[i].first;
      if(early<=start){
         early=end;
			res++;
      }
	}
	cout << res;
	return 0;
}
