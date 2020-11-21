#include <iostream>
#include <algorithm>
using namespace std;

string s[100001];
string u[100001];
pair<string, string> t[100001];

bool cmp(pair<string, string>& t1, pair<string, string>& t2) {
	return t1.first < t2.first;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		cin >> s[i] >> u[i];
		t[i].first=s[i];
		t[i].second=u[i];
	}
	sort(t, t+n, cmp);
	for (int i=0;i<m;i++) {
		string q;
		cin >> q;
		int left=0;
		int right=n-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(t[mid].first<q) left=mid+1;
			else if(q<t[mid].first) right=mid-1;
			else{
				cout << t[mid].second << "\n";
				break;
			}
		}
	}
	return 0;
}
