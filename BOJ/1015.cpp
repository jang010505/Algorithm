#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> x;

int main(){
	int n, y, z[100];
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &y);
		x.push_back(make_pair(y, i));
	}
	sort(x.begin(), x.end());
	for(int i=0;i<n;i++) z[x[i].second]=i;
	for(int i=0;i<n;i++) printf("%d ", z[i]);
} 
