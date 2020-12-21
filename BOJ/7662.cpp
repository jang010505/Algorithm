#include<iostream>
#include<set>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		multiset<int> d;
		int n;
		cin >> n;
		for (int j=0;j<n;j++) {
			char a;
			int x;
			cin >> a >> x;
			if(a=='I') d.insert(x);
			else{
				if(d.empty()) continue;
				if(x==1){
					auto iter=d.end();
					iter--;
					d.erase(iter);
				}
				else{
					auto iter=d.begin();
					d.erase(iter);
				}
			}
		}
		if(d.empty()) cout << "EMPTY" << "\n";
		else{
			auto end=d.end();
			end--;
			cout << *end << " " << *d.begin() << "\n";
		}
	}
	return 0;
}
